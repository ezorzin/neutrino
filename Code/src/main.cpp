/// @file

#include "neutrino.hpp"
#include "program.hpp"

int main()
{
  neutrino* program = new neutrino();                                           // The Neutrino object.

  neutrino->init();                                                             // Initializing neutrino...

  setup();                                                                      // Executing Neutrino "setup" function...

  while (!program->gui_window->closed())                                        // Opening window...
  {
    program->get_tic();                                                         // Getting "tic" [us]...
    loop();                                                                     // Executing Neutrino "loop" function...
    program->get_toc();                                                         // Getting "toc" [us]...
  }

  terminate();                                                                  // Terminating Neutrino application...

  return 0;
}
