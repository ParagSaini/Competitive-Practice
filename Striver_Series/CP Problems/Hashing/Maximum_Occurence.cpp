#include<bits/stdc++.h>
using namespace std;

// normally there are 128 ascii character in c++, but in extended ascii there are 256 character, the characters after 128 are useless and not gonna come in a normal string input. 


// t.c O(n), s.c O(128), ~constant
void findMaxOccurence(string str) {
    vector<int> freq(128, 0);
    char ch;
    int maxOccur = INT_MIN;
    for(int i=0; i<str.length(); i++) {
        freq[int(str[i])]++;
    }
    for(int i=128; i>=0; i--) {
        if(freq[i] >= maxOccur) {
            maxOccur = freq[i];
            ch = (char)i;
        }
    }
    cout<<ch<<" "<<maxOccur<<endl;

}

int main() {
    string str;
    getline(cin, str);
    findMaxOccurence(str);
    return 0;
}

// t.c O(n), s.c O(128)
int main() {
	string s;
	unordered_map<char, int> m;
	getline(cin, s);
	for(int i=0; i<s.length(); i++) {
		m[s[i]]++;
	}
	int maxi = INT_MIN;
	char ch;
	for(auto it : m) {
		if(it.second == maxi) {
			ch = ((int)ch < (int)it.first ? ch : it.first);
		}
		else if(it.second > maxi) {
			maxi = it.second;
			ch = it.first;
		}
	}
	cout<<ch<<" "<<maxi<<endl;
	return 0;
}