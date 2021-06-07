#include<bits/stdc++.h>
using namespace std;

// https://www.geeksforgeeks.org/find-a-repeating-and-a-missing-number/


// the most optimal, tough, but only tell if interviewer not satisfied with the below(summation ) approach.

// t.c O(n) && s.c O(1)

int *findTwoElement(int *nums, int n) {
    int* result = new int[2];
    
    int Xor = 0;
    for(int i=0; i<n; i++) {
        Xor = Xor^nums[i];
    }
    for(int i=1; i<=n; i++) {
        Xor = Xor^i;
    }
    
    int bucket1 = 0;    
    int bucket2 = 0;    
    
    int set_bit_no = Xor & ~(Xor-1);       // rightmost set bit no.
    // ~(Xor-1) == 2's compliment of Xor. ex Xor = 12(1100), 2s compliment = 0100, all digits reverted from the first set bit from right to left side.
    // ex if Xor = 12(1100), setbitno = 4(0100),
    
    for(int i=0; i<n; i++) {
        if(nums[i] & set_bit_no) {
            bucket1 = bucket1 ^ nums[i];
        } else {
            bucket2 = bucket2 ^ nums[i];
        }
    }
    
    for(int i=1; i<=n; i++) {
        if(i & set_bit_no) {
            bucket1 = bucket1 ^ i;
        }else {
            bucket2 = bucket2 ^ i;
        }
    }
    
    int i;
    for(i=0; i<n; i++) {
        if(bucket1 == nums[i]) {
            result[0] = bucket1;      // repeating
            result[1] = bucket2;        // missing
            break;
        }
    }
    if(i == n) {
        result[0] = bucket2;
        result[1] = bucket1;
    }
    
    return result;
}

// t.c O(n) && s.c O(1), but their may be some integer overflow if n is very high, though it is efficient for mostly interviewers.

int *findTwoElement(int *nums, int n) {
    int* result = new int[2];
    
    long long total_sum = ((long long)n*(n+1)/2);
    long long square_sum = ((long long)n*(n+1)*(2*n+1))/6;
    
    long long cur_sum = 0;
    long long cur_square_sum = 0;
    
    for(int i=0; i<n; i++) {
        cur_sum += (long long)nums[i];
        cur_square_sum += (long long)nums[i] * (long long)nums[i];
    }
    int eff_sum = (int)(total_sum - cur_sum);
    result[1] = (int)(eff_sum + ((square_sum - cur_square_sum)/(eff_sum)) )/2;
    result[0] = result[1] - eff_sum;
    return result;
}

// t.c O(n) && s.c O(n)
int *findTwoElement(int *nums, int n) {
    int* result = new int[2];
    
    int freq[n+1];
    for(int i=0; i<n+1; i++) freq[i] = 0;
    
    for(int i=0; i<n; i++) {
        freq[nums[i]]++;
    }
    
    for(int i=1; i<n+1; i++) {
        if(freq[i] > 1) result[0] = i;
        if(freq[i] == 0) result[1] = i;
    }
    return result;
}