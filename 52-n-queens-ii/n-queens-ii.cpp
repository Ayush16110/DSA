class Solution {
private:
    unordered_set<int> col, diag, anti;
    int helper(int n, int r) {
        if(r == n) return 1;
        int count = 0;
        for(int c = 0; c < n; c++) {
            if(!col.contains(c) && !diag.contains(r + c) && !anti.contains(r - c)) {
                col.insert(c);
                diag.insert(r + c);
                anti.insert(r - c);
                count += helper(n, r + 1);
                col.erase(c);
                diag.erase(r + c);
                anti.erase(r - c);
            }
        }

        return count;
    }
public:
    int totalNQueens(int n) {
        return helper(n, 0);
    }
};