#include<bits/stdc++.h>
using namespace std;
int main() {
  int n,k;
  cin>>n>>k;
  priority_queue<int> seq;
  int min = 0, max = n, i=1;
  int temp = n;
  while(temp !=0){
    if(temp&1) {
      min++;
      seq.push(i);
    }
    temp = temp>>1;
    i*=2;
  }
  if(k >= min && k <= max) {
    cout<<"YES"<<endl;
    while(seq.size() != k) {
      int top = seq.top();
      seq.pop();
      seq.push(top/2);
      seq.push(top/2);
    }
    while(seq.size()) {
      cout<<seq.top()<<" ";
      seq.pop();
    }
  } else cout<<"NO";
  return 0;
}