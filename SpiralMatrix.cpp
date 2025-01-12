class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int rowMin = 0, colMin = 0, rowMax = matrix.size() - 1, colMax = matrix[0].size() - 1, row = 0, col = 0;
        vector<int> spiral;
        while(1){
            while(col <= colMax){
                spiral.push_back(matrix[row][col++]);
            }
            if(colMin <= colMax){
                --col;
                ++rowMin;
                ++row;
            } else {
                return spiral;
            }
            while(row <= rowMax){
                spiral.push_back(matrix[row++][col]);
            }
            if(rowMin <= rowMax){
                --row;
                --colMax;
                --col;
            } else {
                return spiral;
            }
            while(col >= colMin){
                spiral.push_back(matrix[row][col--]);
            }
            if(colMin <= colMax){
                ++col;
                --rowMax;
                --row;
            } else {
                return spiral;
            }
            while(row >= rowMin){
                spiral.push_back(matrix[row--][col]);
            }
            if(rowMin <= rowMax){
                ++row; 
                ++colMin;
                ++col;
            } else {
                return spiral;
            }
        }
    }
};
