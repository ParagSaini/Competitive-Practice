#include<bits/stdc++.h>
using namespace std;

int stoi(string str)
{
    int ans = 0;
    bool negative = false;
    if(str[0] == '-') {
        negative = true;
    }
    for(int i= (negative ? 1 : 0); i<str.length(); i++) {
        int digit = str[i] - '0';
        if(digit < 0 || digit > 9) return -1;
        ans = (ans + digit) * 10;
    }
    ans /= 10;
    if(negative) (ans *= -1);
    return ans;
}