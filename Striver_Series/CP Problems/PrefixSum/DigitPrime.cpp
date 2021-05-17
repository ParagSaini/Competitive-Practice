#include<bits/stdc++.h>
using namespace std;
class var {
	public:
	bool isPrime, isDigitPrime;
	var(bool a, int b) {
		isPrime = a;
		isDigitPrime = b;
	}
};

bool digitPrime(int num, const vector<var>& primeArr) {
	int sum = 0;
	while(num != 0) {
		sum += (num % 10);
		num /= 10;
	}
	if(primeArr[sum].isPrime) return true;
	return false;
}

void preComputePrimes(vector<var>& primeArr) {
	int n = primeArr.size() - 1; // 10^6
	for(int i=2; i<=n; i++) {
		if(primeArr[i].isPrime) {
			if(digitPrime(i, primeArr)) {
				primeArr[i].isDigitPrime = true;
			}
			for(long long j=(long long)i*i; j<=(long long)n; j+=(long long)i) {
				primeArr[(int)j].isPrime = false;
			}
		}
	}
}
void preComputeDigitPrimeCount(vector<int>& digitPrimeArr, const vector<var>& primeArr) {
	int n = digitPrimeArr.size() -1; // n = 10^6
	digitPrimeArr[0] = 0;
	for(int i=1; i<=n; i++) {
		if(primeArr[i].isDigitPrime) {
			digitPrimeArr[i] = digitPrimeArr[i-1] + 1;
		} else {
			digitPrimeArr[i] = digitPrimeArr[i-1];
		}
	}
}
int countDigitPrime(int i, int j, const vector<int>& digitPrimeArr, const vector<var>& primeArr) {
	int count = 0;
	if(primeArr[i].isDigitPrime) count = 1;
	return (digitPrimeArr[j] - digitPrimeArr[i] + count);
}

int main() {
	int n;   // 5*10^5
	cin>>n;
	int maxInd = pow(10,6)+1;
	vector<var> primeArr(maxInd, var(true, false));
	vector<int> digitPrimeArr(maxInd);   // 0 to 10^6
	primeArr[1].isPrime = false;
	preComputePrimes(primeArr);
	preComputeDigitPrimeCount(digitPrimeArr, primeArr);
	vector<int> arr;
	while(n--) {
		int i,j;           // 0<i<=j<=10^6
		cin>>i>>j;
		arr.push_back(countDigitPrime(i,j, digitPrimeArr, primeArr));
	}
	for(auto it : arr) cout<<it<<endl;
	return 0;
}