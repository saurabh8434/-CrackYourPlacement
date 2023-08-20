#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        map <int, int> m;
        vector <int> result;
        
        for(int i=0; i<nums1.size(); i++){
            for(int j=0; j<nums2.size(); j++){
                if(nums2[j] == nums1[i]){
                    m[nums1[i]] = j;
                    break;
                }
            }
        }
        
        for(int i=0; i<nums1.size(); i++){
            int ans = -1;
            for(int j = m[nums1[i]]+1; j<nums2.size(); j++){
                if(nums2[j] > nums1[i]){
                    ans = nums2[j];
                    break;
                }
            }
            result.push_back(ans);
        }
        
        return result;
    }
};