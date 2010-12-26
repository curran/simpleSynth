#ifndef SYNTH_H
#define SYNTH_H
#include "jack.hpp"
#include "note.hpp"
#include <jack/jack.h>
#include <jack/midiport.h>
#include <QObject>

class Synth : public QObject{
  Q_OBJECT
  /** The overall volume, from 0 to 1. */
  float volume_;

  float note_freqs[128];
  const int polyphony;
  Note** notes;
  int highestNoteIndex;
  void noteOn(int midinote,int velocity);
  void noteRelease(int midinote);
  void noteOff(int midinote);
public:
  Synth();
  void updateSampleRate();
  int process(jack_nframes_t nframes, void * port_buf, jack_default_audio_sample_t *out);
  float volume(){return volume_;}
  ADSR adsr;
public slots:
  void setVolume(float value){
    if(volume_ != value){
      volume_ = value;
      emit volumeChanged(value);
    }
  }
signals:
  /** Emitted when the overall volume changes. Value os from 0 to 127 */
  void volumeChanged(float newValue);
};


#endif
