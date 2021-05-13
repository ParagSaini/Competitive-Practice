#include<bits/stdc++.h>
using namespace std;
 
int main() {
    int t;
    cin>>t;
    unordered_map<string, int> m;
    for(int i=0; i<t; i++) {
        string s;
        cin>>s;
        if(m.count(s)) {
            cout<<s<<m[s]<<endl;
            m[s]++;
        }else {
            cout<<"OK"<<endl;
            m[s] = 1;
        }
    }
    return 0;
}