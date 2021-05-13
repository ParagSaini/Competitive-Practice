// #include<unordered_set>
#include<iostream>
#include<algorithm>
// #include<queue>
// #include<climits>
#include<vector>
// #include<stack>
using namespace std;

void MergePrint(vector<pair<int, int>> ar) {
    
    if(ar.size() == 0) return;
        
    vector<int> start;
    vector<int> end;
    start.push_back(ar[0].first);
    end.push_back(ar[0].second);
    
    for(int i=1; i<ar.size(); i++) {
        
        int newStart = ar[i].first;
        int newEnd = ar[i].second;
        
        if(newStart > end.back() ) {
            start.push_back(newStart);
            end.push_back(newEnd);
        }
        else {
            if(newEnd > end.back()) {
                end.pop_back();
                end.push_back(newEnd);
            }
        }
    }
    
    for(int i=0; i<start.size(); i++) {
        cout<<start[i]<<" "<<end[i]<<" ";
    }
    cout<<endl;
    
}

int main() {
    system("cls");
    vector<pair<int, int> >k = {{3,15}, {1,2}, {2,3}, {4,5}, {0, 2}};
    sort(k.begin(), k.end());
    MergePrint(k);
    return 0;
}