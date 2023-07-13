#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector <int> max_right_area(vector <int> heights){
        stack <int> s;
        vector <int> ans(heights.size(), -1);

        for(int i=heights.size()-1; i>=0; i--){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }

            if(!s.empty() && heights[s.top()] < heights[i]){
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    vector <int> max_left_area(vector <int> heights){
        stack <int> s;
        vector <int> ans(heights.size(), -1);

        for(int i=0; i<heights.size(); i++){
            while(!s.empty() && heights[s.top()]>=heights[i]){
                s.pop();
            }

            if(!s.empty() && heights[s.top()] < heights[i]){
                ans[i] = s.top();
            }

            s.push(i);
        }

        return ans;
    }

    int largestRectangleArea(vector<int>& heights) {
        vector <int> right_index = max_right_area(heights);
        vector <int> left_index = max_left_area(heights);
        int ans = 0;

        for(int i=0; i<heights.size(); i++){
            int max_right = right_index[i];
            int max_left = left_index[i];

            if(max_right == -1)
                max_right = heights.size();

            int temp_ans = (max_right-max_left-1)* heights[i];

            ans = max(ans, temp_ans);
        }

        return ans;
    }
};