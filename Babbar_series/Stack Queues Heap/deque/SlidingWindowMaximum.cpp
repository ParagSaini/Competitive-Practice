#include<bits/stdc++.h>
using namespace std;

void printMax(vector<int> ar, int k) {
    deque<int> dq;
    // initialising the deque for first k elements.
    for(int i=0; i<k; i++) {
        if(dq.empty()) {
            dq.push_back(ar[i]);
        }
        else {
            while(!dq.empty() && dq.back() < ar[i]) {
                dq.pop_back();
            }
            dq.push_back(ar[i]);
        }
    }
    // traversing the array
    // i < ar.size() - k not i <=ar.size() -k , for not getting segmentation fault in ar[i+k]
    for(int i=0; i<(ar.size()-k); i++) {
        cout<<dq.front()<<" ";
        if(ar[i] == dq.front()) {
            dq.pop_front();
        }
        while(!dq.empty() && dq.back() < ar[i+k]) {
            dq.pop_back();
        }
        dq.push_back(ar[i+k]);
    }
    cout<<dq.front()<<" ";
    
}
void printMin(vector<int> ar, int k) {
    deque<int> dq;
    // initialising the deque for first k elements.
    for(int i=0; i<k; i++) {
        if(dq.empty()) {
            dq.push_back(ar[i]);
        }
        else {
            while(!dq.empty() && dq.back() > ar[i]) {
                dq.pop_back();
            }
            dq.push_back(ar[i]);
        }
    }
    // traversing the array
    for(int i=0; i<(ar.size()-k); i++) {
        cout<<dq.front()<<" ";
        if(ar[i] == dq.front()) {
            dq.pop_front();
        }
        while(!dq.empty() && dq.back() > ar[i+k]) {
            dq.pop_back();
        }
        dq.push_back(ar[i+k]);
    }
    cout<<dq.front()<<" ";
    
}


// Merge both the above code.
int SumMinMax(vector<int> ar, int k) {
    int sum = 0;
    deque<int> dqMax;
    deque<int> dqMin;
    // initialising the deque for first k elements.
    for(int i=0; i<k; i++) {
        if(dqMin.empty()) {
            dqMax.push_back(ar[i]);
            dqMin.push_back(ar[i]);
        }
        else {
            while(!dqMin.empty() && dqMin.back() > ar[i]) {
                dqMin.pop_back();
            }
            while(!dqMax.empty() && dqMax.back() < ar[i]) {
                dqMax.pop_back();
            }
            dqMax.push_back(ar[i]);
            dqMin.push_back(ar[i]);
        }
    }
    // traversing the array
    for(int i=0; i<(ar.size()-k); i++) {
        sum += (dqMax.front() + dqMin.front());
        if(ar[i] == dqMax.front()) {
            dqMax.pop_front();
        }
        if(ar[i] == dqMin.front()) {
            dqMin.pop_front();
        }
        while(!dqMin.empty() && dqMin.back() > ar[i+k]) {
            dqMin.pop_back();
        }
        while(!dqMax.empty() && dqMax.back() < ar[i+k]) {
            dqMax.pop_back();
        }
        dqMax.push_back(ar[i+k]);
        dqMin.push_back(ar[i+k]);
    }
    sum += dqMax.front() + dqMin.front();
    return sum;
}
int main() {
    vector<int> ar = {2,5,-1,7,-3,-1,2};
    int k = 4;
    cout<<SumMinMax(ar, k);
    return 0;
}