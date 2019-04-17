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
	int *myStack[10];
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

	int topIndex() {
		return top;
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
  Node *q[20];
  int front,rear;
public:
  Queue() {
    front=rear=-1;
  }


  void insertQueue(Node *temp) {
    if(!isFull()) q[++rear] = temp;
  }

  Node* deleteQueue() {
    return q[++front];
  }

  int isEmpty() {
    if(front==rear) return 1;
    else return 0;
  }

  int isFull() {
    if(rear == 19) return 1;
    else return 0;
  }

  Node* returnFront() {
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
            cout<<"\n Enter friend vertex";
            cin>>curr->vertex;
            cout<<"\n Enter friend name";
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
    
    cout<<"\n Starting from which?";
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

void graph::displayDFS_nr() {
    Stack s;
    int v,w,a[20];
    
    for(int i=0;i<n;i++) a[i]=0;
    
    cout<<"\n Starting from which?";
    cin>>v;
    
    Node *curr = new Node;
    curr = head[v];
    s.push(v);
}

int main() {
    graph g;
    g.createGraph();
    g.displayGraph();
    cout<<endl<<endl;
    g.displayDFS();
}
