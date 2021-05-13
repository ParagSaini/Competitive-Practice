#include<bits/stdc++.h>
using namespace std;
// Overall time complexity is O(nlog(n))..
class Meeting{
    public:
    int start = 0, finish = 0, pos = 0;
    Meeting(){}
    Meeting(int s, int f, int p) {
        start = s;
        finish = f;
        pos = p;
    }
};

bool compare(Meeting a, Meeting b) {
    if(a.finish == b.finish) return a.pos < b.pos;
    return a.finish < b.finish;
}

void generateMeetings(int start[], int end[], int n, Meeting meetings[]){
    for(int i=0; i<n; i++) {
        Meeting temp(start[i], end[i], i+1);
        meetings[i] = temp;
    }
}
void maxMeetings(int start[], int end[], int n) {
    Meeting meetings[n] = {};
    generateMeetings(start, end, n, meetings);
    
    sort(meetings, meetings+n, compare);
    
    int finishTime = meetings[0].finish;
    int position = meetings[0].pos;
    
    for(int i=1; i<n; i++) {
        if(meetings[i].start > finishTime) {
            cout<<position<<" ";
            finishTime = meetings[i].finish;
            position = meetings[i].pos;
        }
    }
    cout<<position<<" ";
}