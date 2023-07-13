#include<bits/stdc++.h>
using namespace std;

class Solution {
public:

    bool search(int index, int row, int col, vector <vector <char>> &board, string word){

        if(index == word.size())
            return true;

        if(row < 0 || row >= board.size() || col < 0 || col >= board[0].size() || word[index] != board[row][col] || board[row][col] == '.')
            return false;

        int temp = board[row][col];
        board[row][col] = '.';

        if(search(index+1, row+1, col, board, word) || search(index+1, row, col-1, board, word) || search(index+1, row, col+1, board, word) || search(index+1, row-1, col, board, word))
            return true;

        board[row][col] = temp;
        
        return false;
    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int row = board.size();
        int col = board[0].size();

        for(int i=0; i<row; i++){
            for(int j=0; j<col; j++){
                if(search(0, i, j, board, word))
                    return true;
                
            }
        }

        return false;
    }
};