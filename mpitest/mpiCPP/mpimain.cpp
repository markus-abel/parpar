/*
 * First test: master collects and prints results
 * input to slaves: an integer
 * output: double the integer
 * split of main, master, and slave into .c and .h files
 */ 
#include "mpi.h"
#include <iostream>
#include "mpimain.hpp"

int main(int argc, char **argv)
{
  int success;

  MPI::Init(argc, argv); /* initialize MPI */
  int myrank = MPI::COMM_WORLD.Get_rank();
  std::cout<<"myrank "<<myrank<<std::endl;

  /* process rank, 0 thru N-1 */
  if (myrank == 0) {
    success=master();
  } 
  else {
    success=slave();
  }
  MPI::Finalize();
  /* cleanup MPI */
  return 0;
}
