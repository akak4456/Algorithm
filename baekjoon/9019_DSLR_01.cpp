//result:틀렸습니다
#include <iostream>
#include <algorithm>
#include <queue>
#include <stack>
#include <cstring>
using namespace std;
const int MAX_N = 10000;
int T;
int A, B;
bool visited[MAX_N];
pair<int,char> parent[MAX_N];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> A >> B;
		for (int i = 0; i < MAX_N; i++) {
			visited[i] = false;
			parent[i].first = -1;
		}
		queue<int> q;
		q.push(A);
		while (!q.empty()) {
			int newN = q.front();
			q.pop();
			visited[newN] = true;
			if (newN == B) {
				stack<char> st;
				int p = parent[newN].first;
				st.push(parent[newN].second);
				while (parent[p].first != -1) {
					st.push(parent[p].second);
					p = parent[p].first;
				}
				while (!st.empty()) {
					cout << st.top();
					st.pop();
				}
				cout << '\n';
				break;
			}
			int tmpN = (newN * 2) % MAX_N;
			if (!visited[tmpN]) {
				visited[tmpN] = true;
				q.push(tmpN);
				parent[tmpN].first = newN;
				parent[tmpN].second = 'D';
			}
			tmpN = newN - 1;
			if (tmpN == 0)
				tmpN = 9999;
			if (!visited[tmpN]) {
				visited[tmpN] = true;
				q.push(tmpN);
				parent[tmpN].first = newN;
				parent[tmpN].second = 'S';
			}
			int tmpN2 = newN / 1000;
			tmpN = (newN - tmpN2*1000)*10;
			tmpN = tmpN + tmpN2;
			if (!visited[tmpN]) {
				visited[tmpN] = true;
				q.push(tmpN);
				parent[tmpN].first = newN;
				parent[tmpN].second = 'L';
			}
			tmpN2 = newN % 10;
			tmpN = (newN / 10);
			tmpN = tmpN + tmpN2*1000;
			if (!visited[tmpN]) {
				visited[tmpN] = true;
				q.push(tmpN);
				parent[tmpN].first = newN;
				parent[tmpN].second = 'R';
			}
		}
	}
}