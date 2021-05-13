#include<vector>
#include<iostream>
#include<queue>
#include<climits>
#include<sstream>
#include<unordered_set>
using namespace std;
int main() {
    system("cls");
    string s = "Publish your own articles on GeeksforGeeks and share your knowledge with the world";
    stringstream ss(s);
    string word;
    while(ss >> word) {
        cout<<word<<" ";
    }
    return 0;
}