#include <iostream>
#include<vector>
#include<algorithm>
#include<unordered_set> 
using namespace std; 
bool compare(int a, int b) {
    return a>b;
}
void PrintMaximiseFirst(int ar1[], int ar2[], int n) {
    vector<int> allNum;
    for(int i=0; i<n; i++) {
        allNum.push_back(ar1[i]);
        allNum.push_back(ar2[i]);
    }

    sort(allNum.begin(), allNum.end(), compare);

    unordered_set<int> s;
    for(int i=0; i<allNum.size(); i++) {
        if(s.size() == n) break;
        else if(!s.count(allNum[i])) {
            s.insert(allNum[i]);
        }
    }

    //traversing second array
    vector<int> result;
    for(int i=0; i<n; i++) {
        if(s.count(ar2[i])) {
            result.push_back(ar2[i]);
        }
    }
    if(result.size() != n) {
        for(int i=0; i<n; i++) {
            if(s.count(ar1[i])) {
                result.push_back(ar1[i]);
            }
        }
    }

    for(auto i: result) cout<<i<<" ";
}
int main()  
{ 
    system("cls");
    int arr1[] = {7,4,8,0,1};
    int arr2[] = {9,7,6,4,8};
    int n = sizeof(arr1)/sizeof(int);
    PrintMaximiseFirst(arr1, arr2, n);
    return 0; 
}