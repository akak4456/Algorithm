//result:정답
#include <iostream>
#include <string>
using namespace std;
struct Board {
	char status;
	Board* upLeftInclude = NULL;
	Board* upRightInclude = NULL;
	Board* downLeftInclude = NULL;
	Board* downRightInclude = NULL;
};
int C;
string src;
int idx;
void quad(Board* cur) {
	if (src[idx] == 'w') {
		idx++;
		cur->status = 'w';
		return;
	}else if (src[idx] == 'b') {
		idx++;
		cur->status = 'b';
		return;
	}
	else if (src[idx] == 'x') {
		idx++;
		for (int cnt = 0; cnt < 4; cnt++) {
			Board* newBoard = new Board;
			cur->status = 'x';
			if (cnt == 0) {
				cur->upLeftInclude = newBoard;
			}
			else if (cnt == 1) {
				cur->upRightInclude = newBoard;
			}
			else if (cnt == 2) {
				cur->downLeftInclude = newBoard;
			}
			else if (cnt == 3) {
				cur->downRightInclude = newBoard;
			}
			quad(newBoard);
		}

	}
}
void deleteBoard(Board* cur) {
	if (cur->upLeftInclude != NULL)
		deleteBoard(cur->upLeftInclude);
	if (cur->upRightInclude != NULL)
		deleteBoard(cur->upRightInclude);
	if (cur->downLeftInclude != NULL)
		deleteBoard(cur->downLeftInclude);
	if (cur->downRightInclude != NULL)
		deleteBoard(cur->downRightInclude);
	delete cur;
}
void flip(Board* cur) {
	if (cur->upLeftInclude != NULL)
		flip(cur->upLeftInclude);
	if (cur->upRightInclude != NULL)
		flip(cur->upRightInclude);
	if (cur->downLeftInclude != NULL)
		flip(cur->downLeftInclude);
	if (cur->downRightInclude != NULL)
		flip(cur->downRightInclude);
	Board* tmp = cur->upLeftInclude;
	cur->upLeftInclude = cur->downLeftInclude;
	cur->downLeftInclude = tmp;

	tmp = cur->upRightInclude;
	cur->upRightInclude = cur->downRightInclude;
	cur->downRightInclude = tmp;
}
void print(Board* cur) {
	if (cur->status == 'x') {
		cout << 'x';
		print(cur->upLeftInclude);
		print(cur->upRightInclude);
		print(cur->downLeftInclude);
		print(cur->downRightInclude);
	}
	else {
		cout << cur->status;
		return;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> C;
	while (C--) {
		idx = 0;
		cin >> src;
		Board* start = new Board;
		quad(start);
		flip(start);
		print(start);
		cout << '\n';
		deleteBoard(start);
	}
}