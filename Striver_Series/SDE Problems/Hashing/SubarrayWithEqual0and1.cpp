#include<bits/stdc++.h>
using namespace std;

// t.c O(n) && s.c O(n)
int countSubarray(vector<int>& arr) {
	unordered_map<int, int> freq;
	for(int i=0; i<arr.size(); i++) 
		if(arr[i] == 0) arr[i] = -1;

	int count = 0;
	int sum = 0;
	for(int i=0; i<arr.size(); i++) {
		sum += arr[i];
		if(sum == 0) count++;
		if(freq.count(sum)) count += freq[sum];
		freq[sum] += 1;
	}
	return count;
}