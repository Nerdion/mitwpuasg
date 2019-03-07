#include <iostream>
#include <math.h>
using namespace std;
class Node;
class Polynomial;


// Creation of node structure using class
class Node {
public :
	int coeff;
	int exp;
	Node *next;
	friend class Polynomial;

	void displayNode(Node n) {
		cout<<"\n\t";
		cout<<n.coeff<<" "<<n.exp<<" "<<n.next;
	}
};


// Class for actual polynomial connected with Node
class Polynomial {
		Node *head;

public:

	Polynomial() {
		head = new Node();
		head->coeff = 0;
		head->exp = -1;
		head->next = head;
	}
	//function for creation of polynomial
	void createPolynomial() {
		char yn;
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

	//displaying
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
		cout<<"\n";
	}

	//function for evaluation of polynomial
	int evaluatePolynomial(int x) {
		int evaluation = 0, powered;

		Node *current = head->next;

		do {
			powered = pow(x, current->exp);
			evaluation = evaluation + (current->coeff * powered);
			current = current->next;
		}while(current!=head);

		return evaluation;
	}

	//function for adding 2 polynomials given in parameter
	void addPolynomials(Polynomial p1, Polynomial p2) {
		Node *curr1 = p1.head->next;
		Node *curr2 = p2.head->next;
		Node *curr3 = head;
		Node *temp;

		while(curr1->exp != -1 || curr2->exp != -1) {
			temp = new Node;
			if(curr1->exp == curr2->exp) {
				temp->exp = curr1->exp;
				temp->coeff = curr1->exp + curr2->exp;
				curr1 = curr1->next;
				curr2 = curr2->next;

			} else if(curr1->exp > curr2->exp) {

				temp->exp = curr1->exp;
				temp->coeff = curr1->coeff;
				curr1 = curr1->next;

			} else if(curr1->exp < curr2->exp){

				temp->exp = curr2->exp;
				temp->coeff = curr2->coeff;
				curr2 = curr2->next;

			}

			curr3->next = temp;
			curr3 = temp;
			curr3->next = head;
		}

		if(curr1->exp == -1) {
			while(curr2 != p2.head) {
				temp = new Node;
				temp->exp = curr2->exp;
				temp->coeff = curr2->coeff;

				curr2 = curr2->next;
				curr3->next = temp;
				curr3 = temp;
				curr3->next = head;
			}
		}

		if(curr2->exp == -1) {
			while(curr1 != p1.head) {
				temp->exp = curr1->exp;
				temp->coeff = curr1->coeff;

				curr1 = curr1->next;
				curr3->next = temp;
				curr3 = temp;
				curr3->next = head;
			}
		}

	}


};

int main() {
	int choice=0,x,evaluatedPolynomial;
	Polynomial poly, poly1, poly2, addedPolynomial;

	do {
		cout<<"What you want? 1.createPolynomial 2.displayPolynomial 3.evaluatePolynomial 4.addPolynomials 5.exit";
		cin>>choice;

		switch (choice) {
			case 1:
				poly.createPolynomial();
				break;

			case 2:
				poly.displayPolynomial();
				break;

			case 3:
				cout<<"\n\t Enter exponent value";
				cin>>x;
				evaluatedPolynomial = poly.evaluatePolynomial(x);
				cout<<"\n\t"<<evaluatedPolynomial<<"\n";
				break;

			case 4:
				cout<<"\n Poly1 \n\t";
				poly.createPolynomial();

				cout<<"\t You entered 1-";
				poly.displayPolynomial();

				cout<<"\n Poly2 \n\t";
				poly2.createPolynomial();

				cout<<"\t You entered 2-";
				poly2.displayPolynomial();

				addedPolynomial.addPolynomials(poly,poly2);
				cout<<"Displaying the added polynomial-";
				addedPolynomial.displayPolynomial();
				break;

			case 5:
				cout<<"Exit Time? Bye.... :)";
				break;

		}

	}while(choice < 5);

	return 0;
}
