#include<bits/stdc++.h>
using namespace std;

class Solution{
  public:
    // Function to find the number of islands.
    
    void dfs(vector <vector <char>> &grid, int row, int col, vector<vector<bool>> &isVisited){
        isVisited[row][col] = true;
            
        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i==0 && j==0)
                    continue;
                    
                if(row+i>=0 && row+i<grid.size() && col+j>=0 && col+j<grid[0].size() && !isVisited[row+i][col+j] && grid[row+i][col+j]=='1')
                    dfs(grid, row+i, col+j, isVisited);
            }
        }
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // Code here
        int n = grid.size();
        int m = grid[0].size();
        int count = 0;
        
        vector <vector<bool>> isVisited(n, vector<bool>(m, false));
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(!isVisited[i][j] && grid[i][j]=='1'){
                    count++;
                    dfs(grid, i, j, isVisited);
                }
            }
        }
        
        return count;
    }
};