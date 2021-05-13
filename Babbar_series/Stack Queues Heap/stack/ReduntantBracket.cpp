// #include<unordered_set>
#include<iostream>
#include<algorithm>
// #include<queue>
// #include<climits>
#include<vector>
#include<stack>
using namespace std;

string checkRed(string ar) {
    for(int i=0; i<ar.length(); i++) {
        if(ar[i] == '('){
            if((i+2) < ar.length() && ar[i+2] == ')') {
                return "yes";
            }
        }
        else if(ar[i] == ')') {
            if((i+1) < ar.length() && ar[i+1] == ')') {
                return "yes";
            }
        }
    }
    return "No";
}
int main() {
    system("cls");
    string s = "( (a+b) * (c) )";
    cout<<checkRed(s);
    return 0;
}