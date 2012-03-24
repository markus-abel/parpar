/*
 * First test: master collects and prints results
 * input to slaves: an integer
 * output: double the integer
 * split of main, master, and slave into .c and .h files
 */ 
#include "mpi.h"
#include <stdio.h>
#include "mpimaster.h"
#include "mpimain.h"
#include "mpislave.h"


int main(argc, argv)
int argc;
char *argv[];
{
  int myrank,success;

  MPI_Init(&argc, &argv); /* initialize MPI */
  MPI_Comm_rank(MPI_COMM_WORLD, /* always use this */
  &myrank);

  /* process rank, 0 thru N-1 */
  if (myrank == 0) {
    success=master();
  } else {
    success=slave();
  }
  MPI_Finalize();
  /* cleanup MPI */
  return 1;
}
