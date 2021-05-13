#include<vector>
#include<iostream>
#include<algorithm>
#include<math.h>
#include<climits>
#include<unordered_map>
#include<unordered_set>
#include<set>
#include<queue>
using namespace std;
void Triplets(vector<int> ar) {
    unordered_set<int> num;
    int count = 0;
    for(int i=0; i<ar.size(); i++) {
        num.insert(ar[i]);
    }
    for(int i=0; i<ar.size()-1; i++) {
        for(int j=i+1; j<ar.size(); j++) {
            int difference = ar[j] - ar[i];
            if (num.count(ar[j] + difference)) {
                cout<<ar[i]<<" "<<ar[j]<<" "<<ar[j]+difference<<endl;
                count++;
            }
        }
    }
    cout<<count;
}
void printAllAPTriplets(vector<int> arr) 
{ 
    int n = arr.size();
    unordered_set<int> s; 
    for (int i = 0; i < n - 1; i++) 
    { 
    for (int j = i + 1; j < n; j++) 
    { 
        // Use hash to find if there is 
        // a previous element with difference 
        // equal to arr[j] - arr[i] 
        int diff = arr[j] - arr[i]; 
        if (s.find(arr[i] - diff) != s.end()) 
            cout << arr[i] - diff << " " << arr[i] 
                 << " " << arr[j] << endl; 
    } 
    s.insert(arr[i]); 
    } 
} 
   
// Driver code 
int main() {
    system("cls");    
    vector<int> ar = { 3, 5, 6, 7, 8, 10, 12 };
    printAllAPTriplets(ar);
    return 0;
}