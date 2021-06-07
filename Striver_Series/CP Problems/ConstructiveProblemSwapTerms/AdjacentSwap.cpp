#include<bits/stdc++.h>
using namespace std;

// O(n) approach.
bool possibleToSort(vector<int> arr, string str) {
    str.push_back('0');
    int l = str.length(), lastZeroInd = l-1;
    vector<int> swapTill(l,-1);
    for(int i=l-2; i>=0; i--) {
        if(str[i] == '0') {
            lastZeroInd = i;
        } else {
            swapTill[i] = lastZeroInd;
        }
    }
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] != i) {
            int destInd = arr[i];
            if(swapTill[i] == -1 || swapTill[i] < destInd ) return false;
            swap(arr[i], arr[destInd]);
            i--;
        }
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) {
        int temp;
        cin>>temp;
        arr[i] = temp-1;    // Ai varies from 0 to n-1.
    }
    string str;
    cin>>str;
    if(possibleToSort(arr, str)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}


// nlogn approach.
bool possibleToSort(vector<int> arr, string str) {
    int n = arr.size();
    int s=0, e=0;
    str.push_back('0');
    for(int i=0; i<str.length(); i++) {
        if(str[i] == '1') {
            s = i;
            for(int j=i+1; j<str.length(); j++) {
                if(str[j] == '0') {
                    e = j;
                    i = j;
                    break;
                }
            }
            sort(arr.begin()+s, arr.begin()+e+1);    // sort it between [s,e], e+1 works as the endl.

        }
    }
    for(int i=1; i<n; i++) {
        if(arr[i] < arr[i-1]) return false;
    }
    return true;
}
int main() {
    int n;
    cin>>n;
    vector<int> arr(n);
    for(int i=0; i<n; i++) cin>>arr[i];
    string str;
    cin>>str;
    if(possibleToSort(arr, str)) cout<<"YES"<<endl;
    else cout<<"NO"<<endl;
    return 0;
}