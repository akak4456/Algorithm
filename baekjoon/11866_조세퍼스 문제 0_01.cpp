//result:맞았습니다!!
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N, K;
	cin >> N >> K;
	queue<int> q;
	for (int i = 1; i <= N; i++)
		q.push(i);
	vector<int> result;
	while (result.size() < N) {
		while (!q.empty()) {
			for(int i=0;i<K-1;i++){
				q.push(q.front());
				q.pop();
			}
			result.push_back(q.front());
			q.pop();
		}
	}
	cout << '<';
	for (int i = 0; i < result.size()-1; i++) {
		cout << result[i] << ", ";
	}
	cout << result[N - 1] << '>';
}