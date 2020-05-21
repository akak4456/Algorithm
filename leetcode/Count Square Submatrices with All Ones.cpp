class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int ans = 0;
        int oneCnt[300][300];
        for(int i=0;i<300;i++){
            for(int j=0;j<300;j++){
                oneCnt[i][j] = 0;
            }
        }
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                oneCnt[i][j] += matrix[i][j];
                if(i-1 >= 0){
                    oneCnt[i][j] += oneCnt[i-1][j];
                }
                if(j-1 >= 0){
                    oneCnt[i][j] += oneCnt[i][j-1];
                }
                if(i-1 >= 0 && j-1 >= 0){
                    oneCnt[i][j] -= oneCnt[i-1][j-1];
                }
            }
        }
        for(int side = 1;side <= min(matrix.size(),matrix[0].size());side++){
            for(int startY = 0;startY < matrix.size();startY++){
                for(int startX = 0;startX < matrix[0].size();startX++){
                    int ny = startY+side-1;
                    int nx = startX+side-1;
                    if(ny >= matrix.size() || nx >= matrix[0].size())
                        continue;
                    int cnt = oneCnt[ny][nx];
                    if(ny-side >= 0)
                        cnt -= oneCnt[ny-side][nx];
                    if(nx-side >= 0)
                        cnt -= oneCnt[ny][nx-side];
                    if(ny-side >= 0 && nx-side >= 0)
                        cnt += oneCnt[ny-side][nx-side];
                    if(cnt == side * side)
                        ans++;
                }
            }
            cout << side << ' ' << ans << endl;
        }
        return ans;
    }
};