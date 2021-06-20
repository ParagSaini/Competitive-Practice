vector<int> solve(string s) {
    vector<int> res;
    int arr[26];
    int n = s.length();

    for(int i=0; i<n; i++) {
        arr[s[i]-'a'] = i;
    }

    for(int i=0; i<n; i++) {
        int lastInd = arr[s[i]-'a'];
        int j = i+1;
        while(j < n && j < lastInd ) {
            if(arr[s[j]-'a'] > lastInd) {
                lastInd = arr[s[j]-'a'];
            }
            j++;
        }
        res.push_back(lastInd-i+1);
        i = lastInd;
    }
    return res;
}