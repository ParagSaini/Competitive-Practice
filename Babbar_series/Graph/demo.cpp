#include<queue>
#include<iostream>
#include<map>
#include<vector>
#include<climits>
#include<algorithm>
#include<set>
using namespace std;
class MapNode {
    public:
    int vertex;
    int distance;
    MapNode(int v, int d) {
        vertex = v;
        distance = d;
    }
};
// overload the <(operator) so that we use multimap according to us on our custom object, this way only 
// works on the custom object

bool operator<(MapNode a, MapNode b) {
    return a.distance < b.distance;
}
int main() {
    vector<int> dis(6,32);
    cout<<dis[4]<<dis[2];
    multiset<MapNode> v;
    int source = 3;
    for(int i=1; i<=6; i++) {
        if(i == source) 
            v.insert(MapNode(i, 0));
        else 
        v.insert(MapNode(i,INT_MAX));
    }
    for(auto i : v) {
        cout<<i.vertex<<" "<<i.distance<<endl;
    }
    return 0;
}