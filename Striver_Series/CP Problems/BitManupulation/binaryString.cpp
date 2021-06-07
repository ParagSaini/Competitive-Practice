#include<bits/stdc++.h>
using namespace std;

void findK(string x, string y) {
    // for simplicity reverse both the strings.
    reverse(x.begin(), x.end());
    reverse(y.begin(), y.end());

    int l1 = x.length(), l2 = y.length(), leftmost_set_bit_posY, leftmost_set_bit_posX;     
    
    for(int i=0; i<l2; i++) {
        if(y[i] == '1') {
            leftmost_set_bit_posY = i;
            break;
        }
    }
    for(int i=0; i<l1; i++) {
        if(x[i] == '1' && i >= leftmost_set_bit_posY) {
            leftmost_set_bit_posX = i;
            break;
        }
    }
    cout<<leftmost_set_bit_posX - leftmost_set_bit_posY<<endl;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        string x, y;
        cin>>x>>y;
        findK(x,y);
    }
    return 0;
}