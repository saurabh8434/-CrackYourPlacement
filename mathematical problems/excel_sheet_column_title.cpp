#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string convertToTitle(int columnNumber) {
        string result = "";

        while(columnNumber != 0){
            result = char('A' + (columnNumber-1)%26) + result;
            columnNumber = (columnNumber-1)/26;
        }

        return result;
    }
};