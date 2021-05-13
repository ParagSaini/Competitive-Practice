#include<bits/stdc++.h>
using namespace std;
vector<int> deno = {1,2,5,10, 20, 50, 100, 500, 1000};
void findMin(int V) 
{ 
    // Initialize result 
    vector<int> ans; 
    int n = deno.size();
    // Traverse through all denomination 
    for (int i = n - 1; i >= 0; i--) { 
  
        // Find denominations 
        while (V >= deno[i]) { 
            V -= deno[i]; 
            ans.push_back(deno[i]); 
        } 
    } 
  
    // Print result 
    for (int i = 0; i < ans.size(); i++) 
        cout << ans[i] << " "; 
} 
int main() {
    long long n = 2132;
    findMin(n);
    return 0;
}