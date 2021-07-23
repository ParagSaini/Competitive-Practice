#include<bits/stdc++.h>
using namespace std;
/* Following program is a C++ implementation of Rabin Karp 
Algorithm given in the CLRS book */
#include <bits/stdc++.h> 
using namespace std; 

// d is the number of characters in the input alphabet 
#define d 256 

/* pat -> pattern 
    txt -> text 
    q -> A prime number 
*/
void search(char pat[], char txt[], int q) 
{ 
    int M = strlen(pat); 
    int N = strlen(txt); 
    int i, j; 
    int p = 0; // hash value for pattern 
    int t = 0; // hash value for txt 
    int h = 1; 

    // The value of h would be "pow(d, M-1)%q" 
    for (i = 0; i < M - 1; i++) 
        h = (h * d) % q; 

    // Calculate the hash value of pattern and first 
    // window of text 
    for (i = 0; i < M; i++) 
    { 
        p = (d * p + pat[i]) % q; 
        t = (d * t + txt[i]) % q; 
    } 

    // Slide the pattern over text one by one 
    for (i = 0; i <= N - M; i++) 
    { 

        // Check the hash values of current window of text 
        // and pattern. If the hash values match then only 
        // check for characters on by one 
        if ( p == t ) 
        { 
            /* Check for characters one by one */
            for (j = 0; j < M; j++) 
            { 
                if (txt[i+j] != pat[j]) 
                    break; 
            } 

            // if p == t and pat[0...M-1] = txt[i, i+1, ...i+M-1] 
            if (j == M) 
                cout<<"Pattern found at index "<< i<<endl; 
        } 

        // Calculate hash value for next window of text: Remove 
        // leading digit, add trailing digit 
        if ( i < N-M ) 
        { 
            t = (d*(t - txt[i]*h) + txt[i+M])%q; 

            // We might get negative value of t, converting it 
            // to positive 
            if (t < 0) 
            t = (t + q); 
        } 
    } 
} 

/* Driver code */
int main() 
{ 
    char txt[] = "GEEKS FOR GEEKS"; 
    char pat[] = "GEEK"; 
    int q = 101; // A prime number 
    search(pat, txt, q); 
    return 0; 
}

// WE CAN MAKE MORE COMPLEX HASH FUNCTION, USING PRIME, EXAMPLE
/*  prime = 119;
    hashval += str[i] * pow(prime, i);
    and similar way define new recalculatehashVal function that will run in O(1) t.c
    */
// t.c best and average run time - O(n+m), worst case - O(nm), very rare, && s.c O(1)
int hashVal(string& str, int s, int e) {
    int val = 0;
    for(int i=s; i<=e; i++) val += (int)str[i];
    return val;
}
bool compareString(string& str, string& pat, int s) {
    int k1, k2 = s;
    for(int k1=0; k1<pat.length(); k1++) {
        if(str[k2++] != pat[k1]) return false;
    }
    return true;
}

int strStr(string str, string pat) {
    int l1 = str.length();
    int l2 = pat.length();
    
    if(l2 == 0) return 0;
    if(l2 > l1) return -1;
    
    int patHash = hashVal(pat, 0, l2-1);
    int curHash = hashVal(str, 0, l2-1);
    str.push_back(' ');       
    for(int i=0; i<=(l1-l2); i++) {
        if(curHash == patHash && compareString(str, pat, i)) return i;
        curHash = curHash - (int)str[i] + (int)str[i+l2];
        // (when i == (l1-l2) the extra space added to string str, is helpful to prevent the garbage value in str[i+l2])
    }
    str.pop_back();
    return -1;
}