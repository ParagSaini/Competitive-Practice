#include<bits/stdc++.h>
using namespace std;

// t.c O(n) && s.c O(2n)
// actually we are finding the length of longest palindrome which starts from index = 0;
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

int minCharacter(string str) {
    string temp = str;
    temp.push_back('$');
    int i=str.length()-1;
    while(i>=0) {
        temp.push_back(str[i]);
        i--;
    }
    vector<int> kmpArr = KmpArray(temp);
    return (str.length() - kmpArr[kmpArr.size()-1]);
}
int main() {
    cout<<minCharacter("abc");
    return 0;
}