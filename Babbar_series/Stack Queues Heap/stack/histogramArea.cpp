// #include<unordered_set>
#include<iostream>
#include<algorithm>
// #include<queue>
// #include<climits>
#include<vector>
#include<stack>
using namespace std;

void FindMax(vector<long long> ar ) {
    if(ar.size() == 1) {
       cout<<ar[0];
    }
    
    stack<long long> ht;
    stack<int> id;
    
    long long maxArea = ar[0];
    int i;
    for(i=0; i<ar.size(); i++ ) {
        if(ht.empty()) {
            ht.push(ar[i]);
            id.push(i);
        }
        else {
            if(ar[i] < ht.top()) {
                while(!ht.empty() && ar[i] < ht.top()) {
                    long long h = ht.top();
                    int index = id.top();
                    ht.pop();
                    
                    long long area = (i-index) * h;
                    if(area > maxArea) {
                        maxArea = area;
                    }
                    if(!ht.empty()) {
                        if(ar[i] < ht.top()) {
                           id.pop(); 
                        }
                    }
                }
                ht.push(ar[i]);
            }
            else {
                ht.push(ar[i]);
                id.push(i);
            }
        }
    }
    while(!ht.empty()) {
        long h = ht.top();
        int index = id.top();
        ht.pop();
        long area = (i-index) * h;
        if(area > maxArea) {
            maxArea = area;
        }
        id.pop();
    }
    cout<<maxArea<<endl;
}

int main() {
    system("cls");
    vector<long long> x = {6,2,5,4,5,1,6};
    FindMax(x);
    return 0;
}