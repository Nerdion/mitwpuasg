#include<iostream>

using namespace std;

class Tree;
class TreeNode {
	int data;
	TreeNode *left;
	TreeNode *right;
	friend class Tree;
};

class Tree {
	TreeNode *root;
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
	}

	void displayPostorderR(TreeNode *temp) {
		if(temp!=NULL) {
			displayPostorderR(temp->left);
			displayPostorderR(temp->right);
			cout<<temp->data<<"\t";
		}
	}

	

	
};

int main() {
		Tree myTree = Tree();
		int choice=0;

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

		}while(choice<5);
		myTree.createTreeNR();
		myTree.displayInorderR();
		myTree.displayPreorderR();
		myTree.displayPostorderR();

		return 0;

}
