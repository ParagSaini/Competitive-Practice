 #include<bits/stdc++.h>
 using namespace std;

 int lengthOfLongestSubstring(string s) {
    if(s.length() == 0) return 0;
    unordered_set<char> visited;
    int a_pointer = 0;
    int b_pointer = 0;
    int maxLength = 1;
    
    
    while(b_pointer < s.length()) {
        if(!visited.count(s[b_pointer])) {
            visited.insert(s[b_pointer]);
            maxLength = max(maxLength, (int)visited.size());
            b_pointer++;
        } else {
            // removing all the element before and upto duplicate element, thats why only increase a_pointer not b_pointer.
            visited.erase(s[a_pointer]);
            a_pointer++;
        }
        
    }
    return maxLength;
}