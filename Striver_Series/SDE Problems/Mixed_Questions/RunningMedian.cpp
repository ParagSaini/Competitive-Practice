#include<bits/stdc++.h>
using namespace std;

// Using two heaps approach, t.c O(lg(n)) & O(1) for insertion and getMedian function
// idea if we divide a sorted array in two half, it will create a two heaps like structure max_heap and min_heap, we have use that key idea.
class MedianFinder {
public:
    /** initialize your data structure here. */
    priority_queue<int> max_heap;
    priority_queue<int, vector<int>, greater<int>> min_heap;
    MedianFinder() {
        
    }
    void BalanceHeap() {
        int diff = max_heap.size() - min_heap.size();
        if(abs(diff) > 1) {
            if(max_heap.size() > min_heap.size()) {
                int val = max_heap.top();
                max_heap.pop();
                min_heap.push(val);
            }
            else {
                int val = min_heap.top();
                min_heap.pop();
                max_heap.push(val);
            }
        }
    }
    void addNum(int num) {
        if(max_heap.size() == 0) max_heap.push(num);
        else {
            int val = max_heap.top();
            if(num > val) min_heap.push(num);
            else max_heap.push(num);
            BalanceHeap();
        }
    }
    
    double findMedian() {
        if(min_heap.size() == max_heap.size()) return ((min_heap.top() + max_heap.top())/2.0 );
        if(max_heap.size() > min_heap.size()) return max_heap.top();
        return min_heap.top();
    }
};


// USING MULTISET APPROACH

class MedianFinder {
public:
    /** initialize your data structure here. */
    multiset<int> data;
    multiset<int>::iterator lo_median, hi_median;
    MedianFinder() {
        
    }
    
    void addNum(int num) {
        const size_t size = data.size();        // contains the prev_size
        data.insert(num);
        
        if(size == 0) {
            lo_median = data.begin();
            hi_median = data.begin();
        }
        // even size
        else if(size % 2 == 0) {
            if(num > *lo_median && num < *hi_median) {
                lo_median++;
                hi_median--;
            }
             // if numbers are duplicate the latest number is insert at the end, then do accordingly
            else if(num >= *hi_median) {
                // handling the case when both the two pointer have same value and the inserted value is also the same, ex before adding 3 3 , and we have to add 3 
                lo_median++;
            } else {
                lo_median = --hi_median;
   
            }
        }
        // odd size
        else {
            if(num >= *lo_median ) {
                hi_median++;
            }
            else {
                lo_median--;
            } 
        }
        
    }
    
    double findMedian() {
        return ((double)(*lo_median + *hi_median)/2.0);
    }
};
