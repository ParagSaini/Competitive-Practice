#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve(string str) {
    int n = str.length();
    stack<int> st;
    st.push(-1);
    int maxi=INT_MIN, cnt = 0;
    for(int i=0;i<str.length();i++){
        char c = str[i];
        
        if(c=='('){
            st.push(i);
        }
        else{
            st.pop();
            if(st.empty()){
                st.push(i);
            }
            else{
                int len = i - st.top();
                if(len == maxi) cnt++;
                if(len > maxi) {
                    maxi = len;
                    cnt = 1;
                }
            }
        }
    }
    
    if(cnt == 0) cout<<0<<" "<<1<<endl;
    else cout<<maxi<<" "<<cnt<<endl;
}
int main() {
    int t;
    t=1;
    // cin>>t;
    while(t--) {
        string str;
        cin>>str;
        solve(str);
    }
    return 0;
}