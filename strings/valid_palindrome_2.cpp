#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isPalindrome(string s, int start, int end){

        while(start < end){
            if(s[start] != s[end])
                return false;

            start++;
            end--;
        }

        return true;
    }

    bool validPalindrome(string s) {

        int i=0;
        int j = s.size()-1;

        if(isPalindrome(s, 0, j))
            return true;

        while(i<j){
            if(s[i]!=s[j]){
                return isPalindrome(s, i, j-1) || isPalindrome(s, i+1, j);
            }
            i++;
            j--;
        }

        return true;
    }
};