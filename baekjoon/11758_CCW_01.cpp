//result:맞았습니다!!
#include <iostream>
#include <cmath>
using namespace std;
struct Point {
	int x, y;
};
Point points[3];
int ccw(Point r, Point p, Point q) {
	return ((p.x - r.x) * (q.y - r.y) - (q.x - r.x) * (p.y - r.y));
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	for (int i = 0; i < 3; i++)
		cin >> points[i].x >> points[i].y;
	int ans = ccw(points[0], points[1], points[2]);
	if (ans < 0)
		cout << -1;
	else if (ans > 0)
		cout << 1;
	else
		cout << 0;
}