class Solution {
public:
    int numberOfRounds(string startTime, string finishTime) {
        int h1 = stoi(startTime.substr(0, 2)), h2 = stoi(finishTime.substr(0, 2));
        int m1 = stoi(startTime.substr(3)), m2 = stoi(finishTime.substr(3));
        
        int t1 = h1*60 + m1, t2 = h2*60 + m2;  // converting every time into the minute with respect to the 00:00 time, and then rounding off the startTime to next closest 15 multiple and finishTime to previous closest 15 mutlitple. 
        
        if(t2 < t1) t2 += (60*24);
        int ans = max(0, (int)(floor(t2/15) - ceil(t1/15.0)));
        return ans;
    }
};