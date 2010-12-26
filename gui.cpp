#include "gui.hpp"
#include "synth.hpp"
#include "jack.hpp"
#include "qknob.hpp"
#include <QWidget>
#include <QCloseEvent>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <QColor>


#define MIN(a, b) ((a) < (b) ? a : b)

class RoundedRect : public QWidget{
  int radius;
  QPen pen;
public:
  RoundedRect(QWidget *parent = 0,int radius = 10):QWidget(parent),
					       radius(radius),
					       pen(QPen(Qt::black,2)){
  }
protected:
  void paintEvent(QPaintEvent */*event*/){
    QPainter painter(this);
    painter.setPen(Qt::NoPen);
    int x = 200;
    painter.setBrush(QColor(x,x,x));
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawRoundedRect (rect(), radius,radius);
  }
};

GUI::GUI(Synth *synth,QWidget *parent)
  : QWidget(parent), synth_(synth){
  setGeometry(0,0,500,500);

  QPalette pal = palette();
  pal.setColor(QPalette::Window,Qt::black);
  setPalette(pal);

  int knobSize = 32;
  int knobPadding = 3;
  int knobMargin = 5;
  int rectMargin = 5;
  int textHeight = 4;
  int x = 0,y = 0;

  RoundedRect *rect = new RoundedRect(this,knobSize/2+knobMargin);
  rect->setGeometry(rectMargin,rectMargin,
		    2*rectMargin+3*knobSize+2*knobPadding,
		    2*rectMargin+knobSize+textHeight+knobMargin);

  x = 0;
  QKnob *volumeKnob = new QKnob(this);
  volumeKnob->setRange(0, 1);
  volumeKnob->setGeometry(rectMargin+knobMargin+x*(knobSize+knobPadding),
			  rectMargin+knobMargin+y*(knobSize+knobPadding),knobSize,knobSize);
  volumeKnob->setValue(synth->volume());
  connect(volumeKnob, SIGNAL(valueChanged(float)), synth, SLOT(setVolume(float)));
  connect(synth, SIGNAL(volumeChanged(float)), volumeKnob, SLOT(setValue(float)));



  x = 1;
  QKnob *attackKnob = new QKnob(this);
  attackKnob->setRange(0, 1);
  attackKnob->setGeometry(rectMargin+knobMargin+x*(knobSize+knobPadding),
			  rectMargin+knobMargin+y*(knobSize+knobPadding),knobSize,knobSize);
  cout << "volume = " << synth->volume();
  attackKnob->setValue(synth->adsr.attack());
  connect(attackKnob, SIGNAL(valueChanged(float)), &(synth->adsr), SLOT(setAttack(float)));
  connect(&(synth->adsr), SIGNAL(attackChanged(float)), attackKnob, SLOT(setValue(float)));

  x = 2;
  QKnob *decayKnob = new QKnob(this);
  decayKnob->setRange(0, 1);
  decayKnob->setGeometry(rectMargin+knobMargin+x*(knobSize+knobPadding),
			  rectMargin+knobMargin+y*(knobSize+knobPadding),knobSize,knobSize);
  decayKnob->setValue(synth->adsr.decay());
  connect(decayKnob, SIGNAL(valueChanged(float)), &(synth->adsr), SLOT(setDecay(float)));
  connect(&(synth->adsr), SIGNAL(decayChanged(float)), decayKnob, SLOT(setValue(float)));
}



void GUI::closeEvent(QCloseEvent *event){
  disconnect_from_jack();
  event->accept();
}
