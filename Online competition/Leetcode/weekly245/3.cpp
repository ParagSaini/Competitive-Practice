#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int, int> p32;


bool mergeTriplets(vector<vector<int>> triplets, vector<int> target) {
    int n = triplets.size();
    int x = -1, y = -1, z = -1;
    for(auto v : triplets) {
        if(v[0] <= target[0] && v[1] <= target[1] && v[2] <= target[2]) {
            x = max(x, v[0]);
            y = max(y, v[1]);
            z = max(z, v[2]);
        }
    }
    if(x == target[0] && y == target[1] && z == target[2]) return true;
    return false;
}
int main() {
    cout<<mergeTriplets({{2,5,3},{1,8,4},{1,7,5}},{2,7,5});
    return 0;
}