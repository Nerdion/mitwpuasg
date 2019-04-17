#include<iostream>
using namespace std;

class tTreeNode {
  int data;
  bool lbit, rbit;
  tTreeNode *left, *right;
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
      temp = root;
      bool flag = 1;
      curr = new tTreeNode;
      cout<<"\n Enter data- ";
      cin>>curr->data;
      curr->lbit = curr->rbit = 0;

      while(flag) {
        cout<<"Where u want to inset? l or r";
        cin>>side;

        if(side == 'l') {
          if(temp->lbit == 0) {
            curr->left = temp->left;
            temp->lbit = 1;
            temp->left = curr;
            flag = 0;
          }
          temp = temp->left;
        } else if(side == 'r') {
          if(temp->rbit == 0) {
            curr->right = temp->right;
            temp->rbit = 1;
            temp->right = curr;
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
    tTreeNode *x = new tTreeNode;
    if(temp == NULL) return NULL;

    while(temp->lbit == 1) {
      temp = temp->left;
    }

    return temp;
  }

  void inorderTraversal() {
    tTreeNode *temp;
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
