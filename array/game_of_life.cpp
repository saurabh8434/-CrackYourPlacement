#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool isLive(vector <vector <int>> board, int row, int col){
        int numOne=0;
        int n = board.size();
        int m = board[0].size();

        for(int i=-1; i<=1; i++){
            for(int j=-1; j<=1; j++){
                if(i==0 && j==0)
                    continue;
                int r = row+i;
                int c = col+j;

                if(r>=0 && r<n && c>=0 && c<m && board[r][c]==1)
                    numOne++;
            }
        }

        if(board[row][col] == 0 && numOne==3)
            return true;
        else if(board[row][col] == 1 && (numOne==2 || numOne==3))
            return true;
        else
            return false;
    }

    void gameOfLife(vector<vector<int>>& board) {
        int n = board.size();
        int m = board[0].size();

        vector <vector <int>> clone_board(n, vector <int>(m));

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                clone_board[i][j] = board[i][j];
            }
        }

        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(clone_board[i][j] == 1 && !isLive(clone_board, i, j))
                    board[i][j] = 0;
                else if(clone_board[i][j] == 0 && isLive(clone_board, i, j))
                    board[i][j] = 1;
            }
        }
    }
};