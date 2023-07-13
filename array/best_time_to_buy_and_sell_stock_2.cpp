#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int t[2][30000];

    int solve(vector <int> &prices, bool buy, int index){
        if(index >= prices.size())
            return 0;

        if(t[buy][index] != -1)
            return t[buy][index];

        if(buy == 1){
            return t[buy][index] = max(solve(prices, buy, index+1), prices[index]+solve(prices, 0, index+1));
        }

        return t[buy][index] = max(solve(prices, buy, index+1), solve(prices, 1, index+1)-prices[index]);
    }

    int tabular(vector <int> &prices){
        int n = prices.size();
        vector <vector <int>> dp(n+1, vector <int> (2, 0));

        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
                if(j==1){
                    dp[i][j] = max(dp[i+1][j], dp[i+1][0]+prices[i]);
                }
                else
                    dp[i][j] = max(dp[i+1][j], dp[i+1][1]-prices[i]);
            }
        }

        return dp[0][0];
    }

    int optimized(vector <int> &prices){
        vector <int> curr(2, 0);
        vector <int> next(2, 0);
        int n = prices.size();

        for(int i=n-1; i>=0; i--){
            for(int j=1; j>=0; j--){
                int profit = 0;
                if(j==1){
                    profit = max(next[1], next[0]-prices[i]);
                }
                else
                    profit = max(next[0], next[1]+prices[i]);

                curr[j] = profit;
            }

            next = curr;
        }

        return next[1];
    }

    int maxProfit(vector<int>& prices) {
        memset(t, -1, sizeof(t));
        int ans = optimized(prices);

        return ans;
    }
};