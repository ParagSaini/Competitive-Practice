// link: https://practice.geeksforgeeks.org/problems/rotate-a-2d-array-without-using-extra-space1004/1

void transpose(vector<vector<int>>& arr, int n) {
	    for(int i=0; i<n; i++) {
	        for(int j=0; j<i; j++) {
	            swap(arr[i][j] , arr[j][i]);
	        }
	    }
	}
	void swapRow(vector<vector<int>>& arr, int n) {
	    int s = 0;
	    int e = n-1;
	    while(s < e) {
	        for(int i=0; i<n; i++) {
	            swap(arr[s][i], arr[e][i]);
	        }
	        s++;
	        e--;
	    }
	}
	void rotateMatrix(vector<vector<int>>& arr, int n) {
	       transpose(arr, n);
	       swapRow(arr, n);
	}