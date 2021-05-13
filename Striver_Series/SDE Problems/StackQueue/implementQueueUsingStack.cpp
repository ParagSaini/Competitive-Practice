#include<bits/stdc++.h>
using namespace std;

// t.c - O(1) per operation, O(n) amortized running time for n operations of pop(), s.c O(2n)
class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> FrontQ;        // contains the first element of queue on top always
    stack<int> St;        // used for normally pushing elements of the queue
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        if(FrontQ.empty()) FrontQ.push(x);
        else St.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int ans = FrontQ.top();
        FrontQ.pop();
        if(FrontQ.empty()) {
            while(!St.empty()) {
                FrontQ.push(St.top());
                St.pop();
            }
        }
        return ans;
        
    }
    
    /** Get the front element. */
    int peek() {
        return FrontQ.top();
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        if(St.empty() && FrontQ.empty()) return true;
        return false;
    }
};


// t.c - O(n) per operation of pop() && peek, O(n2) running time for n operation, s.c O(n)- USING ONLY ONE STACK

class MyQueue {
public:
    /** Initialize your data structure here. */
    stack<int> st;
    MyQueue() {
        
    }
    
    /** Push element x to the back of queue. */
    void push(int x) {
        st.push(x);
    }
    
    /** Removes the element from in front of queue and returns that element. */
    int pop() {
        int x = st.top(); 
        st.pop(); 
  
        if (st.empty()) 
            return x; 
  
        // recursive call
        int item = pop(); 
  
        // push popped item back to the stack 
        st.push(x); 
  
        // return the result of deQueue() call 
        return item; 
        
    }
    
    /** Get the front element. */
    int peek() {  
        int x = st.top(); 
        st.pop(); 
  
        if (st.empty()){
            st.push(x);
            return x;
        }
         
  
        // recursive call
        int item = peek(); 
  
        // push popped item back to the stack 
        st.push(x); 
  
        // return the result of deQueue() call 
        return item;
    }
    
    /** Returns whether the queue is empty. */
    bool empty() {
        return st.empty();
    }
};