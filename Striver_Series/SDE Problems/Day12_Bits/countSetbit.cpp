
// t.c O(n) && s.c O(n)
int countSetBits(int n)
{
    // shifting of number >> 1 means dividing it by 2;
    int ans = 0;
    int arr[n+1];
    arr[0] = 0;
    for(int i=1; i<=n; i++) {
        if(i%2 == 0) {     // Lsb is set to '0'
            arr[i] = arr[i/2];
        }else {         // lsb is set bit
            arr[i] = 1 + arr[i/2];
        }
    }
    for(int i=0; i<=n; i++) ans += arr[i];
    return ans;
}

// t.c O(nlog(n)) && s.c O(1)
int countBits(int n) {
    if(n == 1) return 1;
    int count = 0;
    while(n != 0) {
        count += (n&1);
        n = (n >> 1);
    }
    return count;
}
int countSetBits(int n)
{
    int ans = 0;
    for(int i=1; i<=n; i++) ans += countBits(i);
    return ans;
}