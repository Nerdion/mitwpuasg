#include<iostream>
using namespace std;

class node
{
public:
	node *left,*right;
	int lbit,rbit,data;
	friend class tbt;
};

class tbt
{
node *head;
public:

	tbt()
	{
		head->right=head;
		head->lbit=0;
		head->rbit=1;
	}

	void create();
	node* insuc(node *);
	void inorder();


};

void tbt::create()
{
	node *root,*curr,*temp;
	char side,yn;

	root=new node;

	cout<<"enter the data for the root"<<endl;
	cin>>root->data;

	head->left=root;
	head->lbit=1;

	root->left=root->right=head;
	root->lbit=root->rbit=0;



	do
	{
		int flag=0;
		curr=new node;
		temp=root;
		cout<<"enter the data of node"<<endl;
		cin>>curr->data;

		while(flag==0)
		{
			cout<<"press l to add node to left and r to right of "<<temp->data;
			cin>>side;

			if(side=='l')
			{
				if(temp->lbit==0)
				{
					curr->left=temp->left;
					temp->left=curr;
					temp->lbit=1;

					curr->lbit=curr->rbit=0;
					curr->right=temp;
					flag=1;

				}
				temp=temp->left;
			}

			if(side=='r')
			{
				if(temp->rbit==0)
				{
					curr->right=temp->right;
					temp->right=curr;
					temp->rbit=1;

					curr->lbit=curr->rbit=0;
					curr->left=temp;
					flag=1;

				}
				temp=temp->right;
			}

		}
			cout<<"press y to continue and n to stop"<<endl;
			cin>>yn;

		}while(yn=='y');

}


node* tbt::insuc(node *temp)
{
	node *x;
	x=new node;
	x=temp->right;
	if(temp->rbit==1)

		while(x->lbit==1)

			x=x->left;
	return x;
}


void tbt::inorder()
{
	node *temp;
	temp=new node;
	temp=head;

	while(1)
	{
		temp=insuc(temp);
		if(temp==head)
		break;
		cout<<temp->data;
	}
}
int main()
{
	tbt t;
	t.create();
	t.inorder();

	return 0;
}

/*
OUTPUT:

enter the data for the root
4
enter the data of node
3
press l to add node to left and r to right of 4l
press y to continue and n to stop
y
enter the data of node
6
press l to add node to left and r to right of 4r
press y to continue and n to stop
n
346

*/
