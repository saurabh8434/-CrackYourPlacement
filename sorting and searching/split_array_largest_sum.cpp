#include<bits/stdc++.h>

class Solution {
public:

    bool isPossible(vector <int> &nums, int k, int maxSum){
        int currSum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++){
            if((currSum + nums[i]) > maxSum){
                k--;
                currSum = nums[i];

                if((k == 0) || (nums[i]>maxSum))
                    return false;

                continue;
            }

            currSum += nums[i];
        }

        return true;
    }

    int splitArray(vector<int>& nums, int k) {
        int sum = 0;
        int n = nums.size();

        for(int i=0; i<n; i++)
            sum += nums[i];

        int ans = sum;

        int low = 0;
        int high = sum;
        int mid;

        while(low <= high){
            mid = low + (high-low)/2;

            if(isPossible(nums, k, mid)){
                ans = min(ans, mid);
                high = mid-1;
            }
            else
                low = mid+1;
        }

        return ans;
    }
};