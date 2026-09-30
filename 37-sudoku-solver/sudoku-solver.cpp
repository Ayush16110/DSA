class Solution {
    vector<unordered_set<char>> rows;
    vector<unordered_set<char>> cols;
    vector<unordered_set<char>> boxes;

private:
    bool solve(vector<vector<char>>& board, int i, int j) {
        if (i == 9)
            return true;

        if (j == 9)
            return solve(board, i + 1, 0);

        if (board[i][j] != '.')
            return solve(board, i, j + 1);

        int box = (i / 3) * 3 + (j / 3);

        for (char ch = '1'; ch <= '9'; ch++) {
            if (rows[i].contains(ch) ||
                cols[j].contains(ch) ||
                boxes[box].contains(ch)) {
                continue;
            }

            board[i][j] = ch;
            rows[i].insert(ch);
            cols[j].insert(ch);
            boxes[box].insert(ch);

            if (solve(board, i, j + 1))
                return true;

            board[i][j] = '.';
            rows[i].erase(ch);
            cols[j].erase(ch);
            boxes[box].erase(ch);
        }

        return false;
    }

public:
    void solveSudoku(vector<vector<char>>& board) {
        rows.resize(9);
        cols.resize(9);
        boxes.resize(9);

        for (int i = 0; i < 9; i++) {
            for (int j = 0; j < 9; j++) {
                if (board[i][j] == '.')
                    continue;

                char ch = board[i][j];
                int box = (i / 3) * 3 + (j / 3);

                rows[i].insert(ch);
                cols[j].insert(ch);
                boxes[box].insert(ch);
            }
        }

        solve(board, 0, 0);
    }
};
