#include<bits/stdc++.h>
using namespace std;

/* THINK ABOUT THE EDGE CASES WHENEVER USES THESE LIBRARY FUNCTION, LIKE WHAT THE INDEX IS OUT OF BOUND OF ARRAY AND LIKE THAT.
WHAT LEARNT:
1. binary_search()
2. lower_bound()
3. upper_bound()
*/
int main() {
    int a[] = {1,4,5,6,9,9};
    vector<int> av =  {1,4,5,6,9,9};
    int n = sizeof(a)/sizeof(int);
    bool x = binary_search(a, a+n, 4);
    bool y = binary_search(av.begin(), av.end(), 9);
    cout<<y<<" "<<x<<endl;

    // lower_bound returns the address of the element equal to the given val or just greater than the given val if val is not present. 
    // lower_bound - a gives the index of the element.
    // if the given key is greater than maxVal in the array, then it points to the just next address block, with garbage value and index of n.
    // if there are duplicate key present in the array it will give the address of element with smallest index.
    // logn time complexity
    int l1 = lower_bound(a, a+n, 4) - a;  
    int l2 = *lower_bound(a, a+n, 7);  
    int l3 = lower_bound(a, a+n, 10) - a;  
    int l4 = lower_bound(a, a+n, 9) - a; // returns the first occurence of that element
    cout<<l1<<" "<<l2<<" "<<l3<<" "<<l4<<endl;
    int lv = lower_bound(av.begin(), av.end(), 2) - av.begin();
    cout<<lv<<endl;

    // the upper bound works in O(log(n)), it always return the pointer pointing to the just next greater element, it never point to the given val element if it exists or not in the array.
    int u1 = upper_bound(a, a+n, 4) - a;  // returns the index of '5' i.e 2, 
    int u2 = upper_bound(a, a+n, 7) - a;  
    int u3 = upper_bound(a, a+n, 10) - a;  
    int u4 = upper_bound(a, a+n, 9) - a;  // return index = n, no greater element than the '9'.
    cout<<u1<<" "<<u2<<" "<<u3<<" "<<u4<<endl;

     
    return 0;
}