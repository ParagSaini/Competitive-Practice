#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
class coord {
    public:
    int x, y;
    ll dist;
    char ch;
    coord(int a, int b, ll c, char k) {
        x = a; y = b; dist = c; ch = k;
    }
};
bool comp(coord a, coord b) {
    return (a.dist <= b.dist);
}
class heapComp {
    public:
    bool operator()(coord a, coord b) {
        return (a.dist < b.dist);
    }
};

int main() {
    int x,y, n, k;
    cin>>x>>y>>n>>k;
    priority_queue<coord, vector<coord>, heapComp> maxHeap;
    int sulf = 0, other = 0;
    for(int i=0; i<n; i++) {
        int x1, y1; char ch;
        scanf("%d %d %c", &x1, &y1, &ch);
        ll k1 = x1-x, k2 = y1-y;
        ll dist = (k1*k1) + (k2*k2);
        maxHeap.push(coord(x1,y1,dist, ch));
        if(maxHeap.size() > k) {
            maxHeap.pop();
        }
    }
    while(!maxHeap.empty()) {
        coord x = maxHeap.top();
        maxHeap.pop();
        if(x.ch == 'X') other++;
        else sulf++;
    }
    
    if(sulf > other) cout<<"IT IS EXHILARATING"<<endl;
    else cout<<"EASY AS CAKE"<<endl;
    return 0;
}