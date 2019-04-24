#include<iostream>
#define infi 9999
using namespace std;

class Prims {
    int cost[20][20];

public:
    Prims() {
    }

    Prims(int n) {
        for(int i=0;i<n;i++) {
            for(int j=i+1;i<n;i++) {
                cost[i][j] = cost[j][i] = infi;
            }
        }
    }

    void create(int);
    void primsFunction(int);
};

void Prims::create(int n) {
    int opt;

    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            cout<<"\n Press 1. if there is connection in "<<i<<" "<<j;
            cin>>opt;

            if(opt == 1) {
                cout<<"\n Then enter cost in place of "<<cost[i][j];
                cin>>cost[i][j];
                cost[i][j] = cost[j][i];
            }
        }
    }
}

void Prims::primsFunction(int n) {
    int min,near[20],k,t[20][20],mincost=0,m;

    cout<<"\n Enter starting vertex- ";
    cin>>k;

    near[k] = -1;

    for(int i=0;i<n;i++) {
        if(i!=k) {
            near[i] = k;
        }
    }

    for(int i=0;i<n-1;i++) {
        min = infi;

        for(int j=0;j<n;j++) {
            if(near[j]!=-1) {
                if(cost[j][near[j]] < min) {
                    min = cost[j][near[j]];
                    k=j;
                }
            }

            cout<<"\n Next office"<<k;
        }
    }
}

int main() {

}
