#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
#include<set>
using namespace std;
int main() {
    system("cls");
    vector<int> ar = {1,2,3};
    unordered_set<int> repeated;
    int repeatedElem = 0;
    for(int i=0; i<ar.size(); i++) {
        if(repeated.count(ar[i])) {
            repeatedElem++;
        }
        else {
            repeated.insert(ar[i]);
        }
    }
    int effNumber = ar.size() - repeatedElem;
    cout<<"No. of pairs should be " <<effNumber*effNumber<<endl;
    return 0;
}