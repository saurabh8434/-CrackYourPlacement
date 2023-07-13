#include<bits/stdc++.h>
using namespace std;

int findMinDiff(int arr[], int n, int m){
    if(m==0 || n==0)
        return 0;

    sort(arr, arr+n);

    int i=0;
    int j=m-1;
    int ans = INT_MAX;

    while(j<n){
        ans = min(ans, arr[j]-arr[i]);
        j++;
        i++;
    }

    return ans;
}

int main()
{
    int arr[] = { 12, 4,  7,  9,  2,  23, 25, 41, 30, 40, 28, 42, 30, 44, 48, 43, 50 };
    int m = 7; 
    int n = sizeof(arr) / sizeof(arr[0]);
    cout << "Minimum difference is "<< findMinDiff(arr, n, m);
    return 0;
}