#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {

        if(nums.size() == 1)
            return 0;

        if(nums.size() == 2)
            return nums[0]>nums[1] ? 0 : 1;
        
        int i = 1;
        int j = nums.size()-2; 

        while(i <= j){
            int mid = (i + j) / 2;

            if(nums[mid] > nums[mid+1] && nums[mid] > nums[mid-1])
                return mid;
            else if(nums[mid] > nums[mid+1])
                j = mid-1;
            else
                i = mid+1;
        }       

        if(nums[0] > nums[1])
            return 0;
            
        if(nums[nums.size()-1] > nums[nums.size()-2])
            return nums.size()-1;

        return -1;
    }
};