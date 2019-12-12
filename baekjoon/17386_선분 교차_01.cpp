//result:틀렸습니다
#include <iostream>
#include <cmath>
using namespace std;
int ccw(pair<int, int> a, pair<int, int> b, pair<int, int> c) {
	int op = a.first * b.second + b.first * c.second + c.first * a.second;
	op -= (a.second * b.first + b.second * c.first + c.second * a.first);
	if (op > 0)return 1;
	else if (op == 0)return 0;
	else return -1;
}
int isIntersect(pair<int,int> a, pair<int, int> b, pair<int, int> c, pair<int, int> d) {
	int ab = ccw(a, b, c) * ccw(a, b, d);
	int cd = ccw(c, d, a) * ccw(c, d, b);
	if (ab == 0 && cd == 0) {
		if (a > b)swap(a, b);
		if (c > d)swap(c, d);
		return c <= b && a <= d;
	}
	return ab <= 0 && cd <= 0;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	pair<int, int> points[4];
	for (int i = 0; i < 4; i++)
		cin >> points[i].first >> points[i].second;
	cout << isIntersect(points[0], points[1], points[2], points[3]);
}