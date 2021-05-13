#include<stdio.h>
#include<bits/stdc++.h>
using namespace std;

// This problem is somewhat different from the pattern finding problem, because there is no repetation in any character all character are different SUVO and SUVOJIT. whereas in Pattern finding, pattern may be have repetitive characters also.

// t.c O(n) s.c O(1)
// it is not bad to hard Code, when you know for sure that something always remain the same.
int main() {
	int t;
	cin>>t;
	getchar();
	while(t--) {
		string str;
		getline(cin, str);
		int l = str.length();
		int a = 0, b = 0;
		for(int i=0; i<=l-4; i++) {
			if(str[i] == 'S' && str[i+1] == 'U' && str[i+2] == 'V' && str[i+3] == 'O') a++;
		}
		for(int i=0; i<=l-7; i++) {
			if(str[i] == 'S' && str[i+1] == 'U' && str[i+2] == 'V' && str[i+3] == 'O' && str[i+4] == 'J' && str[i+5] == 'I' && str[i+6] == 'T') b++;
		}
		cout<<"SUVO = "<<(a-b)<<", SUVOJIT = "<<b<<endl;

	}
}

// t.c O(2n) s.c O(1);
int countSubstr(string str, string pat) {
	int count = 0;
	size_t found = str.find(pat);
	while(found != string::npos) {
		count++;
		found = str.find(pat, found+pat.length());
	}
	return count;
}
int main() {
	int t;
	cin>>t;
	getchar();  // to empty the buffer.
	while(t--) {
		string str;
		getline(cin, str);
		int a = countSubstr(str, "SUVO");
		int b = countSubstr(str, "SUVOJIT");
		cout<<"SUVO = "<<(a-b)<<", SUVOJIT = "<<b<<endl;
	}
}

// t.c O(n), s.c O(1)
void checkName(char* arr, int* i, char* name, int* count1, int* count2) {
	int i1 = 0;
	for(; arr[*i] != '\0' && name[i1] != '\0'; (*i)++, i1++) {
		if(arr[*i] != name[i1]) break;
	}
	if(name[i1] == '\0') (*count2)++;
	else if(i1 > 3) (*count1)++;   // this is also tackle the case when arr[*i] == '\0'. 

}
void countName(char* arr) {   
	char name2[] = "SUVOJIT";
	int count1 = 0, count2 = 0;
	int i=0;
	while(arr[i] != '\0') {
		if(arr[i] == name2[0]) {
			checkName(arr, &i, name2, &count1, &count2);
            continue;
		}
        i++;
	}
	printf("SUVO = %d, SUVOJIT = %d", count1, count2);
}
int main() {
	int t;
	scanf("%d", &t);
	getchar();
	while(t--) {
		char arr[150];
        // getting the string input.
		fgets(arr, sizeof(arr), stdin);
		countName(arr);
		printf("\n");
	}
}