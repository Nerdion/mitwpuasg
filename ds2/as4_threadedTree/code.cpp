#include<iostream>
using namespace std;

class tTreeNode {
  bool lbit, rbit;
  tTreeNode *left, *right;
  int data;
  friend class ThreadedTree;
};


class ThreadedTree {
  tTreeNode* head;
public:
  ThreadedTree() {
    head = new tTreeNode;
    head->rbit = 1;
    head->lbit = 0;
    head->right = head->left = head;
  }

  void createThreadedTree() {
    tTreeNode *root,*temp,*curr;
    char side;
    int more;

    root = new tTreeNode;
    cout<<"\n Enter root data";
    cin>>root->data;
    head->lbit = 1;
    head->left = root;  
    root->left = root->right = head;
    root->lbit = root->rbit = 0;

    do {
      bool flag = 1;
      curr = new tTreeNode;
      temp = root;
      cout<<"\n Enter data- ";
      cin>>curr->data;

      while(flag) {
        cout<<"Where u want to inset? l or r";
        cin>>side;
        curr->lbit = curr->rbit = 0;

        if(side = 'l') {
          if(temp->lbit == 0) {
            curr->left = temp->left;
            temp->left = curr;
            temp->lbit = 1;
            flag = 0;
          }
          temp = temp->left;
        } else if(side = 'r') {
          if(temp->rbit == 0) {
            curr->right = temp->right;
            temp->right = curr;
            temp->rbit = 1;
            flag = 0;
          }
          temp = temp->right;
        }
      }

      cout<<"Want to insert more? 1.Yes 0.No";
      cin>>more;
    } while(more);
  }

  tTreeNode* insucc(tTreeNode *temp) {
    tTreeNode *x;
    x = new tTreeNode;
    x = temp->right;
    if(temp->rbit == 1) {
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
    ThreadedTree t;
    t.createThreadedTree();
    t.inorderTraversal();
    return 0;
}

