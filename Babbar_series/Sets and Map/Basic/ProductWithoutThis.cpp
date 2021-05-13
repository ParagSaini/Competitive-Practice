#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<unordered_set>
#include<set>
using namespace std;
// Time O(n), specifically O(2n), space O(1);
string isPresentNumber(vector<long long> x) {
    long long TotalProduct = 1;
    for(int i=0; i<x.size(); i++) {
        TotalProduct = TotalProduct * x[i];
    }
    for(int i=0; i<x.size(); i++) {
        long long ProductWithoutThis = TotalProduct / x[i];
        if(x[i] == ProductWithoutThis) return "Yes";
    }
    return "No";
}
// another method for the same, requires set.     Time = O(n) , space O(n)
string CheckArray(vector<long long> arr) 
{ 
    int prod = 1; 
    unordered_set<int> Numbers; 
  
    // Calculate the product of all the elements 
    for (int i = 0; i < arr.size(); ++i) { 
        Numbers.insert(arr[i]); 
        prod *= arr[i]; 
    } 
  
    int root = sqrt(prod); 
  
    // If the prod is a perfect square 
    if (root * root == prod) 
  
        // then check if its square root 
        // exist in the array or not 
        if (Numbers.find(root) != Numbers.end()) 
            return "Yes"; 
  
    return "No"; 
} 
int main() {
    system("cls");
    vector<long long> x = {1,2,3};
    cout<<isPresentNumber(x);
    cout<<CheckArray(x);
    return 0;
}