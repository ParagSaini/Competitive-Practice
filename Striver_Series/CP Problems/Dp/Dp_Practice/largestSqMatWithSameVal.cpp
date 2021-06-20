int solve(vector<vector<int>>& matrix) {
    int n = matrix.size(), m = matrix[0].size();
    // solution matrix contains the size of the sq matrix which are possible solution.
    vector<vector<int>> solution(n, vector<int>(m, 1));

    for(int i=1; i<n; i++) {
        for(int j=1; j<m; j++) {
            int cur = matrix[i][j];
            if(matrix[i][j-1] == cur && matrix[i-1][j] == cur && matrix[i-1][j-1] == cur) {
                solution[i][j] = min({solution[i-1][j], solution[i][j-1], solution[i-1][j-1]}) + 1;
            } 
        }
    }
    int maxi = 1;
    for(int i=0; i<n; i++) {
        for(int j=0; j<m; j++) {
            maxi = max(maxi, solution[i][j]);
        }
    }
    return maxi;
}