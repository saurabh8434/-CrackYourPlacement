#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    string longestCommonPrefix(vector<string>& strs) {

        string ans = "";

        if(strs.size() == 1)
            return strs[0];

        sort(strs.begin(), strs.end());
        int n = strs.size();

        string start = strs[0];
        string end = strs[n-1];

        for(int i=0; i<min(start.size(), end.size()); i++){
            if(start[i] != end[i])
                return ans;

            ans += start[i];
        }

        return ans;
    }
};