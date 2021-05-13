// link: https://practice.geeksforgeeks.org/problems/count-subarrays-with-equal-number-of-1s-and-0s-1587115620/1/?category[]=Arrays&difficulty[]=1&page=1&query=category[]Arraysdifficulty[]1page1

long long int countSubarrWithEqualZeroAndOne(int arr[], int N)
{
    unordered_map<int, int> freq;
	for(int i=0; i<N; i++) 
		if(arr[i] == 0) arr[i] = -1;

	int count = 0;
	int sum = 0;
	for(int i=0; i<N; i++) {
		sum += arr[i];
		if(sum == 0) count++;
		if(freq.count(sum)) count += freq[sum];
		freq[sum] += 1;
	}
	return count;
}