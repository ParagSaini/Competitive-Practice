#include <bits/stdc++.h> 
using namespace std; 
  
// function to count the number of  
// unique triplets whose xor is 0 
int countTriplets(int a[], int n)  
{ 
    // To store values that are present 
    unordered_set<int> s; 
    for (int i = 0; i < n; i++) 
        s.insert(a[i]); 
      
    // stores the count of unique triplets 
    int count = 0; 
      
    // traverse for all i, j pairs such that j>i 
    for (int i = 0; i < n; i++) { 
        for (int j = i + 1; j < n; j++) { 
  
          int xr = a[i] ^ a[j]; 
      
          // if xr of two numbers is present,  
          // then increase the count 
          if (s.find(xr) != s.end() && xr != a[i] && xr != a[j]) 
            {
                count++; 
                cout<<a[i]<<" "<<a[j]<<endl;
            }
        } 
    } 
      
    return count/3; 
} 
// Both method are correct but yet different approaches used
int count(int a[], int n) {
    unordered_set<int> s;
    int count = 0;
    for(int i=0; i<n-1; i++) {
        for(int j=i+1; j<n; j++) {
            int xr = a[j] ^ a[i];
            if(s.count(xr) && xr != a[i] && xr != a[j]){
                count++;
            }
        }
        s.insert(a[i]);
    }
    cout<<count;
    return count;
}  
// Driver code to test above function 
int main()  
{ 
    system("cls");
    int a[] = {4, 7, 5, 8, 3, 9}; 
    int n = sizeof(a) / sizeof(a[0]);    
    count(a, n);     
    return 0; 
}