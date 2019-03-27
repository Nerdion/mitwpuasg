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
        else cout<<"It's full";
    }

    TreeNode* deleteQueue() {
        if(!isEmpty()) return q[front++];
        else cout<<"Empty";
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
        int flag = 0;
        do {
           if(root == NULL) {
                root = new TreeNode;
                cout<<"\nEnter root data ";
                cout<<"Enter keyword and meaning";
                cin>>root->word>>root->meaning;
                root->left = root->right = NULL;
           } else {
                temp = root;

                cout<<"Enter new node-";
                cin>>newNode->word>>newNode->meaning;
                newNode->left=newNode->right = NULL;

                while(flag==0) {
                    if(strcmp(temp->word,newNode->word) >= 0) {
                        if(temp->left == NULL) {
                            temp->left = newNode;
                            flag=1;
                            break;
                        }
                        temp = temp->left;
                    } else if(strcmp(temp->word,newNode->word) < 0) {
                        if(temp->right == NULL) {
                            temp->right = newNode;
                            flag=1;
                            break;
                        }
                        temp = temp->right;
                    }
                }
               }
           cout<<"Want to insert more?";
           cin>>choice;

            }while(choice == 'y' || choice == 'Y');
    }

    void displayBTreeBFS() {
        Queue BFS;
        TreeNode *temp;

        temp = root;

        BFS.insertQueue(root);


        while(!BFS.isEmpty()) {
            temp = BFS.deleteQueue();

            cout<<" "<<temp->word<<temp->meaning;
            cout<<"\n";

            if(temp->left !=NULL) {
                BFS.insertQueue(temp->left);
            }

            if(temp->right !=NULL) {
                BFS.insertQueue(temp->right);
            }

        }
    }
};



int main() {
    BTree *BST;
    BST = new BTree;
    BST->createBTree();
    BST->displayBTreeBFS();

    return 0;
}
