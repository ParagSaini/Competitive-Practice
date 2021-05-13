#include <iostream>
#include<vector>
#include<unordered_set> 
using namespace std; 
// Time complexity = O(n);         very nice 
// whenever we find the subarray with sum 0, the sum of total
// array till that is equal to some previous sum.
/* ex: ar = {5,4,2,-3,1,6}; subarray with sum 0 = {2,-3,1};
sum till element 1 = 9(5+4);
*/
bool Subarraywithzerosum(vector<int> ar) {
    unordered_set<int> sumTillNow;
    int sum = 0;
    for(int i=0; i<ar.size(); i++) {
        sum += ar[i];
        if(sum == 0 || sumTillNow.count(sum)) {
            return true;
        }
        sumTillNow.insert(sum);
    }
    return false;
}
int main()  
{ 
    system("cls");
    vector<int> ar = {5,4,2,-3,1,6,0};
    if(Subarraywithzerosum(ar)) {
        cout<<"Their exists a subarray with zero sum";
    }     
    else {
        cout<<"Their is no such subarray exist with zero sum";
    }
    return 0; 
}