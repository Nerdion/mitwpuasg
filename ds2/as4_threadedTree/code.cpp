#include<iostream>
using namespace std;

class tTreeNode {
  bool lbit, rbit;
  tTreeNode *left, *right;
  int data;
  friend class ThreadedTree;
}

class ThreadedTree {
  tTreeNode head;
public:
  ThreadedTree() {
    head->rbit = TRUE;
    head->lbit = FALSE;
    head->right = head->left = head;
  }

  void createThreadedTree() {
    tTreeNode *root,*temp,*curr;
    char side;
    int more;

    root = new tTreeNode;
    cout<<"\n Enter root data";
    cin>>root->data;
    head->lbit = TRUE;
    head->left = root;
    root->left = root->right = head;
    root->lbit = root->rbit = FALSE;

    do {
      int flag = 1;
      curr = new tTreeNode;
      temp = root;
      cout<<"\n Enter data- ";
      cin>>curr->data;

      while(flag) {
        cout<<"Where u want to inset? l or r";
        cin>>side;
        curr->lbit = curr->rbit = FALSE;

        if(side = 'l') {
          if(temp->lbit == FALSE) {
            curr->left = temp->left;
            temp->left = curr;
            temp->lbit = TRUE;
            flag = 0;
          }
          temp = temp->left;
        } else if(side = 'r') {
          if(temp->rbit == FALSE) {
            curr->right = temp->right;
            temp->right = curr;
            temp->rbit = TRUE;
            flag = 0;
          }
          temp = temp->right;
        }
      }

      cout<<"Want to insert more?";
      cin>>more;
    } while(more);
  }

  tTreeNode* insucc(tTreeNode *temp) {
    tTreeNode *x;
    x = new tTreeNode;
    x = temp->right;
    if(temp->rbit == TRUE) {
      while(x->lbit == 1) {
        x = x->left;
      }
      return x;
    }
  }

  void inorderTraversal() {
    tTreeNode *temp;
    temp = new tTreeNode;
    temp = head;

    while(1) {
      temp = insucc(temp);
      if(temp == head) break;
      cout<<temp->data;
    }
  }
};


int main(void) {

  return 0;
}
