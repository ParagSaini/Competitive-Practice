#include<iostream>
#include<vector>
#include<algorithm>
#include<conio.h>
using namespace std;
int main()
{
	vector<int> a = {2,3,1,3,4,23,32,1,2};
	vector<int>::iterator it1= max_element(a.begin(), a.end());
	vector<int>::iterator it2= min_element(a.begin(), a.end());
	cout<<"Max element is "<<*it1<<" and Min element is "<<*it2<<endl;
	return 0;
}