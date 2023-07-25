#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validSquare(vector<int>& p1, vector<int>& p2, vector<int>& p3, vector<int>& p4) {
        int x1 = p1[0];
        int y1 = p1[1];
        int x2 = p2[0];
        int y2 = p2[1];
        int x3 = p3[0];
        int y3 = p3[1];
        int x4 = p4[0];
        int y4 = p4[1];

        if((x1==x2 && y1==y2) || (x2==x3 && y2==y3) || (x3==x4 && y3==y4) || (x1==x4 && y1==y4) || (x1==x3 && y1==y3) || (x2==x4 && y2==y4))
            return false;

        map <double, int> m;

        double dist1 = sqrt((double)pow(x2-x1, 2) + (double)pow(y2-y1, 2));
        double dist2 = sqrt((double)pow(x3-x2, 2) + (double)pow(y3-y2, 2));
        double dist3 = sqrt((double)pow(x4-x3, 2) + (double)pow(y4-y3, 2));
        double dist4 = sqrt((double)pow(x3-x1, 2) + (double)pow(y3-y1, 2));
        double dist5 = sqrt((double)pow(x4-x1, 2) + (double)pow(y4-y1, 2));
        double dist6 = sqrt((double)pow(x4-x2, 2) + (double)pow(y4-y2, 2));

        m[dist1]++;
        m[dist2]++;
        m[dist3]++;
        m[dist4]++;
        m[dist5]++;
        m[dist6]++;

        return m.size()==2;
    }
};