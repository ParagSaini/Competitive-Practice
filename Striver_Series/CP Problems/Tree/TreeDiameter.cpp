#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;
// The tree is not guarantee to be have 1 root node, it may have many root node which can be 4, 5, 6 anything not always '1'. so do accordingly.
// tree can be of very different category like below.
/*  10     
    4 1
    6 5
    7 2
    6 3
    1 7
    2 10
    10 9
    3 8
    8 9
    // taking root at '1'
    1 -> 7 -> 2 -> 10 -> 9 -> 8 -> 3 -> 6 -> 5
    |-> 4
    // taking root at '10';
    10 -> 9 -> 8 -> 3 -> 6 -> 5
    |-> 2 -> 7 -> 1 -> 4

    We can make the root node and node, there is loss generisity or overall tree structure.
*/
int solve(vector<vector<int>>& edges, int root, int& diameter, vector<int>& visited) {
    // if(edges[root].size() == 1 && visited[edges[root][0]]) return 0;   no need to write this, because we don't go inside for loop we have 0 visited node from root. size of any element is never be zero in edges because the way we are taking the input.

    visited[root] = 1;
    int maxht = -1, maxi1 = -1, maxi2 = -1;
    // priority_queue<int> maxHeap; // no need to use maxheap, we only need max and second maximum value.

    for(int i=0; i<edges[root].size(); i++) {
        int child = edges[root][i];
        if(visited[child] == 0) {
            int ht = solve(edges, child, diameter, visited);
            // maxHeap.push(ht);
            maxht = max(maxht, ht);

            // setting maximum and second maximum correctly.
            if(ht >= maxi1) {
                maxi2 = maxi1;
                maxi1 = ht;
            }
            else if(ht > maxi2) {
                maxi2 = ht;
            }
        }
    }
   // we need the maximum and second maximum ht for getting longest diameter from current root node.

    // if(!maxHeap.empty()) {
    //     maxht = maxHeap.top();
    //     maxi1 = maxHeap.top();
    //     maxHeap.pop();
    //     if(!maxHeap.empty()) maxi2 = maxHeap.top();
    // }
    diameter = max(diameter, (maxi1 + maxi2 + 2));
    visited[root] = 0;
    return (maxht + 1);
}
int main() {
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    int t;
    // cin>>t;
    t = 1;
    while(t--) {
        int n;
        cin>>n;
        vector<vector<int>> edges(n+1);
        for(int i=1; i<=(n-1); i++) {
            int a, b;
            cin>>a>>b;
            // there is edge between 'a' and 'b', there is no concept like a is the parent and b is the child, no just see like this as a graph.

            // see the above tip at top, why we add both here.
            edges[a].push_back(b);
            edges[b].push_back(a);
        }
        int diameter = 0;
        vector<int> visited(n+1, 0);
        solve(edges, 1, diameter, visited);    // starting from the '1', the root node, we can choose any arbitary node and make it our roor, there is no loss of generisity.
        cout<<diameter<<endl;
    }
    return 0;
}