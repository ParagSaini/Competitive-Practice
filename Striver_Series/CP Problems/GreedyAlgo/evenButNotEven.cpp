#include<bits/stdc++.h>
using namespace std;
void checkNumber(string str) {
    int n = str.length();
    vector<int> odds;
    for(int i=0; i<n; i++) {
        if(odds.size() == 2) break;
        if((str[i] - 48) % 2) odds.push_back(str[i] - 48);
    }
    if(odds.size() == 2) cout<<odds[0]<<odds[1]<<endl;
    else cout<<-1<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string str;
        cin>>str;
        checkNumber(str);
    }
    return 0;
}