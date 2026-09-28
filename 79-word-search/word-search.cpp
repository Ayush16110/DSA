class Solution {
private:
    vector<int> dx = {0, 1, 0, -1};
    vector<int> dy = {1, 0, -1, 0};
    bool backtrack(vector<vector<char>>& board, const string& word, int i, int j, int idx) {
        if(idx == word.size()) return true;
        for(int k = 0; k < 4; k++) {
            int nx = dx[k] + i;
            int ny = dy[k] + j;
            if(nx >= 0 and nx < board.size() and ny >= 0 and ny < board[0].size()) {
                if(board[nx][ny] == word[idx]) {
                    char ch = board[nx][ny];
                    board[nx][ny] = '*';
                    if(backtrack(board, word, nx, ny, idx+1)) return true;
                    board[nx][ny] = ch;
                }
            }
        }

        return false;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i = 0; i < board.size(); i++) {
            for(int j = 0; j < board[0].size(); j++) {
                if(board[i][j] == word[0]) {
                    char ch = board[i][j];
                    board[i][j] = '*';
                    if(backtrack(board, word, i, j, 1)) return true;
                    board[i][j] = ch;
                }
            }
        }

        return false;
    }
};