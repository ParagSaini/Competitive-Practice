#include<bits/stdc++.h>
using namespace std;

// NEVER USE THE POSAB.SIZE()-1,-2, BECAUSE VECTOR::SIZE() GIVES SIZE_T(UNSIGNED INTEGRAL TYPE), IF WE SUBSTRACT SOMETHING FROM THIS, WE CAN GET UNKNOWN OR WIERD OUTPUT, LIKE IF arr = {}, and we do arr.size()-1, it will give UINT_MAX value. So be careful while using any container size.

void minLettersSwap(string s, string t) {
    int n = s.length();
    vector<int> posAb, posBa;
    vector<pair<int, int>> ans;
    for(int i=0; i<n; i++) {
        if(s[i] != t[i]) {
            if(s[i] == 'a') posAb.push_back(i);
            else posBa.push_back(i);
        }
    }

    if( (posAb.size() + posBa.size()) % 2 != 0) {     // the number of 'a' and 'b' should be even.
        cout<<-1<<endl;
        return;
    }
    
    for(int i=0; i+2 <= posAb.size(); i+=2) {
        ans.push_back(make_pair(posAb[i], posAb[i+1]));
    }

    for(int i=0; i+2 <= posBa.size(); i+=2) {
        ans.push_back(make_pair(posBa[i], posBa[i+1]));
    }
    if(posAb.size() % 2 != 0) {           // the only way this will run, is when posAb.size() == odd && posBa.size() == odd. we need only two operation to make them equal.
        int x = posAb[posAb.size()-1];
        int y = posBa[posBa.size()-1];
        ans.push_back(make_pair(y,y));
        ans.push_back(make_pair(x,y));
    }

    cout<<ans.size()<<endl;
    for(int i=0; i<ans.size(); i++) {
        cout<<ans[i].first + 1<<" "<<ans[i].second + 1<<endl;        // 1 based indexing
    }
}
int main() {
    int n;
    cin>>n;
    string s, t;
    cin>>s>>t;
    minLettersSwap(s,t);
    return 0;
}