#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<unordered_set>
#include<set>
using namespace std;
vector<int> Dojob(vector<int> ar) {
    unordered_set<int> repeat;
    int max = *max_element(ar.begin(), ar.end());
    for(int i=0; i<ar.size(); i++) {
        if(repeat.count(ar[i])) {
            ar[i] = max + 1;
            max++;
            // repeat.insert(max);              // this is important
        }
        else {
            repeat.insert(ar[i]);
        }
    }
    return ar;
}
int main() {
    system("cls");
    vector<int> ar = {1,3,4,5,3};
    vector<int> result = Dojob(ar);
    for(auto i:result) cout<<i<<" ";
    return 0;
}