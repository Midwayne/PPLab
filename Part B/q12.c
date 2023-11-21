#include <stdio.h>
#include <mpi.h>

// Demonstration of MPI_Allreduce (MPI_MAX, MPI_MIN, MPI_SUM, MPI_PROD)
int main()
{
    MPI_Init(NULL, NULL);
    int world_rank;
    MPI_Comm_rank(MPI_COMM_WORLD, &world_rank);

    int data = world_rank;
    int max_val, min_val, sum, prod;

    MPI_Allreduce(&data, &max_val, 1, MPI_INT, MPI_MAX, MPI_COMM_WORLD);

    MPI_Allreduce(&data, &min_val, 1, MPI_INT, MPI_MIN, MPI_COMM_WORLD);

    MPI_Allreduce(&data, &sum, 1, MPI_INT, MPI_SUM, MPI_COMM_WORLD);

    MPI_Allreduce(&data, &prod, 1, MPI_INT, MPI_PROD, MPI_COMM_WORLD);

    printf("Process %d - Max: %d, Min: %d, Sum: %d, Product: %d\n",
           world_rank, max_val, min_val, sum, prod);
    MPI_Finalize();
    return 0;
}
