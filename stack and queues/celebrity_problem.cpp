#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    public:
    
    bool knows(vector <vector <int>> &M, int a, int b){
        if(M[a][b]==1)
            return true;
            
        return false;
    }
    
    int celebrity(vector<vector<int> >& M, int n) 
    {
        stack <int> s;
        
        for(int i=0; i<n; i++)
            s.push(i);
            
        while(s.size()>1){
            int a = s.top();
            s.pop();
            
            int b = s.top();
            s.pop();
            
            if(knows(M,a,b))
                s.push(b);
            else
                s.push(a);
        }
        
        
    }
};