#include<bits/stdc++.h>
using namespace std;

class Solution 
{
    int dx[4] = {1,-1,0,0};
    int dy[4] = {0,0,1,-1};
    public:

    //Function to find distance of nearest 1 in the grid for each cell.
	vector<vector<int>>nearest(vector<vector<int>>grid)
	{ 
	    int r = grid.size();
	    int c = grid[0].size();
	    
	    vector<vector<bool>> v(r,vector<bool>(c,0));
	    vector<vector<int>> ans(r,vector<int>(c,0));
	    queue<pair<int,int>> q;
	    
	    for(int i = 0; i < r; i++){
	        for(int j = 0; j < c; j++){
	            if(grid[i][j]){
	                q.push({i,j});
	                v[i][j] = 1;
	            }
	        }
	    }
	    
        int dist = 1;
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                int x = q.front().first;
                int y = q.front().second;
                q.pop();
                
                for(int d = 0; d < 4; d++){
                    int nx = x+dx[d];
                    int ny = y+dy[d];
                    
                    if(nx >= 0 && ny >= 0 && nx < r && ny < c && !v[nx][ny]){
                        ans[nx][ny]  = dist;
                        q.push({nx,ny});
                        v[nx][ny] = 1;
                    }
                }
            }
            ++dist;
        }
	    return ans;
	    
	}
};