#include<bits/stdc++.h>
using namespace std;

// MAKE SURE OF THE OPERATOR PRIORITY.
int leftMostUnsetBit(int n) {
    int i=0, res;
    while(n > 0) {
        i++;
        if( (n&1) == 0) {
            res = i;
        }
        n = (n>>1);
    }
    return res;
}
void countOperation(int n) {
    if(n&(n+1) == 0) {       // already a perfect long cat
        cout<<0<<endl;
        return;
    }
    int num = n, operations = 0;
    vector<int> seq;
    
    while( (num &(num+1)) != 0) {
        // find the leftmost unset bit pos.
        int l = leftMostUnsetBit(num);
        num = ( num ^ ((int)pow(2,l) -1));
        seq.push_back(l);
        operations++;
        if( (num&(num+1)) == 0) break;
        num++;
        operations++;
    }
    cout<<operations<<endl;
    for(auto it : seq) cout<<it<<" ";

}
int main() {
    int n;
    cin>>n;
    countOperation(n);
    return 0;
}