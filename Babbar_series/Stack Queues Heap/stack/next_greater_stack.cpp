#include<unordered_set>
#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<stack>
using namespace std;
void printNext(vector<int> ar) {
    
    if(ar.size() == 0) return;
    vector<int> result(ar.size(), -1);
    stack<int> s;
    s.push(0);
    for(int i=1; i<ar.size(); i++) {
        if(ar[i] > ar[s.top()]) {
            while(!s.empty() && ar[i] > ar[s.top()] ) {
                result[s.top()] = ar[i];
                s.pop();
            }
            s.push(i);
            
        }
        else {
            s.push(i);
        }
    }
    for(auto i : result) {
        cout<<i<<" ";
    }
}
int main() {
    system("cls");
    vector<int> ar = {1,3,2,4};
    printNext(ar);
    return 0;
}