#include <mpi.h>
#include <stdio.h>

// Demonstration of MPI_Gather
int main()
{
    int world_rank, world_size;
    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int send_data = world_rank;

    int recv_data[world_size];

    MPI_Gather(&send_data, 1, MPI_INT, recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (world_rank == 0)
    {
        printf("Gathered data at root: ");
        for (int i = 0; i < world_size; i++, printf("\n"))
            printf("%d ", recv_data[i]);
    }
    MPI_Finalize();
    return 0;
}
