#ifndef QKNOB_H
#define QKNOB_H
#include <QPainter>
#include <math.h>
#include <QWidget>
#include <QMouseEvent>
#include <iostream>
using namespace std;

#define MIN(a, b) ((a) < (b) ? a : b)

class QKnob : public QWidget{
  Q_OBJECT
  
  float min,max,value;
  int centerX,centerY,size,tickLength;
public:
  QKnob(QWidget *parent):QWidget(parent),
			 min(0),max(1),value(0),
			 tickLength(10){}
  void setRange(float min,float max){this->min = min; this->max = max;}
public slots:
  void setValue(float value){
    if(this->value != value){
      this->value = value;
      update();
      emit valueChanged(value);
    }
  }
signals:
  void valueChanged(float newValue);
protected:
  void paintEvent(QPaintEvent */*event*/){
    QPainter painter(this);
    int w = rect().width();
    int h = rect().height();
    centerX = w/2;
    centerY = h/2;
    size = MIN(w,h)-4;
    float angle = value*2*M_PI;
    //QPen::QPen ( const QBrush & brush, qreal width, Qt::PenStyle style = Qt::SolidLine, Qt::PenCapStyle cap = Qt::SquareCap, Qt::PenJoinStyle join = Qt::BevelJoin )
      
    painter.setPen(QPen(Qt::darkGray,2,Qt::SolidLine,Qt::FlatCap));
    //painter.setPen(QPen(Qt::NoPen));    
    painter.setBrush(Qt::white);
    //    painter.setBrush(Qt::white);
    painter.setRenderHint(QPainter::Antialiasing);
    painter.drawEllipse(2,2,size,size);

    int degAngle = angle/(2*M_PI)*360;
    int arcMargin = 0;
    //    painter.setPen(QPen(Qt::darkGray,size/2,Qt::SolidLine,Qt::FlatCap));    
    //    painter.setPen(QPen(Qt::darkGray,size/2));
    painter.setPen(QPen(Qt::NoPen));    
    painter.setBrush(Qt::darkGray);
    painter.drawPie(2+arcMargin,2+arcMargin,size-2*arcMargin,size-2*arcMargin,270*16,-degAngle*16);
    //arcMargin = 0;
    //painter.setPen(QPen(Qt::black,2,Qt::SolidLine,Qt::FlatCap));
    //    painter.drawArc(2+arcMargin,2+arcMargin,size-2*arcMargin,size-2*arcMargin,270*16,-degAngle*16);

    int tickSize = 4;
    painter.setPen(QPen(Qt::NoPen));
    painter.setBrush(Qt::black);
    painter.translate(centerX,centerY);
    painter.rotate(degAngle+90);
    painter.translate(size/2,0);
    //    painter.drawEllipse(-tickSize/2,-tickSize/2,tickSize,tickSize);
    //    painter.drawLine(size/2-tickLength,0,size/2,0);
  }
  void mouseMoveEvent(QMouseEvent *event){
    float angle = atan2(event->y()-centerY,event->x()-centerX)+3*M_PI/2;
    if(angle > 2*M_PI) angle -= 2*M_PI;
    value = angle / 2*M_PI;
    emit valueChanged(value);
    update();
  }
};

#endif
