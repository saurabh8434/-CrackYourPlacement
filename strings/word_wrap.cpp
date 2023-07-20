#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[1001][2001];

    int solve(vector <int> &nums, int rem, int index, int k){
        if(index == nums.size())
            return 0;
            
        if(dp[index][rem] != -1)
            return dp[index][rem];
            
        if(nums[index] > rem){
            return dp[index][rem] = (1+rem) * (1+rem) + solve(nums, k-nums[index]-1, index+1, k);
        }
        else{
            return dp[index][rem] = min((1+rem) * (1+rem) + solve(nums, k-nums[index]-1, index+1, k), solve(nums, rem-nums[index]-1, index+1, k));
        }
    }
    
    int solveWordWrap(vector<int>nums, int k) 
    { 
        // Code here
        memset(dp, -1, sizeof(dp));
        return solve(nums, k, 0, k);
        
    } 
};