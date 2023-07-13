#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    
    int maxArea(vector<int>& height) {

        int n = height.size();
        int i=0;
        int j=n-1;
        int ans = 0;

        while(i < j){
            int temp_ans = (j-i) * min(height[j], height[i]);

            ans = max(ans, temp_ans);

            if(height[i] < height[j])
                i++;
            else
                j--;
        }

        return ans;
    }
};