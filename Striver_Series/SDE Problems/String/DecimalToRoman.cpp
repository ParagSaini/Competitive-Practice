#include<bits/stdc++.h>
using namespace std;

int printRoman(int number) 
{ 
    // we have to take 4, 9, 40, 90, 400, 900 as special numbers, without them the problem is hard to solve
    int num[] = {1,4,5,9,10,40,50,90,100,400,500,900,1000}; 
    string sym[] = {"I","IV","V","IX","X","XL","L","XC","C","CD","D","CM","M"}; 
    int i=12; 
    // finding the just smaller value than number.    
    while(number>0) 
    { 
      int quotient = number/num[i]; 
      number = number%num[i]; 
      while(quotient--) 
      { 
        cout<<sym[i]; 
      } 
      i--; 
    } 
} 