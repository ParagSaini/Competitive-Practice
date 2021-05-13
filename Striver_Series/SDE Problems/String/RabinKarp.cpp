#include<bits/stdc++.h>
using namespace std;
// WE CAN MAKE MORE COMPLEX HASH FUNCTION, USING PRIME, EXAMPLE
/*  prime = 119;
    hashval += str[i] * pow(prime, i);
    and similar way define new recalculatehashVal function that will run in O(1) t.c
    */
// t.c best and average run time - O(n+m), worst case - O(nm), very rare, && s.c O(1)
int hashVal(string& str, int s, int e) {
    int val = 0;
    for(int i=s; i<=e; i++) val += (int)str[i];
    return val;
}
bool compareString(string& str, string& pat, int s) {
    int k1, k2 = s;
    for(int k1=0; k1<pat.length(); k1++) {
        if(str[k2++] != pat[k1]) return false;
    }
    return true;
}

int strStr(string str, string pat) {
    int l1 = str.length();
    int l2 = pat.length();
    
    if(l2 == 0) return 0;
    if(l2 > l1) return -1;
    
    int patHash = hashVal(pat, 0, l2-1);
    int curHash = hashVal(str, 0, l2-1);
    str.push_back(' ');       
    for(int i=0; i<=(l1-l2); i++) {
        if(curHash == patHash && compareString(str, pat, i)) return i;
        curHash = curHash - (int)str[i] + (int)str[i+l2];
        // (when i == (l1-l2) the extra space added to string str, is helpful to prevent the garbage value in str[i+l2])
    }
    str.pop_back();
    return -1;
}