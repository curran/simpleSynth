#ifndef ADSR_H
#define ADSR_H
#include <QObject>

enum { ATTACK, DECAY, SUSTAIN, RELEASE };

class ADSR : public QObject{
  Q_OBJECT

  float attack_;
  float decay_;
  float sustain_;
  float release_;
public:
  float attack(){return attack_;}
  float decay(){return decay_;}
  float sustain(){return sustain_;}
  float release(){return release_;}
public slots:
  void setAttack(float value){
    if(attack_ != value){
      attack_ = value;
      emit attackChanged(value);
    }
  }
  void setDecay(float value){
    if(decay_ != value){
      decay_ = value;
      emit decayChanged(value);
    }
  }
  void setSustain(float value){
    if(sustain_ != value){
      sustain_ = value;
      emit sustainChanged(value);
    }
  }
  void setRelease(float value){
    if(release_ != value){
      release_ = value;
      emit releaseChanged(value);
    }
  }

signals:
  void attackChanged(float newValue);
  void decayChanged(float newValue);
  void sustainChanged(float newValue);
  void releaseChanged(float newValue);

};

#endif
