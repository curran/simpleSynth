#include "jack.hpp"
#include "synth.hpp"
#include <QMessageBox>
#include <iostream>
using namespace std;

const char* appName = "SimpleSynth";
Synth *synth;
jack_client_t *client;
jack_port_t *input_port;
jack_port_t *output_port;

jack_default_audio_sample_t sampleRate;

int process(jack_nframes_t nframes, void * /*arg*/)
{
  return synth->process(nframes,jack_port_get_buffer(input_port, nframes), (jack_default_audio_sample_t *) jack_port_get_buffer (output_port, nframes));
}

int srate(jack_nframes_t /*nframes*/, void */*arg*/)
{
  sampleRate = jack_get_sample_rate (client);
  synth->updateSampleRate();
  return 0;
}

void jack_shutdown(void */*arg*/)
{
  cout<<"Disconnected from Jack!";
}

void connect_to_jack(Synth *synthesizer,int argc, char *argv[]){
  synth = synthesizer;
  
  if ((client = jack_client_open(appName, JackNoStartServer, NULL)) == 0){
    QMessageBox::critical( 0, appName, QString("Cannot connect to Jack. Is the Jack server running?"));
    exit(1);
  }

  sampleRate = jack_get_sample_rate (client);
  synth->updateSampleRate();

  jack_set_process_callback (client, process, 0);
  jack_set_sample_rate_callback (client, srate, 0);
  jack_on_shutdown (client, jack_shutdown, 0);

  input_port = jack_port_register (client, "midi_in", JACK_DEFAULT_MIDI_TYPE, JackPortIsInput, 0);
  output_port = jack_port_register (client, "audio_out", JACK_DEFAULT_AUDIO_TYPE, JackPortIsOutput, 0);

  if (jack_activate(client)){
    QMessageBox::critical( 0, appName, QString("Cannot activate Jack client."));
    exit(1);
  }

  //automatically connect to system out
  jack_connect (client,jack_port_name(output_port),"system:playback_1");
  //connect to midi source specified in command line
  if(argc > 1){
    jack_connect (client,argv[1],jack_port_name(input_port));
    //    cout << argv[1]<<"\n";flush(cout);
  }
}

void disconnect_from_jack(){
    jack_client_close(client);
}

