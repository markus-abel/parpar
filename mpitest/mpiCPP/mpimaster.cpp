/*
 * mpimaster function definition
 * has to be turned to true c++
 */

#ifndef STDIO_
 #include <iostream>
 #define STDIO_
#endif
#ifndef MPIMAIN_
 #include "mpimain.hpp"
 #define MPIMAIN_
#endif


int master()
{
  int rank, work;
  double result;
  MPI::Status status;
  
  int numprocs = MPI::COMM_WORLD.Get_size( ); 

  /*
  * Seed the slaves.
  */
  std::cout<<"in master numprocs  "<<numprocs<<std::endl;
  for (rank = 1; rank < numprocs; ++rank) {
    work = rank;/* get_next_work_request */
    std::cout<<"work/rank=  "<<work<<"\t"<<rank<<std::endl;
    MPI::COMM_WORLD.Send(&work,   /* message buffer */    
    1,                 /* one data item */
    MPI_INT,          /* data item is an integer */
    rank,             /* destination process rank */
    WORKTAG);            /* user chosen message tag */
  } 

    /*
    * Receive a result from any slave and dispatch a new work
    * request until work requests have been exhausted.
    */

//    work = printf("hi slave")/* get_next_work_request */;
//    int i=0;
//    while (i<4) {
//      MPI_Recv(&result, /* message buffer */
//      1,                /* one data item */
//      MPI_DOUBLE,       /* of type double real */
//      MPI_ANY_SOURCE,   /* receive from any sender */
//      MPI_ANY_TAG,      /* any type of message */
//      MPI_COMM_WORLD,   /* always use this */
//      &status);
      /* received message info */
//      MPI_Send(&work, 1, MPI_INT, status.MPI_SOURCE,
//      WORKTAG, MPI_COMM_WORLD);
//      work = printf("hi slave")/* get_next_work_request */;
//      ++i;
//    }
/*
* Receive results for outstanding work requests.
*/
  for (rank = 1; rank < numprocs; ++rank) {
     MPI::COMM_WORLD.Recv(&result, 1, MPI::DOUBLE, MPI::ANY_SOURCE,
     MPI::ANY_TAG, status);
     std::cout<<"the result is:  "<<result<<std::endl;
  }
/*
* Tell all the slaves to exit.
*/
for (rank = 1; rank < numprocs; ++rank) {
MPI::COMM_WORLD.Send(0, 0, MPI::INT, rank, DIETAG);
}

return 0;
}
