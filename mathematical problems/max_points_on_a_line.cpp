#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxPoints(vector<vector<int>>& points) {
        int n = points.size();

        int ans = 1;

        for(int i=0; i<n-1; i++){
            int x1 = points[i][0];
            int y1 = points[i][1];

            map <double, int> m;

            for(int j=i+1; j<n; j++){
                int x2 = points[j][0];
                int y2 = points[j][1];

                double slope = (double)(x2-x1) / (double)(y2-y1);

                if(y2-y1==0)
                    m[abs(slope)]++;
                else
                    m[slope]++;
            }

            int temp = 0;

            for(auto it: m)
                temp = max(temp, it.second+1);

            ans = max(ans, temp);
        }

        return ans;
    }
};