#include<bits/stdc++.h>
using namespace std;

// optimal, t.c O(n) && s.c O(1)
int trappingWater(int arr[], int n){
    int waterTrap = 0;
    int leftMax = arr[0];
    int rightMax = arr[n-1];
    int left = 0;
    int right = n-1;
    
    while(left <= right){
        if(leftMax > rightMax) {
            if(arr[right] < rightMax) {
                waterTrap += (rightMax - arr[right]);
            }else rightMax = arr[right];
            right--;
        }else {
            if(arr[left] < leftMax) {
                waterTrap += (leftMax - arr[left]);
            }else leftMax = arr[left];
            left++;
        }
    }
    return waterTrap;
}
// see below for explanation
// O(n) t.c && O(1) s.c
int trap(vector<int>& height) {
    if(height.size() == 0) return 0;
    int ans = 0;
    
    int low = 0;
    int high = height.size()-1;
    int leftmax = 0;
    int rightmax = 0;
    
    
    while(low < high) {
        if(height[low] > height[high]) {
            if(height[high] > rightmax) rightmax = height[high];
            // we are using rightmax only because we are confident that rightmax is the smaller than leftmax. Run multiple test cases to get feel of it.
            else ans += rightmax - height[high];
            high--;
        }
        else {
            if(height[low] > leftmax) leftmax = height[low];
            // we are using the leftmax only because we are confident that leftmax is the smaller than rightmax .
            else ans += leftmax - height[low];
            low++;
        }
        
    }
    return ans;
}


// time complexity = O(n) && s.c O(n)..

// for any height, the water trapped above it always equal to the min(maxHeight at left, maxHeight at right) - height[i]   
// ...
int trap(vector<int>& height) {
    int ans = 0;
    if(height.size() == 0) return ans;
    int e = height.size()-1;

    // storing the maxHeight to right of every index.
    vector<int> rightMax(height.size());        
    int maxi = height[e];
    
    for(int i=e; i>=0; i--) {
        rightMax[i] = maxi;
        if(height[i] > maxi) maxi = height[i];
    }
        
    int leftmaxi = height[0];
    for(int i = 1; i<height.size(); i++) {
        if(leftmaxi > height[i] && rightMax[i] > height[i]) {
            ans += (min(leftmaxi, rightMax[i]) - height[i]) ; 
        }
        else if(height[i] > leftmaxi) leftmaxi = height[i];            
    }
    return ans;
}
