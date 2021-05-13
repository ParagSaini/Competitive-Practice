#include<bits/stdc++.h>
using namespace std;

// t.c O(n) && s.c O(n)
int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0, i;
    stack<pair<int, int>> st;        // contains the height and starting index of rectangle of that height;
    for(i=0; i<heights.size(); i++) {
        int curHt = heights[i];
        
        if(st.empty()) {
            st.push({curHt, i});
        }else {
            int lastPopedStartingIndex = i;
            while(!st.empty() && curHt < st.top().first) {
                int w = i - st.top().second;
                int h = st.top().first;
                int Area = w * h;
                maxArea = max(maxArea, Area);
                lastPopedStartingIndex = st.top().second;
                st.pop();
            }
            st.push({curHt, lastPopedStartingIndex});
        }
    }
    while(!st.empty()) {
        int w = i - st.top().second;
        int h = st.top().first;
        int Area = w * h;
        maxArea = max(maxArea, Area);
        st.pop();
    }
    
    return maxArea;
}



// t.c O(n2) && s.c O(1)
int largestRectangleArea(vector<int>& heights) {
    int maxArea = 0;
    int Area = 0;
    for(int i=0; i<heights.size(); i++) {
        int minH = heights[i];
        for(int j=i; j<heights.size(); j++) {
            minH = min(minH, heights[j]);
            int width = j - i + 1;
            int height = minH;
            Area = width * height;
            maxArea = max(maxArea, Area);
        }
    }
    return maxArea;
}