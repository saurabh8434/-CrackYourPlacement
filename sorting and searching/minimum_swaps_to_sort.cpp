#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    //Function to find the minimum number of swaps required to sort the array. 
	int minSwaps(vector<int>&nums)
	{
	    // Code here
	    int n = nums.size();
	    unordered_map <int, int> m;
	    vector <int> temp = nums;
	    
	    sort(temp.begin(), temp.end());
	    
	    for(int i=0; i<n; i++)
	        m[temp[i]] = i;
	        
	   int ans = 0;
	   
        int j = 0;
        
        while(j<n){
            if(j != m[nums[j]]){
                swap(nums[j], nums[m[nums[j]]]);
                ans++;
            }
            else
                j++;
        }
	   
	   return ans;
	}
};