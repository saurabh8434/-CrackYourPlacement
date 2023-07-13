#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int count = 0;
        int sum = 0;
        int n = nums.size();
        map <int, int> m;
        m[0] = 1;

        for(int i=0; i<n; i++){
            sum += nums[i];
            int rem = sum % k;

            if(rem < 0)
                rem += k;

            if(m.find(rem) != m.end())
                count += m[rem];

            m[rem]++;
        }

        return count;
    }
};