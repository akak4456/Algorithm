//result:시간 초과
#include <iostream>
#include <vector>
using namespace std;
int N;
int parent[100001];
vector<pair<int, int> >remain;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	parent[1] = -1;
	for (int i = 1; i <= N-1; i++) {
		int a, b;
		cin >> a >> b;
		if (parent[a] != 0) {
			parent[b] = a;
		}
		else if (parent[b] != 0) {
			parent[a] = b;
		}
		else {
			remain.push_back(make_pair(a, b));
		}
	}
	while (!remain.empty()) {
		for (int i = 0; i < remain.size(); i++) {
			if (parent[remain[i].first] != 0) {
				parent[remain[i].second] = remain[i].first;
				remain.erase(remain.begin() + i);
				i--;
			}else if (parent[remain[i].second] != 0) {
				parent[remain[i].first] = remain[i].second;
				remain.erase(remain.begin() + i);
				i--;
			}
		}
	}
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}