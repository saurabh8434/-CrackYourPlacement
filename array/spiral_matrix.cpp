#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        
        int total = row * col;
        int count = 0;
        int rowStart = 0;
        int colStart = 0;
        int rowEnd = row-1;
        int colEnd = col-1;
        vector <int> ans;

        while(count < total){
            for(int i=colStart; count<total && i<=colEnd; i++){
                ans.push_back(matrix[rowStart][i]);
                count++;
            }
            rowStart++;

            for(int i=rowStart; count<total && i<=rowEnd; i++){
                ans.push_back(matrix[i][colEnd]);
                count++;
            }
            colEnd--;

            for(int i=colEnd; count<total && i>=colStart; i--){
                ans.push_back(matrix[rowEnd][i]);
                count++;
            }
            rowEnd--;

            for(int i=rowEnd; count<total && i>=rowStart; i--){
                ans.push_back(matrix[i][colStart]);
                count++;
            }
            colStart++;
        }

        return ans;
    }
};