#include<bits/stdc++.h>
using namespace std;

// t.c O(n) for pop(), O(n2) for n pop() operations, but USING ONLY ONE QUEUE.
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q;
    int topEl;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q.push(x); 
        topEl = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = topEl;
        int s = q.size();
        while(s != 1) {
            q.push(q.front());
            topEl = q.front();
            q.pop();
            s--;
        }
        q.pop();
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return topEl;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return q.empty();
    }
};


// t.c pop() - O(n), O(n2) for n pop() operations
class MyStack {
public:
    /** Initialize your data structure here. */
    queue<int> q1;
    queue<int> q2;
    int topEl;
    MyStack() {
        
    }
    
    /** Push element x onto stack. */
    void push(int x) {
        q1.push(x);
        topEl = x;
    }
    
    /** Removes the element on top of the stack and returns that element. */
    int pop() {
        int ans = topEl;
        int s = q1.size();
        while(s != 1) {
            q2.push(q1.front());
            topEl = q1.front();
            q1.pop();
            s--;
        }
        q1.pop();
        while(!q2.empty()) {
            q1.push(q2.front());
            q2.pop();
        }
        return ans;
    }
    
    /** Get the top element. */
    int top() {
        return topEl;
    }
    
    /** Returns whether the stack is empty. */
    bool empty() {
        return (q1.empty() && q2.empty());
    }
};