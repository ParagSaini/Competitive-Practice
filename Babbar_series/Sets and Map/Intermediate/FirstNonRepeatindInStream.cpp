#include<bits/stdc++.h>
using namespace std;
int main()
 {
	int t;
	cin>>t;
	for(int i=0; i<t; i++){
	    int n;
	    cin>>n;
	    unordered_map<char, int> repeat;
	    set<int> onceInd;
	    vector<char> ar;
	    for(int i=0; i<n; i++) {
	        char ch;
	        cin>>ch;
	        ar.push_back(ch);
	        if(repeat.count(ch)) {
	            int ind = repeat[ch];
	            if(onceInd.count(ind)) {
	                onceInd.erase(ind);
	            }
	            if(onceInd.size() == 0) cout<<-1<<" ";
	            else cout<<ar[*(onceInd.begin())]<<" ";
	        } else {
	            repeat[ch] = i;
	            onceInd.insert(i);
	            cout<<ar[*(onceInd.begin())]<<" ";
	        }
	    }
	    cout<<endl;
	}
	return 0;
}