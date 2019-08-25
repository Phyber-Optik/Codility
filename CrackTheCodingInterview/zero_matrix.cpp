class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        if(!matrix.size() || !matrix[0].size()) return;
        
        int m = matrix.size(), n = matrix[0].size();
        bool row0 = false, col0 = false;
        for(int i = 0; i < n; i++) row0 |= (matrix[0][i] == 0);
        for(int i = 0; i < m; i++) col0 |= (matrix[i][0] == 0);
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][j]) {
                    matrix[i][0] = 0;
                    matrix[0][j] = 0;
                }
            }
        }
        
        for(int i = 1; i < m; i++) {
            for(int j = 1; j < n; j++) {
                if(!matrix[i][0] || !matrix[0][j]) {
                    matrix[i][j] = 0;
                }
            }
        }
        
        if(row0) for(int i = 0; i < n; i++) matrix[0][i] = 0;
        if(col0) for(int i = 0; i < m; i++) matrix[i][0] = 0;
    }
};