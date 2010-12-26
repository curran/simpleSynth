#ifndef GUI_H
#define GUI_H

#include <QWidget>

class QCloseEvent;
class Synth;

class GUI : public QWidget
{
  Synth* synth_;
 public:
  GUI(Synth *synth,QWidget *parent = 0);
 protected:
  void closeEvent(QCloseEvent *event);
};

#endif
