#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;


void solve(string str, string pat) {
    int ind = str.find(pat);
    if(ind == str.npos) {
        cout<<"Not Found"<<endl;
        return;
    }
    vector<int> arr;
    while(ind != str.npos) {
        arr.push_back(ind+1);
        ind = str.find(pat, ind+1);
    }
    cout<<arr.size()<<endl;
    for(auto it : arr) cout<<it<<" ";
    cout<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int t;
    cin>>t;
    while(t--) {
        string str, pat;
        cin>>str>>pat;
        solve(str, pat);
        cout<<endl;
    }
    return 0;
}