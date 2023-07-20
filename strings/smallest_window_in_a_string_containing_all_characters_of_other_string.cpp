#include<bits/stdc++.h>
using namespace std;

class Solution
{
    public:
    //Function to find the smallest window in the string s consisting
    //of all the characters of string p.
    string smallestWindow (string s, string p)
    {
        if(p.length()>s.length())
        return "-1";
        if(s==p)
        return s;
        int n=s.length();
        vector<int> v(26,0);
        int c=0;
        for(char i:p)
        {
            if(v[i-'a']==0)c++;
            v[i-'a']++;
        }
        int i=0,j=0,start=-1,len=INT_MAX;
        while(j<n)
        {
            v[s[j]-'a']--;
            if(v[s[j]-'a']==0)c--;
            if(c==0)
            {
                while(c==0)
                {
                    if(len>(j-i+1))
                    {
                        len=j-i+1;
                        start=i;
                    }
                    v[s[i]-'a']++;
                    if(v[s[i]-'a']==1)
                    c++;
                    i++;
                }
            }
            j++;
        }
        if(len==INT_MAX)
        return "-1";
        return s.substr(start,len);
    }
};