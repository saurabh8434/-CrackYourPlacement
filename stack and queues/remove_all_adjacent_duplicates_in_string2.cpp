#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack <pair<char,int>> st;
        int n = s.size();
        string res = "";

        for(int i=n-1; i>=0; i--){

            if(!st.empty() && st.top().first==s[i]){
                if(1+st.top().second >= k){
                    int temp = k-1;
                    while(temp--){
                        st.pop();
                    }
                }
                else{
                    st.push({s[i],st.top().second+1});
                }
            }
            else{
                st.push({s[i],1});
            }
        }

        while(!st.empty()){
            res += st.top().first;
            st.pop();
        }

        return res;
    }
};
