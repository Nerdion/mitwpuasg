
#include <iostream>
using namespace std;
class Node;
class Polynomial;

class Node {
public :
	int coeff;
	int exp;
	Node *next;
	friend class Polynomial;
};

class Polynomial {
	Node *head;
public:
	void createPolynomial() {
		char yn;
		head->next = head;
		Node *curr;
		Node *temp;

		temp = head;

		do {
			curr = new Node;

			cout<<"\n\t Enter coefficient and exponent - \n";
			cin>>curr->coeff;
			cin>>curr->exp;


 			curr->next = head;
			temp->next = curr;
			temp = curr;

			cout<<"Do you want to add more ? y/1 or n";
			cin>>yn;
		}while(yn == 'y' || yn == '1');

	}

	void displayPolynomial() {
		Node *pointerToNode;
		pointerToNode = new Node;
		pointerToNode = head->next;

		cout<<"\n\t";
		while(pointerToNode != head) {
			cout<< pointerToNode->coeff;
			cout<<"x^" << pointerToNode->exp;
			pointerToNode = pointerToNode->next;

			if(pointerToNode != head) {
				cout<<" + ";
			}
		}
	}
};

int main() {
	Polynomial poly;
	poly.createPolynomial();
	poly.displayPolynomial();
	return 0;
}
