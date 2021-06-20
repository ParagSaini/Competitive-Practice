#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;

void solve(string& str, string checker, int k) {
    int n = str.length();
    unordered_set<string> s;
    for(int i =0; i<n; i++ ){
        int badchar = 0;    
        string cur;
        for(int j =i; j<n; j++) {
            cur.push_back(str[j]);
            if(checker[str[j] - 'a'] == '0') badchar++;
            if(badchar <= k) {
                s.insert(cur);
            }
        }
    }
    cout<<s.size()<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
	#endif
    string str;
    cin>>str;
    string checker;
    cin>>checker;
    int k; 
    cin>>k;
    solve(str, checker, k);
    return 0;
}