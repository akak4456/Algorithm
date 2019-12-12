//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
struct Point {
	int x, y;
};
bool sortBy(const Point& a, const Point& b) {
	if (a.x < b.x)
		return true;
	else if (a.x == b.x) {
		return a.y < b.y;
	}
	else
		return false;
}
vector<Point> points;
int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	points.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> points[i].x >> points[i].y;
	}
	sort(points.begin(), points.end(), sortBy);
	for (int i = 0; i < N; i++) {
		cout << points[i].x << " " << points[i].y << "\n";
	}
}