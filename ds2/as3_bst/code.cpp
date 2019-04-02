#include<iostream>
#include<string.h>

using namespace std;


class TreeNode;
class BTree;

class Queue {
  TreeNode *q[20];
  int front,rear;
public:
  Queue() {
    front=rear=-1;
  }


  void insertQueue(TreeNode *temp) {
    if(!isFull()) q[++rear] = temp;
  }

  TreeNode* deleteQueue() {
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
};

class TreeNode {
public:
  char word[20],meaning[30];
  TreeNode *left, *right;
  friend class BTree;
  friend class Queue;
};

class BTree {
  TreeNode *root;
public:
  BTree() {
    root = NULL;
  }


  void createBTree() {
    TreeNode *temp,*newNode;
    char choice = 'y';
    int flag=1;
    do {
      if(root == NULL) {
        root = new TreeNode;
        cout<<"\nEnter root data ";
        cin>>root->word>>root->meaning;
        root->left = root->right = NULL;
      } else {
        cout<<"Enter new node- ";
        newNode = new TreeNode;
        cin>>newNode->word>>newNode->meaning;
        newNode->left = NULL;
        newNode->right = NULL;

        temp = root;
        flag=1;

        while(flag) {
          if(strcmp(temp->word,newNode->word) < 0) {
            if(temp->right == NULL) {
              temp->right = newNode;
              flag=0;
            }
            temp = temp->right;
          } else {
            if(temp->left == NULL) {
              temp->left = newNode;
              flag=0;
            }
            temp = temp->left;
          }
        }
      }
      cout<<"Want to insert more?";
      cin>>choice;

    }while(choice == 'y' || choice == 'Y');
  }

  void displayBTreeBFS() {
    Queue q;
    TreeNode *temp;
    temp = new TreeNode;
    temp = root;

    q.insertQueue(root);

    while(!q.isEmpty()) {
      temp = q.deleteQueue();

      cout<<" "<<temp->word<<" "<<temp->meaning;
      cout<<"\n";

      if(temp->left !=NULL) {
        q.insertQueue(temp->left);
      }

      if(temp->right !=NULL) {
        q.insertQueue(temp->right);
      }
    }
  }

  void insertNode() {
    TreeNode *temp = root;
    TreeNode *newNode = new TreeNode;

    cout<<"\n Enter new node to insert";
    cin>>newNode->word>>newNode->meaning;

    int flag=1;
    while(flag) {
      if(strcmp(temp->word,newNode->word) < 0) {
        if(temp->right == NULL) {
          temp->right = newNode;
          flag=0;
        }
        temp = temp->right;
      } else {
        if(temp->left == NULL) {
          temp->left = newNode;
          flag=0;
        }
        temp=temp->left;
      }
    }
  }

  BTree* mirrorR() {
    return mirrorR(root);
  }

  BTree* mirrorR(TreeNode *temp) {
    BTree *mirror;
    mirror = new BTree;

    
  }
};



int main() {
  BTree *BST;
  BST = new BTree;
  BST->createBTree();
  BST->displayBTreeBFS();
  //BST->insertNode();
  //BST->displayBTreeBFS();
  return 0;
}
