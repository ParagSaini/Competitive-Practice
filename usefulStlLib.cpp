#include<bits/stdc++.h>
using namespace std;

// MAKE PAIR IS SAME AS WE DID USING THE CURLY BRACKET, BUT SOME COMPILER GIVE ERROR WHEN USING CURLY BRACKET.
vector<pair<int, int>> ar = {{1,2}, {3,2}};
vector<pair<int, int>> ar = {make_pair(1,2), make_pair(3,2)};

class A {
    public:
    int a ;
    int b ;
    A(int x, int y ) {
        a = x;
        b = y;
    }
};
// instead of using greater<int> we can make our own comparator class, do the same for the custom data types, but in the sort function we have to pass only the function not makeing the class.
class Comp{
    public:
    bool operator()(const A& first, const A& sec){
		// '<' sign for maxheap, and '>' sign for min heap
        return first.a < sec.a;
    }
};
// for custom object in priority queue;
priority_queue<A, vector<A>, Comp> q;
    q.push(A(2,3));
    q.push(A(5,2));
    q.push(A(1,3));
    cout<<q.top().a<<" "<<q.top().b<<endl;

priority_queue<int> s ; // max heap 
priority_queue<int, vector<int>, greater<int>> s2; // min heap.

using Intset = 	unordered_set<int>;
using StringIntPair = pair<string,int>;
using IntIntPair = pair<int, int>;

class A {
    public:
    int a, b, c;
    A(int x, int y, int z) {
        a = x;
        b = y;
        c = z;
    }
};
class Comp{
    public:
    bool operator()(A first, A second){
		return first.a > second.a;
    }
};
int main() {
    set<A, Comp> setd;
    setd.insert(A(1,2,3));
    setd.insert(A(2,3,4));
    setd.insert(A(3,4,5));
    setd.insert(A(4,5,6));
    // set.erase can be used with iterator, range of iterator and the value itself also.
    for(auto it : setd) cout<<it.a<<" "<<it.b<<" "<<it.c<<endl;


	map<A, int, Comp> my;
    my[A(1,2,3)] = 3;
    my[A(2,3,5)] = 32;
    my[A(3,4,5)] = 3;
    for(auto it : my) cout<<it.first.a<<" "<<it.second<<endl;


    return 0;
}

int main()
{
	pair<string, int> myPair;
	Intset P;
	IntIntPair my = {2,1};
	vector<int> v;
	v.push_back(3);
	unordered_map<int ,int> mymap;
	mymap[3]=2;
	mymap[3]=34;
	mymap[4]=1;
	mymap[5]=232;
	mymap[34]=32;
	mymap.count(5);
	map<string,int> map1;
	map1["parag"] = 443;
	map1["saini"] = 22;
	if(map1.count("saini"))
		cout<<"saini"<<"="<<map1["saini"];
	unordered_set<int> favouritenumber;	
	favouritenumber.insert(43);
	favouritenumber.insert(22);
	favouritenumber.insert(443);

	unordered_set<int> s;
	for(unordered_set<int>::iterator it = s.begin(); it != s.end(); ++it)
	{
		cout<<(*it)<<endl;
	}
	// same thing with another method.
	for(auto k:s)
		cout<<k<<" ";
	int arr[] = {1,2,3,4};
	int *p=arr;
	cout<<endl;
	for(auto k:mymap)
	{
		cout<<k.second<<" ";
	}

	set<int, greater<int>> s;
    s.insert(1);
    s.insert(2);
    s.insert(0);
    cout<<s.count(32)<<endl;
    cout<<s.erase(82)<<endl;
    map<int, int, greater<int>> x;
    x[1] = 3;
    x[5] = 13;
    x[21] = 32;
    cout<<x.count(21)<<endl;
    cout<<x.erase(21)<<endl;
    for(auto k: s) cout<<k<<" ";
    cout<<endl;
    for(auto k : x) cout<<k.first<< " "<<k.second<<endl;
	getch();
	return 0;
}
