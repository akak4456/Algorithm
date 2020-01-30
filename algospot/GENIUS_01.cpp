//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <map>
#include <cstring>
using namespace std;
class SquareMatrix { 
public:
    vector<vector<double>> v;
    int mSize;
    SquareMatrix(int n) :mSize(n) {
        v.resize(mSize, vector<double>(mSize, 0));
    }
    ~SquareMatrix() {
        for (int i = 0;i < mSize;i++)
            v[i].clear();
        v.clear();
    }
    SquareMatrix identity(int n) {
        SquareMatrix result = SquareMatrix(n);
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                if (i == j)
                    result.v[i][j] = 1;
                else
                    result.v[i][j] = 0;
      
            }
        }
        return result;
    }
    SquareMatrix operator*(SquareMatrix& b) {
        SquareMatrix result = SquareMatrix(mSize);
        for (int i = 0;i < mSize;i++) {
            for (int j = 0;j < mSize;j++) {
                for (int k = 0;k < mSize;k++) {
                    result.v[i][j] += v[i][k] * b.v[k][j];
                }
            }
        }
        return result;
    }
    SquareMatrix pow(SquareMatrix& A, int m) {
        if (m == 0) return identity(A.mSize);
        if (m % 2 > 0) return pow(A, m - 1) * A;
        SquareMatrix half = pow(A, m / 2);
        return half * half;
    }
};
int n, k,m;
int len[50];
double arr[50][50];
double result[50];
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(8);
    int c;
    cin >> c;
    while (c--) {
        memset(result, 0, sizeof(result));
        cin >> n >> k >> m;
        for (int i = 0;i < n;i++)
            cin >> len[i];
        for (int i = 0;i < n;i++)
            for(int j=0;j<n;j++)
            cin >> arr[i][j];
        SquareMatrix W(4 * n);

        for (int i = 0;i < 3 * n;i++) {
            W.v[i][i + n] = 1.0;
        }
        for (int i = 0;i < n;i++) {
            for (int j = 0;j < n;j++) {
                W.v[3 * n + i][(4 - len[j]) * n + j] = arr[j][i];
            }
        }
        SquareMatrix Wk = W.pow(W,k);
        for (int song = 0;song < n;song++) {
            for (int start = 0; start < len[song];start++) {
                result[song] += Wk.v[(3 - start) * n + song][3 * n];
            }
        }
        for (int i = 0;i < m;i++) {
            int query;
            cin >> query;
            cout << result [query]  << ' ';
        }
        cout << '\n';
    }
}