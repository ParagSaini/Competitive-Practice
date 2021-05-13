#include<bits/stdc++.h>
using namespace std;

// t.c O(n), s.c O(1)
class result{
    public:
    long long maxSum = 0;
    int count = 0;
    result(long long val, int c) {
        maxSum = val;
        count = c;
    }
};
result getResult(vector<int> arr) {
    bool hasPositiveNum = false;
    int maxi = INT_MIN;
    long long sum = 0;
    int count = 0;
    for(int i=0; i<arr.size(); i++) {
        if(arr[i] >= 0) {
            hasPositiveNum = true;
            sum += (long long)arr[i];
            count++;
        }
        maxi = max(maxi, arr[i]);
    }
    if(hasPositiveNum) {
        return result(sum, count);
    } else {
        return result((long long)maxi, 1);
    }
}
int main() {
	int num;
    vector<int> arr;
	cin>>num;
	for(int i=0; i<num; i++) {
		int temp;
		cin>>temp;
		arr.push_back(temp);
	}
	result r = getResult(arr);
    cout<<r.maxSum<<" "<<r.count;
	return 0;
}