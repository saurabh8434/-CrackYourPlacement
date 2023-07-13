#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int profit = 0;
        int buy = prices[0];
        int n = prices.size();

        for(int i=1; i<n; i++){
            if(prices[i] < buy)
                buy = prices[i];
            else{
                profit = max(profit, prices[i]-buy);
            }
        }

        return profit;
    }
};