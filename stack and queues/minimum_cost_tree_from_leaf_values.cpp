#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[40][40];

    int maxInRange(vector <int> &arr, int start, int end){
        int ans = 0;
        for(int i=start; i<=end; i++)
            ans = max(ans, arr[i]);

        return ans;
    }

    int solve(vector <int> &arr, int start, int end){
        if(start == end)
            return 0;

        if(end - start == 1)
            return arr[start] * arr[end];

        if(dp[start][end] != -1)
            return dp[start][end];

        int result = INT_MAX;
        for(int i=start; i<end; i++){
            int sum = solve(arr, start, i) + solve(arr, i+1, end);
            sum += maxInRange(arr, start, i) * maxInRange(arr, i+1, end);

            result = min(result, sum);
        }

        return dp[start][end] = result;
    }

    int mctFromLeafValues(vector<int>& arr) {
        memset(dp, -1, sizeof(dp));
        return solve(arr, 0, arr.size()-1);
    }
};