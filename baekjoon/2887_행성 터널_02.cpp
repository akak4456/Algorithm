//result:맞았습니다!!
/*
x축만을 사용할 때에도 (최소)스패닝 트리는 만들 수 있었다.
그러니 최소 스패닝 트리를 만들 수 있다.
*/
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
	points.resize(N);//사이즈 잘 조정해라 이상한 결과 나온다
	for (int i = 0; i < N; i++) {
		points[i].idx = i;
		cin >> points[i].x >> points[i].y >> points[i].z;	
	}
	priority_queue < pair<int, pair<int, int>>>pq;//가중치 start end
	sort(points.begin(), points.end(), sortByX);
	memset(arr, -1, sizeof(arr));	
	for (int i = 1; i < N; i++) {
		pq.push(make_pair(-abs(points[i].x - points[i - 1].x), make_pair(points[i].idx, points[i - 1].idx)));
	}
	sort(points.begin(), points.end(), sortByY);
	for (int i = 1; i < N; i++) {
		pq.push(make_pair(-abs(points[i].y - points[i - 1].y), make_pair(points[i].idx, points[i - 1].idx)));
	}
	sort(points.begin(), points.end(), sortByZ);
	for (int i = 1; i < N; i++) {
		pq.push(make_pair(-abs(points[i].z - points[i - 1].z), make_pair(points[i].idx, points[i - 1].idx)));
	}
	int cost = 0;
	while (!pq.empty()) {
		pair<int, pair<int, int>>tmp = pq.top();
		pq.pop();
		//cout << tmp.second.first << ' '<<tmp.second.second << ' '<< -tmp.first << endl;
		if (merge(tmp.second.first, tmp.second.second)) {
			cost += -tmp.first;
		}
	}
	cout << cost << '\n';
}