#include <bits/stdc++.h>
using namespace std;

void printCombination(int a[], int n, int r, int index, int count, vector<int> temp){
    if(count == r){
        for(int i=0; i<temp.size(); i++){
            cout<<temp[i]<<" ";
        }
        cout<<endl;
        return;
    }

    if(index >= n)
        return;

    printCombination(a, n, r, index+1, count, temp);
    
    temp.push_back(a[index]);
    printCombination(a, n, r, index+1, count+1, temp);
}

 
int main()
{
    int arr[] = {1, 2, 3, 4, 5};
    int r = 3;
    int n = sizeof(arr)/sizeof(arr[0]);
    vector <int> temp;
    printCombination(arr, n, r, 0, 0, temp);
    return 0;
}