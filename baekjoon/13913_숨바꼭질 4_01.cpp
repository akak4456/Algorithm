//result:시간 초과
#include <iostream>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
int N, K;
int visited[100001];
vector<int> route;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	queue<pair<int, int> > q;
	q.push(make_pair(N, 0));
	visited[N] = true;
	while (!q.empty()) {
		pair<int, int> tmp = q.front();
		q.pop();
		int x = tmp.first;
		int newCnt = tmp.second + 1;
		visited[x] = newCnt;
		//cout << x  << ' ' << newCnt<< endl;
		if (x == K) {
			cout << newCnt - 1 << '\n';
			int cnt = newCnt;
			int nx = K;
			route.push_back(nx);
			while (cnt > 1) {
				if (visited[nx - 1] == cnt - 1) {
					nx--;
					cnt--;
					route.push_back(nx);
				}
				else if (visited[nx + 1] == cnt - 1) {
					nx++;
					cnt--;
					route.push_back(nx);
				}
				else if (nx % 2 == 0 && visited[nx / 2] == cnt - 1) {
					nx /= 2;
					cnt--;
					route.push_back(nx);
				}
			}
			for (int i = route.size()-1; i >= 0; i--)
				cout << route[i] << ' ';
			cout << '\n';
			break;
		}
		if (x - 1 >= 0 && visited[x - 1] == 0) {
			visited[x - 1] = newCnt;
			q.push(make_pair(x - 1, newCnt));
		}
		if (x + 1 <= 100000 && visited[x + 1] == 0) {
			visited[x + 1] = newCnt;
			q.push(make_pair(x + 1, newCnt));
		}
		if (2 * x <= 100000 && visited[2 * x] == 0) {
			visited[2 * x] = newCnt;
			q.push(make_pair(2 * x, newCnt));
		}
	}
}