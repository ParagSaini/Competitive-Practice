#include<bits/stdc++.h>
using namespace std;
// overall t.c O(n+m) && s.c O(m) for kmp Array
vector<int> KmpArray(string& pat) {
    int len = pat.length(); 
    vector<int> arr(len);
    arr[0] = 0;
    int i=0, j=1;
    while(j < len) {
        // there is a match
        if(pat[i] == pat[j]) {
            arr[j] = i+1;
            i++;
            j++;
        }else if(i == 0){
            arr[j] = 0;
            j++;
        }else {
            i = arr[i-1]; 
        }
    }
    return arr;
}
int strStr(string str, string pat) {
    int l1 = str.length();
    int l2 = pat.length();
    if(l2 == 0) return 0;
    vector<int> kmpArr = KmpArray(pat);
    int i = 0, j = 0;
    
    while(i < l1) {
        if(str[i] == pat[j]) {
            if(j == l2-1) return (i - l2 + 1);      // starting index of substring
            i++; j++;
        }else if(j == 0) {
            i++;
        } else {
            j = kmpArr[j-1];
        }
    }
    return -1;
}

int main() {
    string str = "my name is parag saini and i am name is parag saini";
    string pat = "ara";
    cout<<strStr(str, pat);
    return 0;
}