#include <stdio.h>
#include <mpi.h>

// Demonstration of MPI_Scatter and MPI_Gather
int main()
{
    MPI_Init(NULL, NULL);
    int world_rank, world_size;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);
    MPI_Comm_size(MPI_COMM_WORLD, &world_size);

    int send_data[4] = {32, 21, 12, 23};
    int recv_data;

    MPI_Scatter(send_data, 1, MPI_INT, &recv_data, 1, MPI_INT, 0, MPI_COMM_WORLD);
    printf("Process %d received data %d\n", world_rank, recv_data);

    recv_data += 10;
    MPI_Barrier(MPI_COMM_WORLD);

    int gathered_data[4];
    MPI_Gather(&recv_data, 1, MPI_INT, gathered_data, 1, MPI_INT, 0, MPI_COMM_WORLD);

    if (world_rank == 0)
    {
        printf("Gathering data after increasing the value by 10\n");
        printf("Gathered data at root: ");
        for (int i = 0; i < world_size; i++, printf("\n"))
            printf("%d ", gathered_data[i]);
    }
    MPI_Finalize();
    return 0;
}