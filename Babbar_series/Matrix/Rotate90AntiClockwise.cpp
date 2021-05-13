// given matrix is a square matrix.

void rotate(vector<vector<int> >& matrix)
{
    // transpose the matrix
    for(int row=0; row<matrix.size(); row++) {
        for(int col=0; col<=row; col++) {
            swap(matrix[row][col], matrix[col][row]);
        }
    }
    int start = 0;
    int end = matrix.size()-1;
    // swap the rows for rotate the matrix
    while(start < end) {
        for(int i=0; i<matrix.size(); i++) {
            swap(matrix[start][i], matrix[end][i]);
        }
        start++;
        end--;
    }
}