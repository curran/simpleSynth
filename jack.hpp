#ifndef JACK_H
#define JACK_H

#include <jack/jack.h>

class Synth;
extern jack_default_audio_sample_t sampleRate;
void connect_to_jack(Synth *synth,int argc, char *argv[]);
void disconnect_from_jack();
#endif
