#include<iostream>

using namespace std;

/* Classes used in program */
class Stack;
class TreeNode;
class Tree;

/* logic of stack for non-recursive display */
class Stack {
	friend class Tree;
	TreeNode *myStack[10];
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
	TreeNode* stackTop() {
		return myStack[top];
	}

	int topIndex() {
		return top;
	}

	//popping the top element of the stack
	TreeNode* pop() {
			return myStack[top--];
	}

	//pushing a new element
	void push(TreeNode *temp) {
		if(top == 10) {
			cout<<"\t Stack full";
		} else {
			myStack[++top] = temp;
		}
	}

};

/* Class for NODE's in the TREE*/
class TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
	friend class Tree;
	friend class Stack;
};

/* Class for TREE*/
class Tree {
	//root element of the tree
	TreeNode *root;
    Stack *stack;
public:
	Tree() {
		//defining a null root
		root = new TreeNode;
		root->left=NULL;
		root->right=NULL;
		root->data=-1;
	}
	
	//creation of a TREE non-recursive
	void createTreeNR() {
		TreeNode *temp;
		TreeNode *newNode;
		char choice, myChoice;
		int flag=0;
		temp = root;

		if(temp->data == -1) {
			cout<<"\n Enter root-";
			cin>>temp->data;	
		}


		do {
			temp=root;
			newNode = new TreeNode;
			cout<<"\n Enter new node data-";
			cin>>newNode->data;
			newNode->left=NULL;
			newNode->right=NULL;				
			flag=0;

			while(flag == 0) {
			

				cout<<"\n Where you want to go? 'l' or 'r'";
				cin>>choice;

				if(choice == 'l') {
					if(temp->left != NULL) {
						temp = temp->left;
						flag=0;		
					} else {
						temp->left = newNode;
						temp = temp->left;
						flag=1;
					}
				}

				if(choice == 'r') {
					if(temp->right != NULL) {
						temp = temp->right;
						flag=0;
					} else {
	
						temp->right = newNode;
						temp = temp->right;
						flag=1;
					}	
				}
			}

		
		cout<<"\n Do you want to insert more? 'y' or 'n'";
		cin>>myChoice;

		}while(myChoice == 'y');
	}


	/*logic for recursive creation of a tree*/
	void createTreeR() {
		root = new TreeNode;
		cout<<"Enter new data";
		cin>>root->data;
		root->left=root->right=NULL;

		//calling recursive creation
		createTreeR(root);
	}

	void createTreeR(TreeNode *root) {
		char choice;

		cout<<root->data<<"\n Want new value for left? 'y' ";
		cin>>choice;

		if(choice == 'y') {
			TreeNode *temp;
			temp = new TreeNode;
			cout<<"\n Enter new data";
			cin>>temp->data;
			temp->left = temp->right = NULL;
			root->left = temp;
			createTreeR(temp);
		}

		cout<<root->data<<"\n Want new value for right? 'y'";
		cin>>choice;

		if(choice == 'y') {
			TreeNode *temp;
			temp = new TreeNode;
			cout<<"\n Enter new data";
			cin>>temp->data;
			temp->left = temp->left = NULL;
			root->right = temp;
			createTreeR(temp);
		}

	}

							


	void displayInorderR() {
		displayInorderR(root);
		cout<<"\n";
	}

	void displayInorderR(TreeNode *temp) {

		if(temp->left != NULL) {
			displayInorderR(temp->left);
		}
		cout<<temp->data<<"\t";
		if(temp->right != NULL) {
			displayInorderR(temp->right);
		}
		/*
		if(temp!=NULL) {
			displayInorderR(temp->left);
			cout<<temp->data<<"\t";
			displayInorderR(temp->right);
		}*/
	}

	void displayPreorderR() {
		displayPreorderR(root);
		cout<<"\n";
	}
	//display preorder recursive
	void displayPreorderR(TreeNode *temp) {
		if(temp!=NULL) {
			cout<<temp->data<<"\t";
			displayPreorderR(temp->left);
			displayPreorderR(temp->right);
		}
	}

	void displayPostorderR() {
		displayPostorderR(root);
		cout<<"\n";
	}
	//display postOrder recursive
	void displayPostorderR(TreeNode *temp) {
		if(temp!=NULL) {
			displayPostorderR(temp->left);
			displayPostorderR(temp->right);
			cout<<temp->data<<"\t";
		}
	}

	//Inorder display logic
	void displayInorderNR() {
		TreeNode *temp = root;
		stack = new Stack;

		while(1) {
			//going to leftmost node
			while(temp!=NULL) {
				stack->push(temp);
				temp=temp->left;
			}

			if(stack->isEmpty()) break;
			temp = stack->pop();
			cout<<temp->data<<"\t";

			temp=temp->right;
		}

		cout<<"\n";

	}

	//preorder display logic
	void displayPreorderNR() {
		TreeNode *temp = root;
		stack = new Stack;
		while(1) {

			while(temp != NULL) {
				cout<<temp->data<<"\t";
				stack->push(temp);
				temp=temp->left;
			}

			if(stack->isEmpty()) break;
			temp = stack->pop();

			temp=temp->right;
		}

		cout<<"\n";
	}

	//Postorder nonrecursive logic
	void displayPostorderNR() {
		TreeNode *temp = root;
		stack = new Stack;
		while(1) {
			while(temp!=NULL) {
				stack->push(temp);
				temp=temp->left;
			}
			
			if(stack->stackTop()->right == NULL) {
				temp = stack->pop();
				cout<<temp->data<<"\t";
			}

                        while(!stack->isEmpty() && stack->stackTop()->right == temp) {
                            temp = stack->pop();
                            cout<<temp->data<<"\t";

			}

			if(stack->isEmpty()) break;

			temp=stack->stackTop()->right;
		}
		
	}

	
};

int main() {
	Tree *myTree;
	int choice=0;
	do {
		cout<<"What you want to do?";
		cout<<"\n 1.CreateTreeNonRecurive 2.CreateTreeRecursive";
		cout<<"\n 3.DisplayInorderRecursive 4.DisplayPreorderRecursive 5.DisplayPostorderRecursive";
		cout<<"\n 6.DisplayInorderNonRecursive 7.DisplayPreorderNonRecursive 8.DisplayPostorderNonRecursive";
		cout<<"\n 9.Free Memory";
		cin>>choice;

		switch(choice) {
		case 1:
			myTree = new Tree;
			myTree->createTreeNR();
			break;
		case 2:
			myTree = new Tree;
			myTree->createTreeR();
			break;
		case 3:
			myTree->displayInorderR();
			break;
		case 4:
			myTree->displayPreorderR();
			break;
		case 5:
			myTree->displayPostorderR();
			break;
		case 6:
			myTree->displayInorderNR();
			break;
		case 7:
			myTree->displayPreorderNR();
			break;
		case 8: 
			myTree->displayPostorderNR();
			break;
		case 9:
			cout<<"\n Exiting everything \n\n";
			//truncating the data
			delete myTree;
			break;
		default:
			cout<<"\n Wrong choice";
		}

	}while(choice<10);

	return 0;

}

