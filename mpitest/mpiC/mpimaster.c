/*
 * mpimaster function definition
 */
#include "mpimaster.h"
#ifndef STDIO_
 #include <stdio.h>
 #define STDIO_
#endif

int master()
{
int ntasks, rank, work;
double result;

  MPI_Status status;
  MPI_Comm_size( MPI_COMM_WORLD,&ntasks);

  /* always use this */
  /* #processes in application */
  /*
  * Seed the slaves.
  */
  printf("in master ntasks: %d\n",ntasks);
  for (rank = 1; rank < ntasks; ++rank) {
    work = rank;/* get_next_work_request */
    printf("work/rank=  %d %d\n",work,rank);
    MPI_Send(&work,   /* message buffer */    
    1,                 /* one data item */
    MPI_INT,          /* data item is an integer */
    rank,             /* destination process rank */
    WORKTAG,          /* user chosen message tag */
    MPI_COMM_WORLD);  /* always use this */
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
  for (rank = 1; rank < ntasks; ++rank) {
    MPI_Recv(&result, 1, MPI_DOUBLE, MPI_ANY_SOURCE,
    MPI_ANY_TAG, MPI_COMM_WORLD, &status);
    printf("the result is: %lf\n",result);
  }
/*
* Tell all the slaves to exit.
*/
for (rank = 1; rank < ntasks; ++rank) {
MPI_Send(0, 0, MPI_INT, rank, DIETAG, MPI_COMM_WORLD);
}

return 1;
}
