//result:맞았습니다!!
#include <iostream>
#include <cmath>
#include <cstring>
#include <map>
using namespace std;
int parent[3001];
int N;
pair<pair<long long int, long long int>, pair<long long int, long long int>> lines[3001];
int ccw(pair<long long int, long long int> a, pair<long long int, long long int> b, pair<long long int, long long int> c) {
	long long int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}
int isIntersect(pair<pair<long long int,long long int>, pair<long long int, long long int>>x, pair<pair<long long int, long long int>, pair<long long int, long long int>>y) {
	pair<long long int, long long int> a = x.first;
	pair<long long int, long long int> b = x.second;
	pair<long long int, long long int> c = y.first;
	pair<long long int, long long int>  d= y.second;
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}
int Find(int x) {

	// Root인 경우 x를 반환
	if (x == parent[x]) {
		return x;
	}
	else {
		// 아니면 Root를 찾아감
		int p = Find(parent[x]);
		parent[x] = p;
		return p;
	}
}
void Union(int x, int y) {

	x = Find(x);
	y = Find(y);

	if (x != y) {
		parent[y] = x;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 1; i <= N; i++) {
		parent[i] = i;
	}
	for (int i = 1; i <= N; i++) {
		cin >> lines[i].first.first >> lines[i].first.second >> lines[i].second.first >> lines[i].second.second;
	}
	for (int i = 1; i <= N; i++) {
		for (int j = i + 1; j <= N; j++) {
			if (isIntersect(lines[i], lines[j]) == 1) {
				Union(i, j);
			}
		}
	}
	map<int, int> tmp;
	int maxVal = 1;
	for (int i = 1; i <= N; i++) {
		Find(i);
	}
	for (int i = 1; i <= N; i++) {
		//cout << parent[i] << ' ';
		map<int, int>::iterator it = tmp.find(parent[i]);
		if (it == tmp.end()) {
			tmp.insert(make_pair(parent[i], 1));
		}
		else {
			it->second++;
			if (it->second > maxVal) {
				maxVal = it->second;
			}
		}
	}
	cout << tmp.size() << '\n' << maxVal << '\n';
}