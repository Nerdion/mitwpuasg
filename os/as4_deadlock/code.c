#include<stdio.h>
#include<stdlib.h>
#define MAX 10
int n,m,avail[MAX],max[MAX][MAX],alloc[MAX][MAX],need[MAX][MAX],finish[MAX];

void accept()
{
	
	int i,j,k;
	printf("\nenter the no. of processes in system :\n");
	scanf("%d",&n);	
	printf("\nenter the no. of resources type in system :\n");
	scanf("%d",&m);	
	printf("\nenter the elements of available resources matrix :\n");
	for(i=0;i<m;i++)
	{
		scanf("%d",&avail[i]);
		//work[i]=avail[i];	
	}

	printf("\nenter the elements of allocation resources matrix :\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
		scanf("%d",&alloc[i][j]);	
	}
	}

	printf("\nenter the elements of max resources matrix :\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
		scanf("%d",&max[i][j]);	
		  /*if(max[i][j] > work[j])

	      { printf(" error! Process cannot claim more than avilable!");

	       exit(0);

	      }*/

	}
	}

	printf("Need Matrix :\n");
	for(i=0;i<n;i++)
	{
	for(j=0;j<m;j++)
	{
		need[i][j]=max[i][j]-alloc[i][j];
		printf("\t%d\t",need[i][j]);	
		 /*if (need[i][j] < 0) 

	     {                 

	       printf(" Error! cannot allocate more than required ");

	       exit(0);

	     }

	    avail[j] = avail[j]-alloc[i][j]; 

	    if (avail[j] < 0) 

	     {                

	       printf("Error! Insufficient no of resources remaining");

	       exit(0);

	     }
*/
	}
	printf("\n");
	}
	

for(int i=0;i<n;i++)
	{
	finish[i]=0;	
	}
}


	
	
int total_vis;	
int safety()
{
	int work[m],i,j,k=0,rem[k];
	for(i=0;i<m;i++)
	{
		work[i]=avail[i];	
	}
	/*	
	for(i=0;i<n;i++)
	{
		finish[i]=0;	
	}*/
	
	int update;
	total_vis=0;
	do
	{
	update=0;
	for(i=0;i<n;i++)
	{int cn=0;
	
	for(j=0;j<m;j++)
	{
	if(finish[i]==0 && need[i][j]<=work[j])
	{
		//work[j]=work[j]+alloc[i][j];
		cn++;
		//finish[i]=1;
	}
	else 
	{
	break;		
	}

	

	}
	if(cn==m)
	{	
		for(j=0;j<m;j++)
		{
		finish[i]=1;
		work[j]=work[j]+alloc[i][j];		
		}
		printf("p%d->",i);	
		update++;
		total_vis++;
	}
	}
	}while(update>0 && total_vis!=n); 
	
/*	if(finish[i]==1)
	{
	
	}	
*/	

	if(total_vis==n-1)
{
		printf("\n\nThe processor is in Safe state\n");
		printf("\n\n\t*********** Work Matrix ******* \n\n");
		printf("Resource_No\tWork_Instances\n\n");

		for(i=0;i<m;i++)
		{
		printf("R%d\t\t%d\n",i,work[i]);
		}
		printf("\n\n");
}	
if(total_vis<n-1)
		printf("\n\nThe processor is in Unsafe state\n\n");
	


}

void resource_request()
{
	int req[n][m];
	int k,i,j,e,cn=0;
	printf("\nenter the process which is doing resource request\n");
	scanf("%d",&k);
	printf("\nenter the requested matrix\n");
	for(j=0;j<m;j++)
	{
	scanf("%d",&req[k][j]);
	}

	
	for(j=0;j<m;j++)
	{
	if(req[k][j] > need[k][j])
	{
		printf("\nerror\n");
		break;
	}
	else if(req[k][j] > avail[j])
	{
		printf("\nprocess should wait for sometime\n");
		break;
	}

	else 
//if(req[k][j] < need[k][j] && req[k][j] < avail[j])
	{
		cn++;
	}
	

	}
	if(cn==m)
	{
		for(i=0;i<m;i++)
		{
		alloc[k][j] = alloc[k][j] + req[k][j];
		avail[j] = avail[j] - req[k][j];
		need[k][j] = need[k][j] - req[k][j];
		}		
		finish[k]=1;
		safety();
		if(total_vis!=n)
		{
		alloc[k][j] = alloc[k][j] - req[k][j];
		avail[j] = avail[j] + req[k][j];
		need[k][j] = need[k][j] + req[k][j];
		}
		
	}
	printf("\n Available Matrix\n\n");
	for(i=0;i<m;i++)
	{
		printf("R%d\t%d\n",i,avail[i]);
	}
	
}



int main()
{
	
	accept();
	safety();
	resource_request();



	return 0;
}
