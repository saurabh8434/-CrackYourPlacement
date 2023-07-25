#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumProduct(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();

        int ans = INT_MIN;
        int temp = 1;

        for(int i=n-1; i>=n-3; i--){
            temp *= nums[i];
        }

        ans = max(ans, temp);

        temp = 1;
        temp *= nums[0];
        temp *= nums[1];
        temp *= nums[n-1];

        ans = max(ans, temp);

        return ans;
    }
};