#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int pivot(vector <int> &nums){
        int start=0;
        int end=nums.size()-1;
        int n = nums.size();
        int mid;

        while(start <= end){
            mid = start + (end-start)/2;

            if(mid!=0 && nums[mid]<nums[mid-1] && nums[mid]<nums[(mid+1)%n])
                return mid;
            else if(nums[mid]>=nums[0])
                start = mid+1;
            else
                end = mid;
        }

        return -1;
    }

    int binary_search(vector <int> &nums, int low, int high, int target){

        int mid;

        while(low <= high){
            mid = low + (high-low)/2;

            if(nums[mid]==target)
                return mid;
            else if(nums[mid]<target)
                low = mid+1;
            else
                high = mid-1;
        }

        return -1;
    }
    
    int search(vector<int>& nums, int target) {
        int n = nums.size();

        if(nums[0]<=nums[n-1])
            return binary_search(nums, 0, n-1, target);

        int pivot_index = pivot(nums);

        if(target==nums[pivot_index])
            return pivot_index;
        else if(target >= nums[0])
            return binary_search(nums, 0, pivot_index-1, target);
        else
            return binary_search(nums, pivot_index+1, n-1, target);

    }
};