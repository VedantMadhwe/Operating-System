#include<stdio.h>
#define MAX_PROCESS 20
#define MAX_RESOURCES 20

void main() {
    int A, B, C;
    int inst[MAX_RESOURCES], alloc[MAX_PROCESS][MAX_RESOURCES], maxneed[MAX_PROCESS][MAX_RESOURCES], avail[MAX_RESOURCES];
    int i, j, n, n_inst;

    printf("Enter number of instances: ");
    scanf("%d", &n_inst);

    printf("Enter the number of instances in the form A B C:\n");
    for (i = 0; i < n_inst; i++) {
        scanf("%d", &inst[i]);
    }

    printf("Enter the number of processes: ");
    scanf("%d", &n);

    // Filling the allocation
    for (i = 0; i < n; i++) {
        printf("Enter the allocation for process P%d:\n", i + 1);
        for (j = 0; j < n_inst; j++) {
            scanf("%d", &alloc[i][j]);
        }
    }

    // Printing the allocation table
    for (i = 0; i < n; i++) {
        printf("The allocation for process P%d:\n", i + 1);
        for (j = 0; j < n_inst; j++) {
            printf("%d\t", alloc[i][j]);
        }
        printf("\n");
    }

    // Max need filling
    for (i = 0; i < n; i++) {
        printf("Enter the Max need for process P%d:\n", i + 1);
        for (j = 0; j < n_inst; j++) {
            scanf("%d", &maxneed[i][j]);
        }
    }

    // Printing max need table
    for (i = 0; i < n; i++) {
        printf("The Max need for process P%d:\n", i + 1);
        for (j = 0; j < n_inst; j++) {
            printf("%d\t", maxneed[i][j]);
        }
        printf("\n");
    }

    // Calculating the sum of allocations
    int sum[MAX_RESOURCES] = { 0 };
    for (i = 0; i < n; i++) {
        for (j = 0; j < n_inst; j++) {
            sum[j] += alloc[i][j];
        }
    }

    for (j = 0; j < n_inst; j++) {
        printf("sum = %d\t", sum[j]);
    }

    // Calculating the available instances
    for (i = 0; i < n_inst; i++) {
        int total = 0;
        for (j = 0; j < n; j++) {
            total += alloc[j][i];
        }
        avail[i] = inst[i] - total;
    }

    // Printing the available instances
    printf("\nAvailable instances:\n");
    for (i = 0; i < n_inst; i++) {
        printf("%d\t", avail[i]);
    }
    printf("\n");





}
