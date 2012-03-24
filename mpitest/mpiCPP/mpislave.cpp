/*
 * slave file for the mpimain test
*/

#include "mpislave.h"
#ifndef IOSTREAM_
 #include <iostream>
 #define IOSTREAM_
#endif

#ifndef MPIMAIN_
 #include "mpimain.hpp"
 #define MPIMAIN_
#endif
int slave()
{
  double result;
  int work;
  MPI::Status status;
  
  std::cout<<"in slave"<<std::endl;
  for (;;) {
    MPI::COMM_WORLD.Recv(&work, 1, MPI::INT, 0, MPI::ANY_TAG, status);
    /*
    * Check the tag of the received message.
    */
    if (status.Get_tag() == DIETAG) {
      std::cout<<"oh no, I am dying as a slave with work "<<work<<std::endl;
      return 0;
    }
    result = 2.0*work/* do the work */;
    MPI::COMM_WORLD.Send(&result, 1, MPI::DOUBLE, 0, 0);
  }
  return 1;
}

