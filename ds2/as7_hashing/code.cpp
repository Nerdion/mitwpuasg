#include<iostream>
#include<string>
#define max 10
using namespace std;

//student class
class Student {
    int rollno;
    string name;
    char grade;
    friend class Hashing;

    Student() {
        rollno = -1;
        name = "--";
        grade = '-';
    }
};

//hash class
class Hashing {
    Student h[max];
public:
    Hashing() {}
    void withoutReplacement();
    void withReplacement();
    void displayHash();
    void searchElement();
};

void Hashing::displayHash() {
    cout<<"\n Called display-";

    for(int i=0;i<max;i++) {
        cout<<"\n "<<i<<"- ";
        cout<<" "<<h[i].rollno<<" "<<h[i].name<<" "<<h[i].grade;
    }
}

void Hashing::withoutReplacement() {
    int rno,flag=0;
    char grade;
    string name;
    bool ch;

    do {
        int loc;

        cout<<"\n Enter student details-";
        cout<<"\n Enter rno";
        cin>>rno;
        cout<<"\n Enter name";
        cin>>name;
        cout<<"\n Enter grade";
        cin>>grade;

        loc = rno%max;

        if(h[loc].rollno == -1) {
            h[loc].rollno = rno;
            h[loc].name = name;
            h[loc].grade = grade;
        } else {
            int i;
            i = (loc+1)%max;
            while(i!=loc) {
                if(h[i].rollno = -1) {
                    h[i].rollno = rno;
                    h[i].name = name;
                    h[i].grade = grade;
                    flag = 1;
                    break;
                }
                i = (i+1)%max;
            }
            if(flag == 0) cout<<"\n\t Hashtable FULL!";
        }
        cout<<"\n Want to enter more? 1.Yes 0.No";
        cin>>ch;
    }while(ch);
}

void Hashing::withReplacement() {
    cout<<"\n\t With replacement";
    int rno,flag=0,newloc;
    char grade;
    string name;
    bool ch;
    Student temp;

    do {
        int loc;

        cout<<"\n Enter student details-";
        cout<<"\n Enter rno";
        cin>>rno;
        cout<<"\n Enter name";
        cin>>name;
        cout<<"\n Enter grade";
        cin>>grade;

        loc = rno%max;

        if(h[loc].rollno == -1) {
            h[loc].rollno = rno;
            h[loc].name = name;
            h[loc].grade = grade;
        } else {
            newloc=(h[loc].rollno)%max;
            temp.rollno = rno;
            temp.name = name;
            temp.grade = grade;

            if(loc != newloc) {
                temp.rollno = h[loc].rollno;
                temp.name = h[loc].name;
                temp.grade = h[loc].grade;

                h[loc].rollno = rno;
                h[loc].name = name;
                h[loc].grade = grade;
            }

            int i;
            i = (loc+1)%max;

            while(i!=loc) {
                if(h[i].rollno == -1) {
                    h[i].rollno = temp.rollno;
                    h[i].name = temp.name;
                    h[i].grade = temp.grade;
                    flag=1;
                    break;
                }
                i=(i+1)%max;
            }
            if(flag==0) cout<<"Table full";
        }
        cout<<"\n Want to enter more? 1.Yes 0.No";
        cin>>ch;
    }while(ch);
}

void Hashing::searchElement() {
    int rno,i,loc;
    int flag=0;

    cout<<"\n Enter location to search";
    cin>>rno;

    loc = (rno)%max;

    if(h[loc].rollno == rno) {
        flag=1;
        i=loc;
    } else {
        i = (loc+1)%max;
        while(i!=loc) {
            if(h[i].rollno == rno) {
                flag=1;
                break;
            }
            i = (i+1)%max;
        }
    }

    if(flag) cout<<"\n Found at- "<<i<<"\n";
    else cout<<"\n Not found\n";
}

int main() {
    Hashing hashing;
    int choice;

    do {
        cout<<"What you want to do? 1.Display 2.WithoutReplacement 3.WithReplacement 4.Search";
        cin>>choice;
        switch(choice) {
        case 1: hashing.displayHash(); break;
        case 2: hashing.withoutReplacement(); break;
        case 3: hashing.withReplacement(); break;
        case 4: hashing.searchElement(); break;
        }
    }while(choice <=4);

    return 0;
}
