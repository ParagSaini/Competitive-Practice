#include<bits/stdc++.h>
using namespace std;
vector<int> num1;

// t.c O(n+m) , s.c O(1)
int compareVersion(string version1, string version2) {
    int temp1 = 0,temp2 = 0;
    int len1 = version1.length(),len2 = version2.length();
    int i = 0,j = 0;
    while(i<len1 || j<len2) {
        temp1 = 0;
        temp2 = 0;
        while(i<len1 && version1[i] != '.') {
            temp1 = temp1*10 + version1[i++] -'0';

        }
        while(j<len2 && version2[j] != '.') {
            temp2 = temp2*10 + version2[j++]-'0';

        }
        if(temp1>temp2) return 1;
        else if(temp1<temp2) return -1;
        else {
            i++;
            j++;

        }
    }
    return 0;
}

// t.c O(n+m) , s.c O(n+m)
int compareVersion(string version1, string version2) {
    vector<int> num2;
    int n = 0;
    for(int i=0; i<version1.length(); i++) {
        if(version1[i] == '.') {
            num1.push_back(n);
            n = 0;
        }else {
            if(n == 0) n = version1[i] - '0';
            else n = n*10 + (version1[i] - '0');
        }
    }
    num1.push_back(n);
    n = 0;
    for(int i=0; i<version2.length(); i++) {
        if(version2[i] == '.') {
            num2.push_back(n);
            n = 0;
        } else {
            if(n == 0) n = version2[i] - '0';
            else n = n*10 + (version2[i] - '0');
        }
    }
    num2.push_back(n);
    
    int e = num1.size() > num2.size() ? num1.size() : num2.size();
    for(int i=0; i<e; i++) {
        int n1 = 0;
        int n2 = 0;
        if(i < num1.size() && i < num2.size()) {
            n1 = num1[i];
            n2 = num2[i];
        } else if(i < num1.size()) {
            n1 = num1[i];
        }else {
            n2 = num2[i];
        }
        if(n1 > n2) return 1;
        if(n2 > n1) return -1;
    }
    return 0;
}