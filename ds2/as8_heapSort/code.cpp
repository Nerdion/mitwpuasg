#include<iostream>
#define max 10
using namespace std;

class Student {
	int marks;
	string name;
	friend class Heap;
};

class Heap {
public:
	Student arr[max];
	int n,minmax;
	void createHeap();
	void display();
	void insertHeap(int);
	void extractMinMax(int);
};

void Heap::createHeap() {
	Student s;
	int ch;
	cout<<"\n Enter total no. of students";
	cin>>n;

	cout<<"\n Press 0 for minheap & 1 for maxheap";
	cin>>minmax;

	for(int i=1;i<=n;i++) {
		cout<<"\n Enter info ";
		cin>>s.name;
		cin>>s.marks;

		arr[i] = s;
		insertHeap(i);
	}
}

void Heap::insertHeap(int index) {
	int i = index;
	Student s = arr[index];

	if(minmax == 1) {
		while(i > 1 && (s.marks > arr[i/2].marks)) {
			arr[i] = arr[i/2];
			i = i/2;
		}
		
	} else {
		while(i > 1 && (s.marks < arr[i/2].marks)) {
			arr[i] = arr[i/2];
			i = i/2;
		}
	}
	arr[i] = s;

	
}

void Heap::display() {
	for(int i=1;i<=n;i++)
		cout<<arr[i].marks<<" ";
	cout<<"\n";
}

void Heap::extractMinMax(int minmax) {
	if(minmax == 0) {
		cout<<"Your minheap is- ";
	} else {
		cout<<"Your maxheap is- ";
	}

	for(int i=1;i<=n;i++)
		cout<<arr[i].marks<<" "<<arr[i].name<<"\t";
	cout<<"\n";
}

int main() {
	Heap h;
	h.createHeap();
	h.display();
	h.extractMinMax(h.minmax);
	return 0;
}