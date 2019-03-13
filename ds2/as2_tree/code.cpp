#include<iostream>

using namespace std;

class Stack;
class TreeNode;
class Tree;

//logic of stack for non-recursive display
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

	TreeNode* stackTop() {
		return myStack[top];
	}

	int topIndex() {
		return top;
	}

	TreeNode* pop() {
			return myStack[top--];
	}

	void push(TreeNode *temp) {
		if(top == 10) {
			cout<<"\t Stack full";
		} else {
			myStack[++top] = temp;
		}
	}


};


class TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
	friend class Tree;
	friend class Stack;
};

class Tree {
	TreeNode *root;
	Stack *stack;
public:
	Tree() {
		root = new TreeNode;
		root->left=NULL;
		root->right=NULL;
		root->data=-1;
	}
	
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

	void displayInorderR() {
		displayInorderR(root);
		cout<<"\n";
	}

	void displayInorderR(TreeNode *temp) {

		if(temp!=NULL) {
			displayInorderR(temp->left);
			cout<<temp->data<<"\t";
			displayInorderR(temp->right);
		}
	}

	void displayPreorderR() {
		displayPreorderR(root);
	}

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

	void displayPostorderR(TreeNode *temp) {
		if(temp!=NULL) {
			displayPostorderR(temp->left);
			displayPostorderR(temp->right);
			cout<<temp->data<<"\t";
		}
	}

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
			cout<<" "<<temp->data<<" ";

			temp=temp->right;
		}

	}
	void displayPreorderNR() {
		TreeNode *temp = root;
		stack = new Stack;
		while(1) {

			while(temp != NULL) {
				cout<<" "<<temp->data<<" ";
				stack->push(temp);
				temp=temp->left;
			}

			if(stack->isEmpty()) break;
			temp = stack->pop();

			temp=temp->right;
		}
	}
/*
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
				cout<<" "<<temp->data<<" ";
			}

			while(stack->stackTop()->right == temp) {
				if(stack->isEmpty()) {
					break;
				}
				else {
					temp = stack->pop();
					cout<<""<<temp->data<<" ";
				}
			}

			if(stack->isEmpty()) break;

			temp=stack->stackTop()->right;
		}
	}
*/
	
};

int main() {
		Tree myTree = Tree();
		int choice=0;
		/*
		do {
			cout<<"What you want to do?\n 1.CreateTreeNonRecurive\n 2.DisplayTreeInorderRecursive\n";
			cout<<"3.DisplayTreePreorderRecursive\n 4.DisplayTreePostorderRecursive\n 5.Exit";
			cin>>choice;

			switch(choice) {
				case 1:
					myTree.createTreeNR();
					break;
				case 2:
					myTree.displayInorderR();
					break;
				case 3:
					myTree.displayPreorderR();
					break;
				case 4:
					myTree.displayPostorderR();
					break;
				case 5:
					cout<<"\nThis is exit";
					break;
				default:
					cout<<"\n Wrong choice";
			}

		}while(choice<5);*/

		myTree.createTreeNR();
		//myTree.displayInorderR();
		//myTree.displayInorderNR();
		//myTree.displayPreorderNR();
		myTree.displayPostorderNR();
		return 0;

}
