#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isPalindrome(int x) {
        if(x < 0)
            return false;

        long long y = 0;
        int temp = x;

        while(temp != 0){
            y = (long long)(y*10) + (temp%10);
            temp = temp/10;
        }

        return y == x;
    }
};