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
    TreeNode* temp = q[front];
    front+=1;
    return temp;
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
    int flag;
    do {
      if(root == NULL) {
        root = new TreeNode;
        cout<<"\nEnter root data ";
        cout<<"Enter keyword and meaning";
        cin>>root->word>>root->meaning;
        root->left = root->right = NULL;
      } else {
        flag=0;
        temp = root;

        cout<<"Enter new node-";
        cin>>newNode->word>>newNode->meaning;
        newNode->left=newNode->right = NULL;

        while(flag==0) {
          if(strcmp(temp->word,newNode->word) >= 0) {
            if(temp->left == NULL) {
              temp->left = newNode;
              flag=1;
              temp = temp->left;
              break;
            } else {
              flag=0;
              temp = temp->left;
            }
          } else {
            if(temp->right == NULL) {
              temp->right = newNode;
              flag=1;
              temp = temp->right;
              break;
            } else {
              flag=0;
              temp = temp->right;
            }
          }

          if(flag==1) break;

        }
      }
      cout<<"Want to insert more?";
      cin>>choice;

    }while(choice == 'y' || choice == 'Y');
  }

  void displayBTreeBFS() {
    Queue q;
    TreeNode *temp;

    temp = root;

    q.insertQueue(root);


    while(!q.isEmpty()) {
      temp = q.deleteQueue();

      cout<<" "<<temp->word<<temp->meaning;
      cout<<"\n";

      if(temp->left !=NULL) {
        q.insertQueue(temp->left);
      }

      if(temp->right !=NULL) {
        q.insertQueue(temp->right);
      }

    }
  }

  void displayInorderR() {
    displayInorderR(root);
    cout<<endl;
  }

  void displayInorderR(TreeNode* temp) {
    if(temp!=NULL) {
      displayInorderR(temp->left);
      cout<<" "<<temp->word;
      displayInorderR(temp->right);
    }
  }
};



int main() {
  BTree *BST;
  BST = new BTree;
  BST->createBTree();
  //BST->displayBTreeBFS();
  BST->displayInorderR();

  return 0;
}
