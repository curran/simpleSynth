#include <QApplication>
#include <signal.h>
#include "gui.hpp"
#include "jack.hpp"
#include "synth.hpp"

static void signal_handler(int /*sig*/)
{
  disconnect_from_jack();
  exit(0);
}

int main(int argc, char *argv[])
{
  QApplication app(argc, argv);
  Synth *synth = new Synth;
  connect_to_jack(synth,argc,argv);

  signal(SIGQUIT, signal_handler);
  signal(SIGTERM, signal_handler);
  signal(SIGHUP, signal_handler);
  signal(SIGINT, signal_handler);
  
  GUI gui(synth);
  gui.show();
  return app.exec();
}
