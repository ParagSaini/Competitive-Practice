#include<bits/stdc++.h>
using namespace std;

class Job{
    public:
    int dead, profit;
    Job(int d, int p) {
        dead = d;
        profit = p;
    }
};


// t.c O(nlog(n) + n*d) && s.c O(d),    1<=n<=100000, 1<=deadline<=100, 1<=profit<=500
// can be optimised by using disjoint sets
bool compare(Job a, Job b) {
    return (a.profit > b.profit);
}
pair<int,int> JobScheduling(Job arr[], int n) 
{ 
    int jobs = 0; int maxProf = 0;
    sort(arr, arr+n, compare);
    vector<int> work(101, 0);
    for(int i=0; i<n; i++) {
        int curDead = arr[i].dead;
        int curProf = arr[i].profit;
        if(work[curDead] == 0) work[curDead] = curProf;
        else {
            for(int i=curDead; i>=1; i--) {
                if(work[i] == 0) {
                    work[i] = curProf;
                    break;
                } 
            }
        }
    }
    for(int i=0; i<101; i++) {
        maxProf += work[i];
        if(work[i] != 0) jobs++;
    }
    return {jobs, maxProf};
} 