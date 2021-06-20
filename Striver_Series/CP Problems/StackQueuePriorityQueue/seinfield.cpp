#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {

}
int main() {
    int k = 1;
    string str;
    while(cin>>str) {
        if(str[0] != '-') {
            stack<char> st;
            int op = 0;
            for(int i=0; i<str.length(); i++) {
                if(str[i] == '{') st.push(str[i]);
                else {
                    if(st.empty()) st.push(str[i]);
                    else if(st.top() == '{') st.pop();
                    else st.push(str[i]);
                }
            }
            while(!st.empty()) {
                char a = st.top();
                st.pop();
                char b = st.top();
                st.pop();
                if(a == b) op++;
                else op+=2;
            }
            cout<<k<<". "<<op<<endl;
            k++;
        } else break;
    }
    return 0;
}