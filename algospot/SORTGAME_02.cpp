//result:런타임 오류
#include <iostream>
#include <queue>
using namespace std;
int C;
int N;
int arr[8];
struct Node {
	int arr[8];
	int cnt = 0;
};
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> arr[i];
		}
		Node tmp;
		for (int i = 0; i < N; i++) {
			tmp.arr[i] = arr[i];
		}
		queue<Node> q;
		q.push(tmp);
		int ans;
		while (!q.empty()) {
			Node topNode = q.front();
			q.pop();
			bool isBreak = true;
			for (int chooseCount = 2; chooseCount <= N; chooseCount++) {
				for (int idx = 0; idx + chooseCount <= N; idx++) {
					Node tmp2;
					tmp2.cnt = topNode.cnt + 1;
					for (int i = 0; i < N; i++) {
						tmp2.arr[i] = topNode.arr[i];
						if (i > 0 && tmp2.arr[i - 1] > tmp2.arr[i]) {
							isBreak = false;
						}
					}
					if (isBreak) {
						ans = topNode.cnt;
						break;
					}
					int tmpArr[8];
					for (int i = 0; i< chooseCount; i++) {
						tmpArr[i+idx] = tmp2.arr[i+idx];
					}
					for (int i = 0; i < chooseCount; i++ ) {
						tmp2.arr[i + idx] = tmpArr[chooseCount - i - 1];
					}
					q.push(tmp);
				}
				if (isBreak)
					break;
			}
			if (isBreak)
				break;
		}
		cout << ans << endl;
	}
}