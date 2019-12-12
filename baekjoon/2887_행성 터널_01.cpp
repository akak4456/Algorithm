//result:출력 초과
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
#include <queue>
#include <vector>
#include <cmath>
using namespace std;
const int MAX = 100000 + 1;
int N;
int arr[MAX];
struct Point {
	int idx;
	int x, y, z;
};
vector<Point> points;
vector<Point> pointByX;
vector<Point> pointByY;
vector<Point> pointByZ;
bool sortByX(const Point& a, const Point& b) {
	return a.x < b.x;
}
bool sortByY(const Point& a, const Point& b) {
	return a.y < b.y;
}
bool sortByZ(const Point& a, const Point& b) {
	return a.z < b.z;
}
int find(int num) {
	if (arr[num] < 0)
		return num;
	return arr[num] = find(arr[num]);
}
bool merge(int aParent, int bParent) {
	aParent = find(aParent);
	bParent = find(bParent);
	if (aParent == bParent)
		return false;
	arr[aParent] += arr[bParent];
	arr[bParent] = aParent;
	return true;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	points.resize(N + 1);
	for (int i = 0; i < N; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		points[i].idx = i;
		points[i].x = x;
		points[i].y = y;
		points[i].z = z;
	}
	sort(points.begin(), points.end(), sortByX);
	pointByX = points;
	sort(points.begin(), points.end(), sortByY);
	pointByY = points;
	sort(points.begin(), points.end(), sortByZ);
	pointByZ = points;
	priority_queue < pair<int, pair<int, int>>>pq;//가중치 start end
	memset(arr, -1, sizeof(arr));
	int dif = 0;
	int cost = 0;
	int cnt = 0;
	int startX = 1,startY = 1,startZ = 1;
	while (cnt < N-1) {
		for (int i = startX-1; i >= 0; i--) {
			cout << pointByX[i].x << endl;
			if (abs(pointByX[i].x - pointByX[startX].x) != dif) {
				break;
			}
			else {
				pq.push(make_pair(-dif, make_pair(i, startX)));
				if (i == 0) {
					startX++;
					i = startX;
				}
			}
		}
		while (!pq.empty()) {
			pair<long long int, pair<int, int>> tmp = pq.top();
			pq.pop();
			if (merge(tmp.second.first, tmp.second.second)) {
				cost += -tmp.first;
				cnt++;
			}
		}
		for (int i = startY; i >= 0; i--) {
			if (abs(pointByY[i].x - pointByY[startY].x) != dif) {
				break;
			}
			else {
				pq.push(make_pair(-dif, make_pair(i, startY)));
				if (i == 0) {
					startY++;
					i = startY;
				}
			}
		}
		while (!pq.empty()) {
			pair<long long int, pair<int, int>> tmp = pq.top();
			pq.pop();
			if (merge(tmp.second.first, tmp.second.second)) {
				cost += -tmp.first;
				cnt++;
			}
		}
		for (int i = startZ; i >= 0; i--) {
			if (abs(pointByZ[i].x - pointByZ[startZ].x) != dif) {
				break;
			}
			else {
				pq.push(make_pair(-dif, make_pair(i, startZ)));
				if (i == 0) {
					startZ++;
					i = startZ;
				}
			}
		}
		while (!pq.empty()) {
			pair<long long int, pair<int, int>> tmp = pq.top();
			pq.pop();
			if (merge(tmp.second.first, tmp.second.second)) {
				cost += -tmp.first;
				cnt++;
			}
		}
		dif++;
		//cout << cnt << endl;
	}
	cout << cnt << '\n';
}