void printN(vector<int>& ar, int k) {
    queue<int> neg;
    for(int i=0; i<k; i++) {
        if(ar[i] < 0) neg.push(ar[i]);
    }
    for(int i=0; i<=(ar.size()-k); i++) {
        if(neg.empty()) cout<<0<<" ";
        else cout<<neg.front()<<" ";
        
        if(ar[i] < 0) neg.pop();
        if(ar[i+k] < 0) neg.push(ar[i+k]);
    }
}