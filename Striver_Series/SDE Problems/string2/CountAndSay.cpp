#include<bits/stdc++.h>
using namespace std;

string countAndSay(int n) {
    // recursive solution 
        if(n == 1) return "1";
        string str = countAndSay(n-1);
        string result;
        int count = 0,i;
        for(i=0; i<str.length()-1; i++) {
            count++;
            if(str[i] != str[i+1]) {
                result.append(to_string(count)).push_back(str[i]);
                count = 0;
            }
        }
        if(count != 0){ 
            result.append(to_string(count+1)).push_back(str[i]);
        }else {
            result.append(to_string(1)).push_back(str[i]);
        }
        return result;


        // iterative solution
        if(n == 1) return "1";
        string temp = "1";
        while(--n) {
            string r;
            int count = 0,i;
            for(i=0; i<temp.length()-1; i++) {
                count++;
                if(temp[i] != temp[i+1]) {
                    r.append(to_string(count)).push_back(temp[i]);
                    count = 0;
                }
            }
            if(count != 0){ 
                r.append(to_string(count+1)).push_back(temp[i]);
            }else {
                r.append(to_string(1)).push_back(temp[i]);
            }
            temp = r;
        }
        return temp;
    }