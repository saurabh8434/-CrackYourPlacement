#include<bits/stdc++.h>
using namespace std;

int ceilSearch(int *arr, int start, int end, int x){
    int index = -1;
    int mid;

    while(start <= end){
        mid = start + (end-start)/2;

        if(arr[mid] > x){
            index = mid;
            end = mid-1;
        }
        else{
            start = mid+1;
        }
    }

    return index;
}

int main()
{
    int arr[] = { 1, 2, 8, 10, 10, 12, 19 };
    int n = sizeof(arr) / sizeof(arr[0]);
    int x = 8;
    int index = ceilSearch(arr, 0, n - 1, x);
    if (index == -1)
        cout << "Ceiling of " << x
             << " doesn't exist in array ";
    else
        cout << "ceiling of " << x << " is " << arr[index];
 
    return 0;
}