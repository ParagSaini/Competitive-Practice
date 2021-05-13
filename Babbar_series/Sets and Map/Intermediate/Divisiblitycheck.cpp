#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<unordered_set> 
using namespace std; 
void divisibilityCheck(int arr[], int n) 
{ 
  
    unordered_set<int> s; 
    int max_ele = INT_MIN; 
    for (int i = 0; i < n; i++) { 
        s.insert(arr[i]); 
  
        max_ele = max(max_ele, arr[i]); 
    } 
  
    // Traversing the array elements and storing the array 
    // multiples that are present in s in res 
    unordered_set<int> res; 
    for (int i = 0; i < n; i++) { 
  
        // Check for non-zero values only 
        if (arr[i] != 0) { 
  
            // Checking the factors of current element 
            for (int j = arr[i] * 2; j <= max_ele; j += arr[i]) { 
  
                // If current factor is already part 
                // of the array then store it 
                if (s.find(j) != s.end()) 
                    res.insert(j); 
            } 
        } 
    } 
    // if arr has duplicate numbers use map also, for more info gfg
    cout<<"The unique numbers are : "<<endl;
    for(auto it : res) cout<<it<<" ";
}
int main()  
{ 
    system("cls");
    int arr1[] = {7,4,8};
    divisibilityCheck(arr1,3);
    return 0; 
}