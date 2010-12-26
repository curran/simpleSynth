#ifndef NOTE_H
#define NOTE_H

#include "adsr.hpp"
#include "envelope.hpp"

struct Note {
  Envelope env;
  bool on;
  int midinote;
  float freq;
  float ramp;
  Note(ADSR *adsr):env(Envelope(adsr)),on(false),ramp(0){}
};
#endif
