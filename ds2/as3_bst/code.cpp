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
    q.insertQueue(NULL);
    while(!q.isEmpty()) {
      temp = q.deleteQueue();

      if(temp == NULL) {
        cout<<"\n";
        if(q.returnFront() != NULL)
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

  void insertNode(TreeNode* val) {
    if(root == NULL) {
      root = val;
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

  TreeNode* mirrorR() {
    TreeNode *temp = root;
    TreeNode *newRoot = new TreeNode;
    newRoot = mirrorR(temp);
    return newRoot;
  }

  TreeNode* mirrorR(TreeNode *temp) {

    if(temp != NULL) {
      TreeNode* newNode = new TreeNode;
      strcpy(newNode->word,temp->word);
      strcpy(newNode->meaning, temp->meaning);
      newNode->left = mirrorR(temp->right);
      newNode->right = mirrorR(temp->left);
      return newNode;

    } else {
      return NULL;
    }
  }

  TreeNode* searchElement(string key) {
    TreeNode* temp = new TreeNode;
    temp = searchElement(key, root);
    return temp;
  }

  TreeNode* searchElement(string key, TreeNode *root) {
    if(root->word == key) {
      return root;
    } else {
      if(root->left != NULL) {
        return searchElement(key,root->left);
      } else if(root->right != NULL){
        return searchElement(key,root->right);
      } else {
        return NULL;
      }
    }
  }

  TreeNode* minValue(TreeNode *root) {
    TreeNode* temp = root;
    while(temp->left != NULL) {
      temp = temp->left;
    }
    return temp;
  }

  TreeNode* deleteKeyword(string key) {
    return deleteKeyword(key, root);
  }

  TreeNode* deleteKeyword(string key, TreeNode* root) {
    if(root == NULL) return root;

    if(key < root->word) {
      root->left = deleteKeyword(key,root->left);
    } else if(key > root->word) {
      root->right = deleteKeyword(key, root->right);
    } else {
      if(root->left == NULL) {
        TreeNode* temp = root->right;
        delete root;
        return temp;
      } else if(root->right == NULL) {
        TreeNode* temp = root->left;
        delete root;
        return temp;
      }

      TreeNode* temp = minValue(root->right);

      strcpy(root->word,temp->word);

      root->right = deleteKeyword(key, root->right);
    }
    return root;
  }
};

int main() {
  BTree *BST;
  BST = new BTree;

  BST->createBTree();
  BST->displayBTreeBFS();
  BST->deleteKeyword("b");
  BST->displayBTreeBFS();
  return 0;
}
