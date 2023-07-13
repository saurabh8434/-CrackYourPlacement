#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        
        vector<vector<int>> ans;
        int n=nums.size();
        sort(nums.begin(), nums.end());
        for(int i=0;i<n-2;i++) 
        {
            if(i==0 or (i>0 and nums[i]!=nums[i-1]))  
            {
                int target = -nums[i]; 
				
				
                int j=i+1,k=n-1;
                while(j<k) 
				{
                    if(nums[j]+nums[k]==target) 
                    {
                        vector<int> temp;
                        temp.push_back(nums[i]);
                        temp.push_back(nums[j]);
                        temp.push_back(nums[k]);
                        ans.push_back(temp);
                        
                        while(j<k and nums[j]==nums[j+1]) j++;
                        while(j<k and nums[k]==nums[k-1]) k--;
                        j++,k--;
                     } 
                     else if(nums[j]+nums[k]<target) 
                            j++;
                     else k--;
                }
				
            }
        }
        return ans;
        
    }
};