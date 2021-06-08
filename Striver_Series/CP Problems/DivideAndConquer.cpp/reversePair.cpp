#include<bits/stdc++.h>
using namespace std;

int countPairs(vector<int>& nums, int s1, int e1, int e2) {
    int pairs = 0;
    int s2 = e1+1;
    while((s1 <= e1) && (s2 <= e2)) {
        long long val1 = nums[s1], val2 = nums[s2];
        if(val1 > (2*val2)) {
            pairs += (e1-s1 + 1);
            s2++;
        } else {
            s1++;
        }
    }
    return pairs;
}

int mergeAndCount(vector<int>& nums, int s1, int e1, int e2) {
    vector<int> sortArr;
    int start1 = s1, start2 = e1+1;
    int pairs = countPairs(nums, s1, e1, e2);

    while((start1 <= e1) && (start2 <= e2)) {
        if(nums[start1] <= nums[start2]) {
            sortArr.push_back(nums[start1]);
            start1++;
        } else {
            sortArr.push_back(nums[start2]);
            start2++;
        }
    }
    while(start1 <= e1) {
        sortArr.push_back(nums[start1++]);
    }
    while(start2 <= e2) {
        sortArr.push_back(nums[start2++]);
    }
    int k = 0;
    for(int i=s1; i<=e2; i++) {
        nums[i] = sortArr[k++];
    }
    return pairs;
}

int reversePairs(vector<int>& nums, int s, int e) {
    if(s >= e) return 0;

    int mid = (s + e)/2;
    int a = reversePairs(nums, s, mid);
    int b = reversePairs(nums, mid+1, e);
    int c = mergeAndCount(nums, s, mid, e);
    return (a+b+c);
}

int main() {
    vector<int> arr = {1,3,2,3,1};
    cout<<reversePairs(arr, 0, arr.size()-1);
    return 0;
}