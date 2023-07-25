#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPowerOfTwo(int n) {

        int noOfOne = 0;

        while(n != 0){
            if(n&1 == 1)
                noOfOne++;

            if(noOfOne > 1)
                return false;

            n = n>>1;
        }

        return noOfOne==1;
    }
};