#include<stdio.h>

struct process {
	int id,bt,at,tt,wt,rt; 
};

void readProcesses(struct process *p, int n) {
	int i;
	printf("\n Accept data of processes");
	
	for(i=0;i<n;i++) {
		p[i].id = i+1;
		
		printf("\n Enter burst time- ");
		scanf("%d",&p[i].bt);
		
		printf("\n Enter arrival time-");
		scanf("%d",&p[i].at);
		
		p[i].tt = 0;
	 	p[i].wt = 0;
	 	p[i].rt = p[i].bt;
	}
}

void sortProcesses(struct process *p, int n) {
	int i,j;
	struct process temp;
	
	for(i=0;i<n-1;i++) {
		for(j=0;j<n-i-1;j++) {
			if(p[j].at > p[j+1].at) {
				temp = p[j];
				p[j] = p[j+1];
				p[j+1] = temp;
			}
		}
	}
}

void executeSchedulingFCFS(struct process *p, int n) {
	int i, tWait, tTurn, currTime = p[0].at;
	float wAvg, tAvg;
	
	printf("\n	GANTT CHART	\n");
	
	for(i=0;i<n;i++) {
		p[i].rt = 0;
		printf(" <PID>%d	",p[i].id);
		currTime = currTime + p[i].bt;
		p[i].tt = currTime - p[i].at;
		p[i].wt = p[i].tt - p[i].bt;
		tWait = tWait + p[i].wt;
		tTurn = tTurn + p[i].tt;
		if(i<n-1 && currTime < p[i+1].at) {
			printf("<IDLE>");
			currTime = p[i+1].at;
		}
	}
	printf("\n");
	tAvg = tWait/n;
	tAvg = tTurn/n;
}

void executeSchedulingSJF(struct process *p, int n) {
}

void displayScheduled(struct process *p, int n) {
	int i,j;
	printf("\n\tID\tBT\tAT\tTT\tWT");
	
	for(i=0;i<n;i++) {
		printf("\n\t%d\t%d\t%d\t%d\t%d",p[i].id,p[i].bt,p[i].at,p[i].tt,p[i].wt);
	}
	printf("\n");
}

int main() {
	int n,choice;
	struct process p[15];

	do {
		printf("What you want to do? 1.FCFS 2.SJF ");
		scanf("%d",&choice);
		
		printf("\n\t No. of processes- ");
		scanf("%d",&n);
		
		switch(choice) {
		case 1:
			printf("\n\n\t FCFS");	
			readProcesses(p,n);
			sortProcesses(p,n);
			executeSchedulingFCFS(p,n);	
			displayScheduled(p,n);
			break;
		case 2:
			printf("\n\n\t SJF");
			readProcesses(p,n);
			sortProcesses(p.n);
			executeSchedulingSJF(p,n);
			displayScheduled(p,n);
			break;
		default:
			printf("\n\n\n EXIT \n\n");
		}
		
		
	}while(choice ==1 || choice==2);
	return 0;
}
