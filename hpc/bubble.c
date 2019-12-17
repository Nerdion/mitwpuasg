#include<stdio.h>
#include<stdlib.h>
#include<omp.h>
#define constMax 35000

int swap(int *a, int *b) {
    int t = *a;
    *a = *b;
    *b = t;
}

int main() {
    int n, *array, i, j;
    double start, end;

    printf("Enter the size-");
    scanf("%d",&n);

    array = (int*) calloc(n, sizeof(int));

    if(array == NULL) {
        printf("Cannot allot");
        return 0;
    }
    start = omp_get_wtime();
//generating random values
    for(i=0;i<n;i++)
        *(array+i) = (rand() % constMax);

// asking user to enter values
    // for(i=0;i<n; i++) {
    //     scanf("%d",array+i);
    // }

    for(i=0; i<n-1; i++) {
        #pragma omp parallel for default(none), shared(i, array, n)
        for(j=0;j<n-i-1; j++) {
            if(*(array+j) > *(array+j+1))
                swap((array+j),(array+j+1));
        }
    }

    end = omp_get_wtime();

    for(i=0;i<n; i++) {
        printf(" %d ",*(array+i));
    }

    printf("\n Time required- %f", (end-start));
    printf("\n");

    free(array);
    return 0;
}