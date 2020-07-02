class Solution {
public:
    int uniquePaths(int m, int n) {
        int board[100][100];
        for(int i=0;i<m;i++){
            board[0][i] = 1;
        }
        for(int i=0;i<n;i++){
            board[i][0] = 1;
        }
        for(int row = 1;row<n;row++){
            for(int col=1;col<m;col++){
                board[row][col] = board[row-1][col] + board[row][col-1];
            }
        }
        return board[n-1][m-1];
    }
};