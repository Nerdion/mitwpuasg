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

  TreeNode* returnFront() {
    return q[front];
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
public:
  TreeNode *root;
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
    q.insertQueue(NULL);
    while(!q.isEmpty()) {
      temp = q.deleteQueue();

      if(temp == NULL) {
        cout<<"\n";
        q.insertQueue(NULL);
      } else {
        cout<<temp->word<<" "<<temp->meaning<<"\t";

        if(temp->left !=NULL) {
          q.insertQueue(temp->left);
        }

        if(temp->right !=NULL) {
          q.insertQueue(temp->right);
        }
      }
    }
    cout<<"\n";
  }

  void insertNode(TreeNode* newNode) {
    TreeNode *temp = root;
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

  void mirrorR() {
    mirrorR(root);
  }

  void mirrorR(TreeNode *root) {
    if(root != NULL) {
      TreeNode* temp = new TreeNode;
      mirrorR(root->right);
      mirrorR(root->left);

      temp = root->left;
      root->left = root->right;
      root->right = temp;
    } else {
      return;
    }
  }


  TreeNode* deleteKeyword(char* key) {
    TreeNode* temp = deleteKeyword(key, root);
    return temp;
  }

  TreeNode* deleteKeyword(char* key, TreeNode* root) {
    if(root == NULL) return root;

    if(strcmp(root->word,key) > 0) {
      root->left = deleteKeyword(key,root->left);
    } else if(strcmp(root->word,key) < 0) {
      root->right = deleteKeyword(key, root->right);
    } else {
      if(root->left == NULL) {
        TreeNode *temp = root->right;
        delete root;
        return temp;
      } else if(root->right == NULL) {
        TreeNode *temp = root->left;
        delete root;
        return temp;
      }

      TreeNode *succParent = root->right;
      // Find succ
      TreeNode *succ = root->right;
      while(succ->left != NULL) {
        succParent = succ;
        succ = succ->left;
      }

      succParent->left = succ->right;

      //copy succ data to root
      strcpy(root->word,succ->word);
      strcpy(root->meaning,succ->meaning);
      succ->left = succ->right = NULL;
      delete succ;
      root->right = deleteKeyword(succ->word,root->right);
      return root;
    }
    return NULL;
  }

  void copyR(BTree *t) {
    root = copyR(t->root);
  }

  TreeNode* copyR(TreeNode* root) {
    TreeNode *temp = NULL;
    if(root != NULL) {
      temp = new TreeNode;
      temp->left = temp->right = NULL;
      strcpy(temp->word,root->word);
      strcpy(temp->meaning,root->meaning);
      temp->left = copyR(root->left);
      temp->right = copyR(root->right);
    }
    return temp;
  }
};

int main() {
  BTree *BST, *BST2;
  TreeNode *newNode, *temp1, *temp2, *temp;
  int choice;

  do {
    cout<<"\n What? 1.Create 2.Display 3.Insert 4.Delete 5.Mirror 6.Copy- ";
    cin>>choice;
    switch (choice) {
    case 1:
      BST = new BTree;
      BST->createBTree();
      break;
    case 2:
      BST->displayBTreeBFS(); break;
    case 3:
      newNode = new TreeNode;
      cout<<"\n Enter new node to insert";
      cin>>newNode->word>>newNode->meaning;
      BST->insertNode(newNode); break;
    case 4:
      temp1 = new TreeNode;
      char a[10];
      cout<<"\n Enter value to delete-";
      cin>>a;
      temp1 = BST->deleteKeyword(a);
      break;
    case 5:
      BST->mirrorR();
      break;
    case 6:
      BST2= new BTree;
      BST2->copyR(BST);
      BST2->displayBTreeBFS();
      break;
    }

  }while(choice <= 6);
  return 0;
}