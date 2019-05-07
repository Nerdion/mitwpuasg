#include<stdio.h>
struct term
{
	char bit;
	int c;									//used only in LRU
};
typedef struct term pterm;
pterm pagetable[20];
int buffer[20];

void init()
{
	int i;
	for(i=0;i<20;i++)
	{
		buffer[i]=-1;
		pagetable[i].bit='I';
	}
}

void print_buffer(int f)
{
	int i;
	for(i=0;i<f;i++)
	{
		if(buffer[i]==-1)
		{
			printf("-\t");
		}
		else
		{
			printf("%d\t",buffer[i]);
		}
	}
}

void fifo(int f,int nop)
{
	int pno,j=0,front=0,temp,noft=0,i;
	for(i=1;i<=nop;i++)
	{
		  printf("\n Enter the Page Number : ");
          scanf("%d",&pno);
          if(pno<0)
          {
          		break;
          }
          if(pno>=nop)
          {
          		break;
          }
          if(pagetable[pno].bit=='I')
          {
          		if(j<f)
          		{
          			
          			buffer[j]=pno;
          			pagetable[pno].bit='V';
          			noft++;
          			printf("\n");
          			print_buffer(f);
					printf(" F\n");
          			j++;
          				
          		}	
          		else
          		{
          		
          			temp=buffer[front];
          			buffer[front]=pno;
          			front=(front+1)%f;
          			pagetable[temp].bit='I';
					noft++;
					pagetable[pno].bit='V';
					printf("\n");
					print_buffer(f);
					printf(" F\n");
					
          		}	
          }       
          else 
          {
          		printf("\n");
          		print_buffer(f);
          		printf("\n");
          		
          }
	}
	printf("Total no.of faults = %d \n",noft);

}
void lru(int f,int nop)
{
	int pno,j=0,temp,noft=0,c=0,min,p,index,i;
	for(i=1;i<=nop;i++)
	{
		  printf("\n Enter the Page Number : ");
          scanf("%d",&pno);
          if(pno<0)
          {
          		break;
          }
          if(pno>=nop)
          {
          		break;
          }
          pagetable[pno].c=c++;
          
          if(pagetable[pno].bit=='I')
          {
          		if(j<f)
          		{
          			
          			buffer[j]=pno;
          			noft++;
          			pagetable[pno].bit='V';
          			printf("\n");
					print_buffer(f);
					printf(" F\n");
          			j++;
          				
          		}	
          		else
          		{
          			p=buffer[0];
          			min=pagetable[p].c;
          			index=0;
          			for(j=1;j<f;j++)
          			{
          				p=buffer[j];
          				if(pagetable[p].c<min)
          				{
          					min=pagetable[p].c;
          					index=j;
          				}
          			
          				temp=buffer[index];
          				buffer[index]=pno;
          				pagetable[temp].bit='I';
						pagetable[pno].bit='V';
					}
						noft++;
						printf("\n");
						print_buffer(f);
						printf(" F\n");
					
          			
          			
					
          		}	
          }       
          else 
          {
          		printf("\n");
          		print_buffer(f);
          		printf("\n");
          		
          }
	}
	printf("Total no.of faults = %d \n",noft);

}
int main()
{
	int nof,nop,ch;
	printf("\n Enter no. of frames :");
    scanf("%d",&nof);
	printf("\n Enter no. of pages:\n");
	scanf("%d",&nop);
    
    printf("------MENU--------\n");
    printf("1.FIFO\n");
    printf("\n");
    printf("2.LRU\n");
    printf("-------------------\n");
    printf("Enter your choice of operation\n");
    scanf("%d",&ch);
    switch(ch)
    {
    	case 1:init();
    			fifo(nof,nop);
    			break;
    	case 2:init();
    			lru(nof,nop);
    			break;
    	default:printf("WRONG OPTION!!!!!\n");
    			break;
    
    }
   
    return 0;
}
/*OUTPUT
ibm@IBM:~$ gcc page.c
ibm@IBM:~$ ./a.out

 Enter no. of frames :3

 Enter no. of pages:
8
------MENU--------
1.FIFO

2.LRU
-------------------
Enter your choice of operation
2

 Enter the Page Number : 0

0	-	-	 F

 Enter the Page Number : 2

0	2	-	 F

 Enter the Page Number : 2

0	2	-	

 Enter the Page Number : 0

0	2	-	

 Enter the Page Number : 1

0	2	1	 F

 Enter the Page Number : 3

0	3	1	 F

 Enter the Page Number : 5

5	3	1	 F

 Enter the Page Number : 2

5	3	2	 F
Total no.of faults = 6 
ibm@IBM:~$ gcc page.c
ibm@IBM:~$ ./a.out

 Enter no. of frames :3

 Enter no. of pages:
12
------MENU--------
1.FIFO

2.LRU
-------------------
Enter your choice of operation
1

 Enter the Page Number : 2

2	-	-	 F

 Enter the Page Number : 3

2	3	-	 F

 Enter the Page Number : 2

2	3	-	

 Enter the Page Number : 1

2	3	1	 F

 Enter the Page Number : 5

5	3	1	 F

 Enter the Page Number : 2

5	2	1	 F

 Enter the Page Number : 4

5	2	4	 F

 Enter the Page Number : 5

5	2	4	

 Enter the Page Number : 3

3	2	4	 F

 Enter the Page Number : 2

3	2	4	

 Enter the Page Number : 5

3	5	4	 F

 Enter the Page Number : 2

3	5	2	 F
Total no.of faults = 9 
ibm@IBM:~$ 
*/

