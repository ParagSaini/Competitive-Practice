#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve() {

}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    int n;
    string pat, str;
    vector<string> arr;
    while(cin>>n) {
        cin>>pat; cin>>str;
        int ind = str.find(pat);
        while(ind != str.npos) {
            cout<<ind<<endl;
            ind = str.find(pat, ind+1);
        }
        cout<<endl;
    }
    return 0;
}