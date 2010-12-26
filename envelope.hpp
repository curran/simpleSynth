#ifndef ENVELOPE_H
#define ENVELOPE_H

#include "adsr.hpp"

struct Envelope{
  ADSR *adsr;
  int stage;
  float ramp;
  float rampInc;
  float amp;
  float ampInc;
  float maxAmp;
  Envelope(ADSR *adsr):adsr(adsr){ setStage(ATTACK); }
  int setStage(int stage);

  /**
   * Returns true normally. Returns false when the release stage
   * is finished and the parent note should be turned off.
   */
  bool update(){
    ramp += rampInc;
    amp += ampInc;
    return ramp > 1 ? setStage(++stage) : true;
  }
};
#endif
