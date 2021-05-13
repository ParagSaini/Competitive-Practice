#include<iostream>
#include<conio.h>
#include<string>
using namespace std;
int main()
{
	double a = 23.12;
	string s = to_string(a);
	double x = stod(s);
	int y = stoi(s);
	cout<<s<<" "<<x<<" "<<y<<" ";
	getch();
	return 0;
}