class Solution {
public:
public:
    void solve(vector<vector<char>>& board) {
        if (board.empty()) return;
        int m = board.size();
        int n = board[0].size();
        queue<pair<int,int>> q;

        for (int i = 0; i < m; i++) {
            if (board[i][0] == 'O') q.push({i, 0});
            if (board[i][n-1] == 'O') q.push({i, n-1});
        }
        for (int j = 0; j < n; j++) {
            if (board[0][j] == 'O') q.push({0, j});
            if (board[m-1][j] == 'O') q.push({m-1, j});
        }

        int dirs[4][2] = {{1,0},{-1,0},{0,1},{0,-1}};
        while (!q.empty()) {
            auto [x, y] = q.front(); q.pop();
            if (board[x][y] != 'O') continue;
            board[x][y] = 'S';
            for (auto& d : dirs) {
                int nx = x + d[0], ny = y + d[1];
                if (nx >= 0 && ny >= 0 && nx < m && ny < n && board[nx][ny] == 'O') q.push({nx, ny});
            }
        }

        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (board[i][j] == 'O') board[i][j] = 'X';
                else if (board[i][j] == 'S') board[i][j] = 'O';
            }
        }
    }
};
