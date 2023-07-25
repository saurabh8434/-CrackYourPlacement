#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves(vector<int>& nums) {

        int mini = INT_MAX;

        for(auto i: nums)
            mini = min(mini, i);

        int ans = 0;

        for(auto i: nums)
            ans += i-mini;

        return ans;
    }
};