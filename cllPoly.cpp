
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
		Node *curr3 = this->head;
		Node *temp;

		while(curr1->exp != -1 || curr2->exp != -1) {

			temp = new Node;

			if(curr1->exp == curr2->exp) {
				temp->exp = curr1->exp;
				temp->coeff = curr1->exp + curr2->exp;

				curr1 = curr1->next;
				curr2 = curr2->next;
				curr3->next = temp;
				curr3 = temp;
			} else if(curr1->exp > curr2->exp) {
				curr3->exp = curr1->exp;
				curr3->coeff = curr1->coeff;

				curr1 = curr1->next;
				curr3 = curr3->next;			
			} else if(curr1->exp < curr2->exp){
				curr3->exp = curr2->exp;
				curr3->coeff = curr2->coeff;
				
				curr2 = curr2->next;
				curr3 = curr3->next;
			}
		}

		if(curr1 == p1.head) {
			while(curr2 != p2.head) {
				curr3->exp = curr2->exp;
				curr3->coeff = curr2->coeff;
				
				curr2 = curr2->next;
				curr3 = curr3->next;
			}
		}

		if(curr2 == p2.head) {
			while(curr1 != p1.head) {
				curr3->exp = curr1->exp;
				curr3->coeff = curr1->coeff;

				curr1 = curr1->next;
				curr3 = curr3->next;
			}
		}
	}

};

int main() {
	int x,evaluatedPolynomial;
	Polynomial poly;
	Polynomial poly2;
	Polynomial addedPolynomial;

	cout<<"\n Poly1 \n\t";
	poly.createPolynomial();
	poly.displayPolynomial();

	cout<<"\n Poly2 \n\t";
	poly2.createPolynomial();
	poly2.displayPolynomial();

	/*
	cout<<"\n\t Enter exponent value";
	cin>>x;	
	evaluatedPolynomial = poly.evaluatePolynomial(x);
	cout<<"\n\t"<<evaluatedPolynomial;
	*/
	
	addedPolynomial.addPolynomials(poly,poly2);
	addedPolynomial.displayPolynomial();
	
	return 0;
}
