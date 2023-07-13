#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {

        vector <pair <int, int>> v;

        int row = matrix.size();
        int col = matrix[0].size();

        for(int i=0;  i<row; i++){
            for(int j=0; j<col; j++){
                if(matrix[i][j] == 0)
                    v.push_back(make_pair(i,j));
            }
        }

        for(auto i: v){
            for(int j=0; j<col; j++){
                matrix[i.first][j] = 0;
            }

            for(int j=0; j<row; j++){
                matrix[j][i.second] = 0;
            }
        }

        
    }
};