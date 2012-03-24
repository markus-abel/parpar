/*
 * slave file for the mpimain test
*/

#include "mpislave.h"
#ifndef STDIO_
 #include <stdio.h>
 #define STDIO_
#endif

slave()
{
  double result;
  int work;
  MPI_Status status;
  
  printf("in slave\n");
  for (;;) {
    MPI_Recv(&work, 1, MPI_INT, 0, MPI_ANY_TAG,
    MPI_COMM_WORLD, &status);
    /*
    * Check the tag of the received message.
    */
    if (status.MPI_TAG == DIETAG) {
      printf("oh no, I am dying as a slave with work %d!\n",work);
      return 0;
    }
    result = 2.0*work/* do the work */;
    MPI_Send(&result, 1, MPI_DOUBLE, 0, 0, MPI_COMM_WORLD);
  }
  return 1;
}

