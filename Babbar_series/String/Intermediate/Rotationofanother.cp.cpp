#include<iostream>
#include<unordered_set>
#include<string>
using namespace std; 
int main() {
   system("cls");
   string s = "abcde";
   string temp = s.append(s);
   int found = temp.find("csade");
   if( found == string::npos)
      cout<<"found";
   return 0;
}
/* .find() is a predefined functionality for string class, it takes a string as a argument, and return the index of the first occurence element of that string in the original string, if present. if not present then it return the string::npos
*/
// Time complexity = O(n);