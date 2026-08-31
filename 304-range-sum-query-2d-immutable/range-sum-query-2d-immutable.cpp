class NumMatrix {
vector<vector<int>> matrix;
vector<vector<int>> prefix;
public:
    NumMatrix(vector<vector<int>>& matrix) {
        this->matrix = matrix;
        this->prefix = setPrefix(matrix);
    }

    vector<vector<int>> setPrefix(const vector<vector<int>>& matrix) {
        vector<vector<int>> prefix(matrix.size() + 1, vector<int> (matrix[0].size() + 1, 0));
        for(int i = 0; i < matrix.size(); i++) {
            for(int j = 0; j < matrix[0].size(); j++) {
                prefix[i+1][j+1] = matrix[i][j] + prefix[i][j+1] + prefix[i+1][j] - prefix[i][j];
            }
        }

        return prefix;
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return (this->prefix[row2+1][col2+1] - this->prefix[row2+1][col1] - this->prefix[row1][col2+1] + this->prefix[row1][col1]);
    }
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix* obj = new NumMatrix(matrix);
 * int param_1 = obj->sumRegion(row1,col1,row2,col2);
 */