#include <iostream>
#include<vector>
#include<algorithm>
#include<climits>
#include<math.h>
#include<unordered_set> 
using namespace std; 
int removeTrailingzero(int n) {
    while(1) {
        if(n % 10 == 0) {
            n = n/10;
        }
        else {
            return n;
        }
    }
}
int countUnique(int n) {
    unordered_set<int> s;
    while(1) {
        n++;
        n = removeTrailingzero(n);
        if(s.count(n)) {
            break;
        }
        else {
            s.insert(n);
        }
    }
    for(auto i:s) cout<<i<<" ";
    return s.size();
}
int main()  
{ 
    system("cls");
    int n = 100;
    cout<<countUnique(n);
    return 0; 
}