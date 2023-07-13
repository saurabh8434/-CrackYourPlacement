#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int n = nums.size();
        int temp_index = 1;

        for(int i=1; i<n; i++){
            if(nums[i] != nums[i-1])
                nums[temp_index++] = nums[i];
        }

        return temp_index;
    }
};