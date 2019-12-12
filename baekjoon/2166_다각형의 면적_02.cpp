//result:맞았습니다!!
#include <iostream>
#include <cmath>
using namespace std;
struct Point {
	long long int x, y;
};
long long int result;
int N;
Point points[10000];
long long int ccw(Point r, Point p, Point q) {
	return ((p.x - r.x) * (q.y - r.y) - (q.x - r.x) * (p.y - r.y));
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	for (int i = 0; i < N; i++)
		cin >> points[i].x >> points[i].y;
	Point origin = points[0];
	for (int i = 1; i < N-1; i++) {
		result += ccw(origin, points[i], points[i + 1]);
	}
	if (result < 0)
		result *= -1;
	double ans = (result * 1.0)/2;
	cout << fixed;
	cout.precision(1);
	cout << ans << '\n';
}