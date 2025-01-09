class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        array<int, 9> rowMasks = {0}, colMasks = {0}, subgridMasks = {0};
        for (int i = 0; i < 9; ++i) {
            for (int j = 0; j < 9; ++j) {
                if (board[i][j] == '.') continue; 
                int num = board[i][j] - '1';
                int subgridIdx = (i / 3) * 3 + (j / 3);
                if ((rowMasks[i] & (1 << num)) || 
                    (colMasks[j] & (1 << num)) || 
                    (subgridMasks[subgridIdx] & (1 << num))) {
                    return false;
                }
                rowMasks[i] |= (1 << num);
                colMasks[j] |= (1 << num);
                subgridMasks[subgridIdx] |= (1 << num);
            }
        }

        return true;
    }
};
