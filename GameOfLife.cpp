class Solution {
public:
    void gameOfLife(vector<vector<int>>& board) {
        vector<vector<int>> nextBoard = board;
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                int living = 0;
                bool t = row != 0, b = row != board.size() - 1, l = col != 0, r = col != board[0].size() - 1, bl = b && l, br = r && b, tl = l && t, tr = r && t;
                if(t && board[row-1][col]){
                    ++living;
                }
                if(b && board[row+1][col]){
                    ++living;
                }
                if(l && board[row][col-1]){
                    ++living;
                }
                if(r && board[row][col+1]){
                    ++living;
                }
                if(tl && board[row-1][col-1]){
                    ++living;
                }
                if(tr && board[row-1][col+1]){
                    ++living;
                }
                if(bl && board[row+1][col-1]){
                    ++living;
                }
                if(br && board[row+1][col+1]){
                    ++living;
                }
                if((board[row][col] == 2 || board[row][col] == 3) || (!board[row][col] && living == 3)){
                    nextBoard[row][col] = 1;
                }
                if(board[row][col] && (living < 2 || living > 3)){
                    nextBoard[row][col] = 0;
                }
            }
        }
        for(int row = 0; row < board.size(); ++row){
            for(int col = 0; col < board[0].size(); ++col){
                board[row][col] = nextBoard[row][col];
            }
        }
    }
};
