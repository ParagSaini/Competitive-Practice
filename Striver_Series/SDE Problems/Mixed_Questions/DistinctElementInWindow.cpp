#include<bits/stdc++.h>
using namespace std;
// t.c O(n) & s.c O(n)
vector <int> countDistinct (int A[], int n, int k)
{
    vector<int> result;
    unordered_map<int, int> m;
    for(int i=0; i<k; i++) {
        if(m.count(A[i])) m[A[i]]++;
        else m[A[i]] = 1;
    }
    int removeIndex = 0;
    result.push_back(m.size());
    for(int i=k; i<n; i++) {
        int cur = A[i];
        int removedEle = A[removeIndex++];
        if(m[removedEle] == 1) m.erase(removedEle);
        else m[removedEle]--;
        
        if(m.count(cur)) {
            m[A[i]]++;
        } else m[A[i]] = 1;
        
        result.push_back(m.size());
    }
    return result;
}