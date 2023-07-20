#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    string minWindow(string s, string t) {

        if(t.size() > s.size())
            return "";

        string ans = "";
        int low_index = 0;
        int str_size = 0;
        int i=0;
        int j=0;
        int size = INT_MAX;
        map <char, int> m;

        for(auto k: t)
            m[k]++;

        int count = m.size();

        while(j<=s.size()){
            while(count == 0){
                if(j-i < size){
                    size = j-i;
                    low_index = i;
                    str_size = j-i;
                }

                if(m.find(s[i])!=m.end()){
                    m[s[i]]++;
                    if(m[s[i]]>0)
                        count++;
                }
                i++;
                continue;
            }

            if(m.find(s[j])!=m.end()){
                m[s[j]]--;

                if(m[s[j]]==0)
                    count--;
            }
            j++;
        }

        if(str_size != 0){
            ans += s.substr(low_index, str_size);
        }

        return ans;
    }
};