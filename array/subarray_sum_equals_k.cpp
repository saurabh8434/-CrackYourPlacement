#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
        int n = nums.size();
        int count = 0;
        map <int, int> m;
        int sum = 0;
        m[sum] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int find = sum-k;
            
            if(m.find(find) != m.end()){
                count += m[find];
            }

            m[sum]++;
        }

        return count;
    }
};