#include "synth.hpp"
#include "adsr.hpp"
#include "envelope.hpp"
#include <math.h>
#include <iostream>
#include <stdio.h>
using namespace std;

//#define DEBUG

Synth::Synth():volume_(0.5),polyphony(10),highestNoteIndex(0){
  adsr.setAttack(1000);
  adsr.setDecay(1000);
  adsr.setSustain(0.5);
  adsr.setRelease(1000);

  notes = new Note*[polyphony];
  for(int i=0;i<polyphony;i++)
    notes[i] = new Note(&adsr);
}

void Synth::noteOn(int midinote,int velocity){
  Note* n = NULL;

  //see if the note is already on
  for(int i=0;i<=highestNoteIndex;i++)
    if(notes[i]->midinote == midinote){
      n = notes[i];
      break;
    }

  //otherwise, use an unused note
  if(n == NULL)
    for(int i=0;i<polyphony;i++)
      if(!notes[i]->on){
	n = notes[i];
	n->env.amp = 0;
	if(i > highestNoteIndex)
	  highestNoteIndex = i;
	break;
      }

  //if all the notes are on, snatch one farthest along in its release phase.
  if(n == NULL)
    for(int i=0;i<polyphony;i++)
      if(notes[i]->env.stage == RELEASE)
	if(n == NULL || (n != NULL && notes[i]->env.ramp > n->env.ramp))
	  n = notes[i];

  //if n is still null, then we've reached our polyphony limit, and this note on event is doomed.
  if(n != NULL){
    n->on = true;
    n->midinote = midinote;
    n->freq = note_freqs[midinote];
    n->env.maxAmp = (float)velocity/127.0;

#ifdef DEBUG 
    cout<<"note on: freq = "<<n->freq<<", vel = "<<n->vel<<"\n";flush(cout);
#endif
    n->env.setStage(ATTACK);
  }else{
#ifdef DEBUG 
    cout<<"note lost\n";flush(cout);
#endif
  }
}

void Synth::noteRelease(int midinote){
  for(int i=0;i<=highestNoteIndex;i++)
    if(notes[i]->midinote == midinote){
      notes[i]->env.setStage(RELEASE);
      break;
    }
}

void Synth::noteOff(int midinote){
  for(int i=0;i<=highestNoteIndex;i++)
    if(notes[i]->midinote == midinote){
      notes[i]->on = false;
      if(highestNoteIndex == i)
	for(i--;;i--)
	  if(i == -1 || notes[i]->on){
	    highestNoteIndex = i;
	    break;
	  }
      break;
    }
#ifdef DEBUG 
  cout<<"note off:highestNoteIndex = "<<highestNoteIndex<<"\n";flush(cout);
#endif
}

void Synth::updateSampleRate(){
  for(int i=0; i<128; i++)
    note_freqs[i] = (2.0 * 440.0 / 32.0) * pow(2, (((float)i - 9.0) / 12.0)) / sampleRate;
}

int Synth::process(jack_nframes_t nframes, void * port_buf, jack_default_audio_sample_t *out){
  jack_midi_event_t in_event;
  jack_nframes_t event_index = 0,i,event_count;
  int j;
  Note* n;

  event_count = jack_midi_get_event_count(port_buf);
  jack_midi_event_get(&in_event, port_buf, 0);
  
  //midi messages described at http://www.midi.org/techspecs/midimessages.php
  for(i = 0; i < nframes; i++){
    if (in_event.time == i && event_index < event_count){
      if ((*(in_event.buffer) & 0xf0) == 0x90)
	noteOn(*(in_event.buffer + 1),*(in_event.buffer + 2));
      else if((*(in_event.buffer) & 0xf0) == 0x80)
	noteRelease(*(in_event.buffer + 1));
      //TODO implement pitch wheel: 
      //TODO implement control changes
      if(++event_index < event_count){
	jack_midi_event_get(&in_event, port_buf, event_index);
	if(in_event.time == i){
	  i--;
	  continue;
	}
      }
    }
    
    out[i]=0;
    for(j=0;j<=highestNoteIndex;j++){
      n = notes[j];
      if(n->on){
	if(n->env.update()){
	  n->ramp += n->freq;
	  if(n->ramp > 1.0) n->ramp -= 2.0;
	  out[i] += volume_*n->env.amp*sin(2*M_PI*(n->ramp));
	}
	else
	  noteOff(n->midinote);
      }
    }
  }
  return 0;  
}
