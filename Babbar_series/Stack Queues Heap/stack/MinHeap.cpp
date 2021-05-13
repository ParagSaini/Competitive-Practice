#include<iostream>
#include<climits>
#include<vector>
using namespace std;

vector<int> a = {INT_MIN};

void heapifyup(int ind) {
    if(ind > 1) {
        int p = ind/2;
        if(a[p] > a[ind]) {
            swap(a[p], a[ind]);
            heapifyup(p);
        }
    }
}

void insert(int d) {
    if(a.size() == 1) {
        a.push_back(d);
    }
    else {
        a.push_back(d);
        heapifyup(a.size() - 1);
    }
}

void heapifydown(int ind) {
    int right = 2*ind +1;
    int left = 2*ind;
    if(left > a.size() -1 ) return;
    if(right > a.size()-1 ) {
        if(a[left] < a[ind]) {
            swap(a[left], a[ind]);
        }
        return;
    }
    else {
        int small = a[right] > a[left] ? left : right;
        if(a[small] < a[ind]) {
            swap(a[small], a[ind]);
            heapifydown(small);
        }
    }
}

int removeMin() {
    if(a.size() == 1) {
        cout<<"underflow"<<endl;
        return -1;
    }
    int temp = a[1];
    swap(a[a.size()-1], a[1]);
    a.pop_back();
    heapifydown(1);
    return temp;
}

void print() {
    for(int i=1; i<a.size(); i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}

vector<int> r;

void makesort() {
    while(a.size() != 1) {
        r.push_back(removeMin());
    }
}

int main() {

    insert(1);
    insert(32);
    insert(5);
    insert(97); 
    insert(0);
    makesort();
    for(int i=0; i<r.size(); i++) {
        cout<<r[i]<<" ";
    }
    return 0;
}