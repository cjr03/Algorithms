#include <algorithm>
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int m = matrix.size(), n = matrix[0].size();
        vector<int> zeroRows, zeroCols;
        for(int row = 0; row < m; ++row){
            for(int col = 0; col < n; ++col){
                if(matrix[row][col] == 0){
                    if(find(zeroRows.begin(), zeroRows.end(), row) == zeroRows.end()){
                        zeroRows.push_back(row);
                    }
                    if(find(zeroCols.begin(), zeroCols.end(), col) == zeroCols.end()){
                        zeroCols.push_back(col);
                    }
                }
            }
        }
        for(int row : zeroRows){
            for(int col = 0; col < n; ++col){
                matrix[row][col] = 0;
            }
        }
        for(int col : zeroCols){
            for(int row = 0; row < m; ++row){
                matrix[row][col] = 0;
            }
        }
    }
};
