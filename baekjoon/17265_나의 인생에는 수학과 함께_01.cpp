//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int N;
char board[5][5];
bool visited[5][5];
int minVal = 987654321;
int maxVal = -987654321;
void dfs(int y, int x,vector<char> op) {
	//cout << y << x << endl;
	visited[y][x] = true;
	op.push_back(board[y][x]);
	if (y == N-1 && x == N-1) {
		stack<int> operand;
		char opcode;
		for (int i = 0; i < op.size(); i++) {
			if (op[i] == '+' || op[i] == '-' || op[i] == '*') {
				opcode = op[i];
			}
			else {
				operand.push(op[i] - '0');
				if (operand.size() == 2) {
					int o2 = operand.top();
					operand.pop();
					int o1 = operand.top();
					operand.pop();
					if (opcode == '+')
						operand.push(o1 + o2);
					else if (opcode == '-')
						operand.push(o1 - o2);
					else
						operand.push(o1 * o2);
				}
			}
		}
		minVal = min(minVal, operand.top());
		maxVal = max(maxVal, operand.top());
		return;
	}
	if (y+1 < N &&!visited[y + 1][x]) {
		visited[y + 1][x] = true;
		dfs(y + 1, x, op);
		visited[y + 1][x] = false;
	}
	if (x+1 < N &&!visited[y][x + 1]) {
		visited[y ][x+1] = true;
		dfs(y, x +1, op);
		visited[y][x+1] = false;
	}
	visited[y][x] = false;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	
	cin >> N;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++)
			cin >> board[i][j];
	vector<char> op;
	dfs(0, 0,op);
	cout << maxVal << ' ' << minVal << '\n';
}