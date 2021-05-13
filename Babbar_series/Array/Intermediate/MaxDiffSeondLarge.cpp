int MaxDiff(vector<int> ar) {
    int max_diff = ar[1] - ar[0];
    int mini = ar[0];
    for(int i=1; i<ar.size(); i++) {
        if(ar[i] - mini > max_diff) max_diff = ar[i] - mini;
        if(ar[i] < mini) mini = ar[i];
    }
    if(max_diff < 0) return -1;
    return max_diff;
}