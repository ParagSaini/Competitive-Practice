#include<bits/stdc++.h>
using namespace std;


// t.c O(n) && s.c O(n)
int FindMissing(vector<int>& arr) {
    int smallest_pos = INT_MAX;
    unordered_set<int> s;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] > 0 && arr[i] < smallest_pos) smallest_pos = arr[i];
        s.insert(arr[i]);
    }
    if(smallest_pos > 1 || smallest_pos == INT_MAX) return 1;
    while(s.count(smallest_pos)) {
        smallest_pos++;
    }
    return smallest_pos;
    
}