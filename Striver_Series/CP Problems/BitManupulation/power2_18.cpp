#include<bits/stdc++.h>
using namespace std; 
int main() {  
    int n;  
    cin>>n;  
    int p = pow(2,30);  
    int ans = 30;  
    while(p>0) {    
        if(n%p == 0){      
            cout<<ans<<endl;      
            break;    
        } else{      
            ans--;      
            p/=2;      
        }  
    }  
    return 0;
}