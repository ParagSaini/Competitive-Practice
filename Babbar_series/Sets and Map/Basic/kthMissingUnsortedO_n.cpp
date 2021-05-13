#include<vector>
#include<iostream>
#include<algorithm>
#include<unordered_set>
using namespace std;
void findMissing(vector<int> ar, int k) {
    unordered_set<int> missing;
    for(int i=0; i<ar.size(); i++ ) {
        missing.insert(ar[i]);
    }
    int maxi = *max_element(ar.begin(), ar.end());            // finding max in vector ar
    int mini = *min_element(ar.begin(), ar.end());            // finding min in vector ar
    int count = 0;

    for(int i=mini; i<=maxi; i++) {
        if(!missing.count(i)) {
            count++;
            if(count == k) {
                cout<<i<<endl;
                return;
            }
        }
    }
    cout<<-1<<endl;
}
int main() {
    system("cls");
    vector<int> ar = {2,4,10,7};
    int k = 2;
    findMissing(ar,k);
    return 0;
}