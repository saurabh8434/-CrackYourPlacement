#include<bits/stdc++.h>
using namespace std;

class Solution{
public:

    void dfs(int n, int m, int row, int col, vector <vector <char>> &mat, vector <vector <bool>> &isVisited){
        isVisited[row][col] = true;
        
        if(row+1<n && !isVisited[row+1][col] && mat[row+1][col]=='O')
            dfs(n, m, row+1, col, mat, isVisited);
            
        if(row-1>=0 && !isVisited[row-1][col] && mat[row-1][col]=='O')
            dfs(n, m, row-1, col, mat, isVisited);
            
        if(col+1<m && !isVisited[row][col+1] && mat[row][col+1]=='O')
            dfs(n, m, row, col+1, mat, isVisited);
            
        if(col-1>=0 && !isVisited[row][col-1] && mat[row][col-1]=='O')
            dfs(n, m, row, col-1, mat, isVisited);
    }
    
    vector<vector<char>> fill(int n, int m, vector<vector<char>> mat)
    {
        // code here
        
        vector <vector <bool>> isVisited(n, vector <bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if((i==0 || i==n-1 || j==0 || j==m-1) && mat[i][j]=='O' && !isVisited[i][j]){
                    dfs(n, m, i, j, mat, isVisited);
                }
            }
        }
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(mat[i][j]=='O' && !isVisited[i][j])
                    mat[i][j] = 'X';
            }
        }
        
        return mat;
    }
};