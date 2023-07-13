#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        
    sort(nums.begin(),nums.end());
    
    vector<vector<int>> ans;
    int len = nums.size();
    
    if(len == 0) return ans; 
    
	
    for(int i=0;i<len;i++){
        for(int j=i+1;j<len;j++){
            int front = j+1, back= len-1;
            long long check_target = (long long)target - nums[i] - nums[j];
            while(front < back){
				
                long long curr_sum = nums[front] + nums[back];
                if(curr_sum == check_target){
                    ans.push_back({nums[i],nums[j],nums[front],nums[back]});
					
                    
                    while(front < back and nums[front] == nums[front+1]) front++;
                    while(front < back and nums[back] == nums[back-1]) back--;
                    
                    front++; back--;
                }
                else if(curr_sum > check_target) back--;
                else front++;
            }
			 
            while(j+1 < len and nums[j] == nums[j+1]) j++;
        }
		  
         while(i+1 < len and nums[i] == nums[i+1]) i++;
    }
    
    return ans;
    }
};