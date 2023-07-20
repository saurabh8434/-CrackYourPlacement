#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string reverseWords(string s) {
        stack <string> st;
        string ans;

        for(int i=0; i<s.size(); i++){
            while(s[i]==' '){
                i++;
            }

            string word = "";
            while(i<s.size() && s[i]!=' '){
                word += s[i];
                i++;
            }

            if(word.size()>0)
                st.push(word);
        }

        while(!st.empty()){
            ans += st.top();
            st.pop();

            if(!st.empty())
                ans += ' ';
        }

        return ans;
    }
};