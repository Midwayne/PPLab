#include <stdio.h>
#include <mpi.h>

// Demonstration of MPI_Scatter
int main()
{
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);
    int data[world_size];

    if (world_rank == 0)
    {
        for (int i = 0; i < world_size; i++)
            data[i] = i;
    }
    int recv_data;

    MPI_Scatter(data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    printf("Process %d received data %d\n", world_rank, recv_data);
    MPI_Finalize();
    return 0;
}
