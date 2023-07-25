#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string addBinary(string a, string b) {
        string ans;
        int i=a.length()-1;
        int j=b.length()-1;
        char carry = '0';

        while(i>=0 && j>=0){
            if(a[i]=='1' && b[j]=='1' && carry == '1'){
                ans += '1';
                carry = '1';
            }
            else if((a[i]=='1' && b[j]=='1') || (a[i]=='1' && carry=='1') || (b[j]=='1' && carry=='1')){
                ans += '0';
                carry = '1';
            }
            else if(a[i]=='1' || b[j]=='1' || carry =='1'){
                ans += '1';
                carry = '0';
            }
            else{
                ans += '0';
                carry = '0';
            }
            j--;
            i--;
        }

        while(i >=0 ){
            if(a[i]=='1' && carry == '1'){
                ans += '0';
                carry = '1';
            }
            else if(a[i]=='1' || carry == '1'){
                ans += '1';
                carry = '0';
            }
            else{
                ans += '0';
                carry = '0';
            }
            i--;
        }

        while(j >=0 ){
            if(b[j]=='1' && carry == '1'){
                ans += '0';
                carry = '1';
            }
            else if(b[j]=='1' || carry == '1'){
                ans += '1';
                carry = '0';
            }
            else{
                ans += '0';
                carry = '0';
            }
            j--;
        }

        if(carry != '0')
            ans += carry;

        reverse(ans.begin(), ans.end());

        return ans;
    }
};