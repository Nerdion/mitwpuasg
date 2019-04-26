#include<stdio.h>
#define max 10

void displayVector(int size, int vector[max]) {
	int i;
	for(i=0;i<size;i++)
		printf(" %d ",vector[i]);
 }

void displayMatrix(int sizer, int sizec, int matrix[max][max]) {
	int i,j;
	
	for(i=0;i<sizer;i++) {
		for(j=0;j<sizec;j++) {
			printf(" %d ", matrix[i][j]);
		}
		printf("\n");
	}
}

int main() {
	int nproc,nres,res[max],aval[max],work[max],claim[max][max],alloc[max][max],need[max][max];
	int i,j;
	printf("Enter no. of resources- ");
	scanf("%d",&nres);
	
	printf("\nEnter no. of proc- ");
	scanf("%d",&nproc);
	
	printf("\nEnter resource vector-");
	
	for(j=0;j<nres;j++) {
		printf("\n\t for %d-",j);
		scanf("%d",&res[j]);
		aval[j] = res[j];
	}

	printf("\n Enter claim matrix-");
	
	for(i=0;i<nproc;i++) {
		for(j=0;j<nres;j++) {
			scanf("%d",&claim[i][j]);
			if(claim[i][j] > res[j]) {
				printf("\n Wrong input, claim overflow than total resources");
				return 0;
			}
		}
	}
	
	printf("\n Enter allocation matrix-");
	for(i=0;i<nproc;i++) {
		for(j=0;j<nres;j++) {
			scanf("%d",&alloc[i][j]);
			
			if(alloc[i][j] > claim[i][j]) {
				printf("\n Wrong input, allocation overflow then claim");
				return 0;
			}
			
			if(aval[j] - claim[i][j] < 0) {
				printf("\n Cannot do..");
				return 0;
			} else {
				aval[j] = aval[j] - claim[i][j];
			}
		}
	}
	
	displayVector(nres,res);
	printf("\n");
	displayVector(nres,aval);
	return 0;
}
