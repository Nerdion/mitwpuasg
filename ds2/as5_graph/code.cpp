#include<iostream>
#include<string>
using namespace std;

class Node {
    int vertex;
    string name;
    Node *next;
    friend class graph;
};

class Stack {
	int myStack[10];
	int top;
	
	Stack() {
		top=-1;
	}

public:

	int isEmpty() {
		if(top >= 0) {
			return 0;
		} else {
			return 1;
		}
	}

	//returns stack top
	int stackTop() {
		return myStack[top];
	}

	//popping the top element of the stack
	int pop() {
			return myStack[top--];
	}

	//pushing a new element
	void push(int temp) {
		if(top == 10) {
			cout<<"\t Stack full";
		} else {
			myStack[++top] = temp;
		}
	}

};

class Queue {
  int q[20];
  int front,rear;
public:
  Queue() {
    front=rear=-1;
  }

  void enQueue(int temp) {
    if(!isFull()) q[++rear] = temp;
  }

  int deQueue() {
    return q[++front];
  }

  int isEmpty() {
    if(front==rear) return 1;
    else return 0;
  }

  int isFull() {
    if(rear < 20) return 1;
    else return 0;
  }

  int returnFront() {
    return q[front];
  }
};

class graph {
    int n;
    Node *head[20];
public:
    graph();
    void createGraph();
    void displayGraph();
    void displayDFS();
    void displayDFS(int v,int a[20]);
    void displayDFS_nr();
	void displayBFS();
};


graph::graph() {
    cout<<"Enter count of nodes";
    cin>>n;
    
    for(int i=0;i<n;i++) {
        head[i] = new Node;
        head[i]->vertex = i;
        
        cout<<"\n Enter name for "<<i<<"- ";
        cin>>head[i]->name;
        
        head[i]->next = NULL;
    }
}
    
void graph::createGraph() {
    bool ch;
    Node *temp,*curr;

    for(int i=0;i<n;i++) {
        cout<<"\n Want to enter for "<<head[i]->name<<"- 1.Yes 0.No ";
        cin>>ch;
        temp = head[i];
        while(ch) {
            curr = new Node;
            cout<<"\n Enter friend vertex- ";
            cin>>curr->vertex;
            cout<<"\n Enter friend name- ";
            cin>>curr->name;
            curr->next = NULL;
            
            temp->next = curr;
            temp = temp->next;
            
            cout<<"\n Want to enter more friend - 1.Yes 0.No ";
            cin>>ch;
        }
    }
}

void graph::displayGraph() {
    Node *temp;

    for(int i=0;i<n;i++) {
        temp = head[i];
        cout<<"\n-----------------------------\n";
        while(temp != NULL) {
            cout<<"\t"<<temp->vertex<<" "<<temp->name;
            
            temp = temp->next;
        }
        cout<<"\n-----------------------------\n";
    }
}

void graph::displayDFS() {
    int v,a[20];
    cout<<"\n----  DFS-R DISPLAY ----";
    cout<<"\n Starting from which? ";
    cin>>v;
    
    for(int i=0;i<n;i++)    a[i]=0;

    displayDFS(v,a);
}

void graph::displayDFS(int v, int a[20]) {
    Node *temp = head[v];
    a[v] = 1;
    cout<<"\n-----------------------------\n";
    cout<<"\t"<<temp->vertex<<" "<<temp->name;
    cout<<"\n-----------------------------\n";
    
    while(temp != NULL) {
        v = temp->vertex;
        if(a[v]!= 1) displayDFS(v,a);
        temp = temp->next;
    }
}

void graph::dfsnr()
{
	Stack s;
	int v,i,w,ar[20];

	for(i=0;i<n;i++) ar[i]=0;
  cout<<"\n----  DFS-NR DISPLAY ----";
  cout<<"\n Starting from which? ";	
	cin>>v;

	Node *curr=new node;
	curr=head[v];
	s.push(v);
	
  while(!s.isEmpty()) {
		v=s.stackTop();
		if(ar[v]==0) {
			ar[v]=1;
			cout<<v<<"->"<<curr->name<<endl;
		}

		curr=head[v]->next;
		while(curr!=NULL) {
			w=curr->vertex;
			if(ar[w]==0) {
				ss.push(w);
				break;
			}

			if(curr->next==NULL) {
				ss.pop();
			}
			curr=curr->next;
		}
	}
}

void graph::displayBFS() {
	Node *temp;
	Queue q;
	int a[20],v;

	for(int i=0;i<n;i++) a[i]=0;
  cout<<"\n----  BFS-NR DISPLAY ----";
	cout<<"\n Starting from which?";
    cin>>v;


	temp = head[v];
	a[v] = 1;
	q.enQueue(v);
	
	cout<<"\n-----------------------------\n";
    cout<<"\t"<<temp->vertex<<" "<<temp->name;
    cout<<"\n-----------------------------\n";

	while(!q.isEmpty()) {
		v = q.deQueue();
		temp = head[v]->next;
		while(temp!=NULL) {
			if(a[temp->vertex] == 0) {
				a[temp->vertex] = 1;
				cout<<"\n-----------------------------\n";
				cout<<"\t"<<temp->vertex<<" "<<temp->name;
				cout<<"\n-----------------------------\n";
				q.enQueue(temp->vertex);
			}
			temp = temp->next;
		}
	}

}

int main() {
    graph g;
    g.createGraph();
    g.displayGraph();
    cout<<endl<<endl;
    g.displayDFS();
	g.displayBFS();
}
