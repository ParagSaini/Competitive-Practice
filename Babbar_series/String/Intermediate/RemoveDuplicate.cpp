#include<iostream>
#include<unordered_set>
#include<string>
using namespace std; 
//Time complexity = O(n), space complexity = O(1) as the no. of alphabets are atmost '26', therefore constant space required.
int main() 
{ 
   system("cls");
   unordered_set<char> x;
   string s = "Raju chala apni dukaan par";
   int index = 0;             // tracking the current position to insert in the string.
   for(int i=0; i<s.length(); i++) {
      if(!x.count(s[i])) {                    // if current character is not present in the set.
         x.insert(s[i]);
         s[index++] = s[i];
      }
   }
   s[index] = '\0';                // terminating the string
   for(int i=0; i<s.length(); i++)                  // this gives the wrong output, because it can't terminate on '\0',
      cout<<s[i];

   cout<<endl;

   for(int i=0; s[i] != '\0'; i++)           // this gives the correct answer, because we explicitly terminate the loop when s[i] == '\0'.
      cout<<s[i];
   return 0; 
}