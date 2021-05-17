#include<bits/stdc++.h>
using namespace std;
 //t.c O(n), s.c O(n)
int main() {
    int t;
    cin>>t;
    unordered_map<string, int> m;
    for(int i=0; i<t; i++) {
        string s;
        cin>>s;
        // count internally uses the find function, it returns how many times a particular key exist in map, since this unordered_map contains only the distinct elements it gives 0 or 1.
        // whereas in find function it returns the iterator to that key value pair if exists, otherwise it gives iterator unordered_map.end();
        if(m.count(s)) {
            cout<<s<<m[s]<<endl;
            m[s]++;
        }else {
            cout<<"OK"<<endl;
            m[s] = 1;
        }
    }
    return 0;
}