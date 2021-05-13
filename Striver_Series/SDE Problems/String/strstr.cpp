#include<bits/stdc++.h>
using namespace std;
// using inbuilt function
// t.c O(m+n), s.c O(m) , m->length of needle
int strStr(string haystack, string needle) {
    if(needle.size() == 0) return 0;
    size_t found = haystack.find(needle);
    if(found != string::npos) return found;
    return -1;
}


// usnig sliding window approach
int findSubString(string mainString, string subString) {
    int l1 = mainString.length();
    int l2 = subString.length();
    int windowSize = l2;
    if(l2 > l1) return -1;

    for(int i=0; i<=(l1 - windowSize); i++) {
        int k = i,j;
        for(j=0; j<l2; j++) {
            if(subString[j] != mainString[k]) break;
            k++;
        }
        if(j == l2) return i;
    }
    return -1;
}
int main() {
    string s1 = "geeksforgeeks for computer science portal";
    string s2 = "computer";
    int found = findSubString(s1, s2);
    if(found != -1) cout<<found<<endl;
    else cout<<"not found"<<endl;
    return 0;
}