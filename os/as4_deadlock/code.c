#include<stdio.h>
#define max 10

void displayVector(int size, int vector[max]) {
	int i;
	for(i=0;i<size;i++)
		printf(" %d ",vector[i]);
	printf("\n");
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
	int nproc,nres;
	int res[max],aval[max],work[max],finish[max],safe[max];
	int want[max][max],alloc[max][max],need[max][max];
	int i,j,k,y,ind=0;
	int flag;

	printf("Enter no. of resources- ");
	scanf("%d",&nres);
	
	printf("\nEnter no. of proc- ");
	scanf("%d",&nproc);
	
	for(i=0;i<nproc;i++) {
		finish[i]=0;
	}

	printf("\nEnter resource vector-\n");
	for(j=0;j<nres;j++) {
		printf("\n\t for %d-",j);
		scanf("%d",&res[j]);
		aval[j] = res[j];
	}

	printf("\nEnter want matrix-\n");
	for(i=0;i<nproc;i++) {
		for(j=0;j<nres;j++) {
			scanf("%d",&want[i][j]);
		}
	}
	
	printf("\nEnter allocation matrix-\n");
	for(i=0;i<nproc;i++) {
		for(j=0;j<nres;j++) {
			scanf("%d",&alloc[i][j]);
			aval[j] = aval[j] - alloc[i][j];
		}
	}
	
	printf("\nCalculating need matrix\n");
	for(i=0;i<nproc;i++) {
		for(j=0;j<nres;j++) {
			need[i][j] = want[i][j] - alloc[i][j];
		}
	}

	//ResourceVector
	printf("\n Resource vector-\n");
	displayVector(nres,res);

	//NeedMAX Matrix
	printf("\n Need matrix-\n");
	displayMatrix(nproc,nres,want);

	//Allocation Matrix
	printf("\n Allocation matrix-\n");
	displayMatrix(nproc,nres,alloc);

	//Available after allocation
	printf("\n Available vector-\n");
	displayVector(nres,aval);

	//Need matrix C-A
	printf("\n Need matrix-\n");
	displayMatrix(nproc,nres,need);

	for(k=0;k<nproc;k++) {
		for(i=0;i<nproc;i++) {
			if(finish[i] == 0) {
				flag=0;

				for(j=0;j<nres;j++) {
					if(need[i][j] > aval[j]) {
						flag=1;
						break;
					}
				}

				if(flag == 0) {
					safe[ind++] = i; //saving process index
					for(y=0;y<nres;y++) {
						aval[y] += alloc[i][y];
					}
					finish[i]=1;
				}
			}
		}
	}

	printf("\n This is safe seq-\n");

	for(i=0;i<nproc-1;i++) {
		printf(" P%d--> ",safe[i]);
	}
	printf(" P%d",safe[nproc-1]);
	printf("\n");
	return 0;
}
