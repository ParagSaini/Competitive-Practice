#include<unordered_set>
#include<iostream>
#include<queue>
#include<climits>
#include<vector>
#include<stack>
using namespace std;

stack<int> s;
void Insert(int a ) {
    if(s.empty()) {
        s.push(a);
    }
    else {
        if(s.top() <= a) {
            s.push(a);
        }
        else {
            int x = s.top();
            s.pop();
            Insert(a);
            s.push(x);
        }
    }
}
void sortStack() {
    if(!s.empty()) {
        int a = s.top();
        s.pop();
        sortStack();
        Insert(a);
    }
}
int main() {
    system("cls");
    s.push(7);
    s.push(6);
    s.push(5);
    s.push(4);
    s.push(3);
    s.push(2);
    s.push(1);
    sortStack();
    stack<int> temp= s;
    while(!temp.empty()) {
        cout<<temp.top()<<" ";
        temp.pop();
    }
    return 0;
}