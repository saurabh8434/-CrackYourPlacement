#include<bits/stdc++.h>
using namespace std;

bool findPair(int arr[], int size, int n){
    //code
    map <int, int> m;
    
    for(int i=0; i<size; i++){
        if(m.find(arr[i]+n) != m.end() || m.find(arr[i]-n) !=  m.end())
            return true;
            
        m[arr[i]]++;
    }
    
    return false;
}