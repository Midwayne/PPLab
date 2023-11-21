#include <stdio.h>
#include <mpi.h>

// Demonstration of Broadcast operation
int main()
{
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int number;
    if (world_rank == 0)
    {

        number = 42;
        printf("Process 0 broadcasting number %d to all processes\n", number);
    }

    MPI_Bcast(&number, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received number %d\n", world_rank, number);
    MPI_Finalize();
    return 0;
}
