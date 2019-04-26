//solved
#include<iostream>
#include<stdlib.h>
#define MAX 10
#define INF 9999
using namespace std;
class graph_prims
{
	int n;  // Total vertices
	int cost[MAX][MAX]; // for creating cost matrix

public:
	graph_prims()
	{
		cout<<"Enter total number of vertices\n";
		cin>>n;  // Taking value of vertices from user
		for(int i = 0; i< n; i++)
		{
			for(int j = 0; j< n; j++)
			{
				cost[i][j] = INF;
			}
		}
	}
	void create();
	void display();
	void prims();
};
void graph_prims:: create()
{
	int edges;
	int start_vertex, end_vertex,cost_edge;
	cout<<"Accept number of edges from the user\n";
	cin>>edges;  // It accepts the total number of edges form the user
	for(int i = 0; i < edges; i++)
	{
		cout<<"Enter start vertex ";
		cin>>start_vertex;
		cout<<"\nEnter end vertex ";
		cin>>end_vertex;
		cout<<"\nEnter cost of edge ";
		cin>>cost_edge;
		cout<<"\n";
		cost[start_vertex][end_vertex] = cost[end_vertex][start_vertex] = cost_edge;
	}

}
void graph_prims:: display()
{
	for(int i = 0; i< n; i++)
	{
		for(int j = 0; j< n; j++)
		{
			cout<<" "<<cost[i][j]<<" ";
		}
		cout<<"\n";
	}
}
void graph_prims:: prims()
{
	int nearest[MAX];
	int mincost, start_vertex;
	int min;  // Out of given edges, selects minimum edge
	int r = 0;
	int k;
	int t[n][2];  // 1st column consists of the start vertices and the 2nd column consists of the end vertices
	cout<<"Enter starting vertex\n";
	cin>>start_vertex;
	for(int i = 0; i < n ; i ++)
	{
		nearest[i] = start_vertex;
	}
	nearest[start_vertex] = -1;
	mincost = 0;
	for(int i = 0; i < n-1; i++)
	{
		min = INF;  // setting the minimum to
		for(int j = 0; j< n; j++)
		{
			if(nearest[j] != -1 && cost[nearest[j]][j] < min)
			{
				k = j;
				min = cost[nearest[j]][j];
			}
		}
		// do it0
		if(k != t[r][0])
		{
		t[r][0] = k;
		t[r][1]=nearest[k];
		// nearest keeps track of next vertex in
		}
		// do it
		mincost = mincost + cost[k][nearest[k]];
		nearest[k] =-1;
		r++;
		for(int j = 0; j < n; j++)
		{
			if(nearest[j] != -1 && cost[nearest[j]][j] > cost[j][k])
			{
				nearest[j] = k;   // Setting the nearest values of k
			}
		}
	}
	// Display
	for(int i = 0; i < n-1; i++)
	{
		for(int j = 0; j< 2; j++)
		{
			cout<<" "<<t[i][j]<<" ";
		}
		cout<<"\n";
	}
	cout<<"Minimum cost: "<<mincost<<endl;
}
int main()
{
	int ch;
	graph_prims t1;
	while(1)
	{
		cout<<"1.Create 2.Display 3.Prims 4.Exit";
		cin>> ch;
		switch(ch)
		{
		case 1:
			t1.create();
			break;
		case 2:
			t1.display();
			break;
		case 3:
			t1.prims();
			break;
		case 4:
			cout<<"Thank You for your time!!\n";
			exit(0);
			break;
		default:
			cout<<"Enter valid input!!\n";
			break;
		}
	}
	return 0;
}
