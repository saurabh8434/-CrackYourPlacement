#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    int nextNumber(int n){
        int newNumber = 0;

        while(n != 0){
            int temp = n%10;

            newNumber += temp*temp;

            n = n/10;
        }

        return newNumber;
    }

    bool isHappy(int n) {
        set <int> s;

        while(n != 1 && !s.count(n)){
            s.insert(n);
            n = nextNumber(n);
        }

        return n==1;
    }
};