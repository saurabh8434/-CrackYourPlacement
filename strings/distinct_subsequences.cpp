#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int dp[1000][1000];

    int solve(string s, string t, int ind1, int ind2){
        if(ind2 < 0)
            return 1;

        if(ind1 < 0)
            return 0;

        if(dp[ind1][ind2] != -1)
            return dp[ind1][ind2];

        if(s[ind1] == t[ind2]){
            return dp[ind1][ind2] = solve(s, t, ind1-1, ind2-1) + solve(s, t, ind1-1, ind2);
        }
        else
            return dp[ind1][ind2] = solve(s, t, ind1-1, ind2);
    }

    int numDistinct(string s, string t) {
        memset(dp, -1, sizeof(dp));
        return solve(s, t, s.size()-1, t.size()-1);
    }
};