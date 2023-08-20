#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        if (arr.size() == 0)  return 0;
        int mod = pow(10, 9) + 7;
        stack<pair <int, int>> s1,s2;
        long long left[arr.size()],right[arr.size()];

        for(int i=0;i<arr.size();i++){
            int count=1;
            while(!s1.empty()&& s1.top().first>=arr[i]){
                count+=s1.top().second;
                s1.pop();
            }
            s1.push(make_pair(arr[i],count));
            left[i]=count;
        }

        for(int i=arr.size()-1;i>=0;i--){
            int count=1;
            while(!s2.empty()&& s2.top().first>arr[i]){
                count+=s2.top().second;
                s2.pop();
            }
            s2.push(make_pair(arr[i],count));
            right[i]=count;
        }

        long long ans=0;
        for(int i=0;i<arr.size();i++){
            ans = (ans + (left[i]*right[i]*arr[i])%mod)%mod;
        }
        return ans;
    }
};