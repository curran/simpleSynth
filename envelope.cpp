#include "jack.hpp"
#include "adsr.hpp"
#include "envelope.hpp"

int Envelope::setStage(int stage){
  this->stage = stage;
  switch(stage){
  case ATTACK:
    ramp = 0;
    rampInc = 1000.0/(adsr->attack()*sampleRate);
    ampInc = rampInc*(maxAmp-amp);
#ifdef DEBUG 
    cout<<"attack set\n";flush(cout);
#endif
    return true;
  case DECAY:
    ramp = 0;
    rampInc = 1000.0/(adsr->decay()*sampleRate);
    amp = maxAmp;
    ampInc = -rampInc*(maxAmp*adsr->sustain());
#ifdef DEBUG 
    cout<<"decay set\n";flush(cout);
#endif
    return true;
  case SUSTAIN:
    ramp = 0;
    rampInc = 0;
    amp = maxAmp*adsr->sustain();
    ampInc = 0;
#ifdef DEBUG 
    cout<<"sustain set\n";flush(cout);
#endif
    return true;
  case RELEASE:
    {
    ramp = 0;
    float sustainAmp = maxAmp*adsr->sustain();
    float releaseTime = amp*adsr->release()/sustainAmp;
    rampInc = 1000.0/(releaseTime*sampleRate);
    ampInc = -rampInc*amp;
#ifdef DEBUG 
    cout<<"release set\n";flush(cout);
#endif
    return true;
    }
  default:
    return false;
  }
}
