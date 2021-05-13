class Interval {
    public:
    int start;
    int finish;
    Interval(int s, int f) {
        start = s;
        finish = f;
    }
};
bool compare(Interval a, Interval b) {
    return a.finish < b.finish;
}
int maxMeeting(vector<Interval> arr){
    int maxi = 1, bt;
    //sorting the meetings according to the finish time(ascending order);
    sort(arr.begin(), arr.end(), compare);
    bt = arr[0].finish;
    
    for(int i=1; i<arr.size(); i++) {
        if(arr[i].start >= bt) {
            maxi++;
            bt = arr[i].finish;
        }
    }
    return maxi;
}

int main()
 {
	int t;
	cin>>t;
	for(int i=1; i<=t ;i++) {
	    int n;
	    cin>>n;
	    vector<int> start;
	    vector<int> finish;
	    for(int i=0; i<n; i++) {
	        int temp;
	        cin>>temp;
	        start.push_back(temp);
	    }
	    for(int i=0; i<n; i++) {
	        int temp;
	        cin>>temp;
	        finish.push_back(temp);
	    }
	    vector<Interval> arr;
	    for(int i=0; i<n; i++) {
	        Interval temp(start[i], finish[i]);
	        arr.push_back(temp);
	    }
	    cout<<maxMeeting(arr)<<endl;
	    
	    
	}
	return 0;
}