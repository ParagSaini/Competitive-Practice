#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

// without stack, greedy approach
// string solve(string str) {
//     int n = str.length();
//     if(str[0] == '0') return "NO";
//     for(int i=2; i<n; i++) {
//         if(str[i] == '0') {
//             if(str[i-1] != '*' && str[i-2] != '*') return "NO";
//         }
//     }
//     return "YES";
// }

// using the stack
string solve(string str) {
    int n = str.length();
    stack<char> st;
    for(int i=n-1; i>=0; i--) {
        if(str[i] == '0') st.push('0');
        else {
            for(int i=0; i<2 && !st.empty(); i++) {
                st.pop();
            }
            if(!st.empty()) return "NO";
        }
    }
    if(st.empty()) return "YES";
    return "NO";
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        string str;
        cin>>str;
        cout<<solve(str)<<endl;
    }
    return 0;
}