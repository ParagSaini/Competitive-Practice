#include<bits/stdc++.h>
using namespace std;
int minVal(string str, int k) {
    unordered_map<char, int> m;
    priority_queue<int> q;
    int mini = 0;
    for(int i=0; i<str.length(); i++) {
        if(m.count(str[i])) {
            m[str[i]]++;
        }else {
            m[str[i]] = 1;
        }
    }
    for(auto k : m) {
        q.push(k.second);
    }
    while(k) {
        int temp = q.top();
        temp--;
        q.pop();
        q.push(temp);
        k--;
    }
    while(!q.empty()) {
        int k = q.top();
        q.pop();
       mini += (k*k); 
    }
    return mini;
    
}
int main()
 {
	int t;
	cin>>t;
	for(int i=0; i<t; i++) {
	    string str;
	    int k;
	    cin>>str>>k;
	    cout<<minVal(str, k);
	    cout<<endl;
	}
	return 0;
}