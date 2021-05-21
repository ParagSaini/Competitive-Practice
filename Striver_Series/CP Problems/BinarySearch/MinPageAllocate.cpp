#include<bits/stdc++.h>
using namespace std;

bool isPossibleToAllocate(int arr[], int n, int m, long long minPage) {

    /* In this function we are trying to allocate the minPages in m students such that each students should get pages <= minPages, because our maximum of Pages among all students should be <= minPage. so we are trying to allocate the atmost minPages to every students. */

    int studentsRequired = 1;
    long long sum = 0;

    for(int i=0; i<n; i++) {
        if((long long)arr[i] > minPage) {  // you can't skip that book pages, the allocation should be in the continous manner.
            return false;
        }
        if(sum + (long long)arr[i] > minPage) {
            studentsRequired++;
            sum = (long long)arr[i];
        } else {
            sum += (long long )arr[i];
        }
    }
    if(studentsRequired > m) return false;    // number of students required are more than the given students, so not possible to allocate the books.
    return true;
}

int findPages(int arr[], int n, int m) {
    if(n < m) return -1;
    int minPages = INT_MAX;
    long long maxPages = 0, ans = LLONG_MAX;
    for(int i=0; i<n; i++) {
        minPages = min(minPages, arr[i]);
        maxPages += (long long)arr[i];
    }

    while(minPages <= maxPages) {
        long long mid = ((long long)minPages + maxPages)/2;

        if(isPossibleToAllocate(arr, n, m, mid)) {
            ans = min(ans, mid);
            maxPages = mid-1;
        } else {
            minPages = mid+1;
        }
    }
    return (int) ans;

}
int main() {
    int arr[] = {12, 34, 67, 90};
    cout<<findPages(arr, 4, 2);
    return 0;
}