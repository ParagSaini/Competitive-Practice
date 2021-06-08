#include<bits/stdc++.h>
using namespace std; 
int main() {  
    int n;  
    cin>>n;  
    int num = (n & (~(n-1))); 
    cout<<log2(num);
    return 0;
}