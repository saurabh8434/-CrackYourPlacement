#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n = cardPoints.size();

        if(n==1)
            return cardPoints[0];

        int sum = 0;

        for(int i=0; i<n; i++)
            sum += cardPoints[i];

        int i=0;
        int j=0;
        int ans = 0;
        int curr_sum = 0;

        while(j <= n-k-1){
            curr_sum += cardPoints[j];
            j++;
        }

        ans = max(ans, sum-curr_sum);
        while(j<n){
            curr_sum -= cardPoints[i];
            curr_sum += cardPoints[j];
            ans = max(ans, sum-curr_sum);
            i++;
            j++;
        }

        return ans;
    }
};