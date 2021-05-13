#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<set>
using namespace std;
int sizeSubSet(int a[], int k, int n) 
{ 
    sort(a, a + n); 
  
    // Set to store the contents of the required sub-set 
    unordered_set<int> s; 
  
    // Insert the elements satisfying the conditions 
    for (int i = 0; i < n; i++) { 
        // before checking the a[i] /k in the set, check a[i] % k must be != 0
        if (a[i] % k != 0 || s.count(a[i] / k) == 0) 
            s.insert(a[i]); 
    } 
    for(auto i : s) cout<<i<<" ";
    // Return the size of the set 
    return s.size(); 
}
int main() {
    system("cls");
    int ar[] = {1,2,3,4,5,6,7,8,9,10};
    int n = sizeof(ar)/sizeof(int);
    int k = 2;
    cout<<sizeSubSet(ar, k, n);
    return 0;
}