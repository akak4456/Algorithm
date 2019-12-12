//result:정답
#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;
const double pi = 2.0 * acos(0);
double y[100], x[100], r[100];
pair<double, double> ranges[100];
int C;
int N;
void convertToRange() {
	for (int i = 0; i < N; i++) {
		double loc = fmod(2 * pi + atan2(y[i], x[i]), 2 * pi);
		double range = 2.0 * asin(r[i] / 2.0 / 8.0);
		ranges[i] = make_pair(loc - range, loc + range);
	}
	sort(ranges, ranges + N);
}
const int INF = 987654321;
int solveLinear(double begin, double end) {
	int used = 0, idx = 0;
	while (begin < end) {
		double maxCover = -1;
		while (idx < N && ranges[idx].first <= begin) {
			maxCover = max(maxCover, ranges[idx].second);
			idx++;
		}
		if (maxCover <= begin) return INF;
		begin = maxCover;
		used++;
	}
	return used;
}
int solveCircular() {
	int ret = INF;
	sort(ranges, ranges + N);
	for (int i = 0; i < N; i++) {
		if (ranges[i].first <= 0 || ranges[i].second >= 2 * pi) {
			double begin = fmod(ranges[i].second, 2 * pi);
			double end = fmod(ranges[i].first+2*pi, 2 * pi);
			ret = min(ret, 1 + solveLinear(begin, end));
		}
	}
	return ret;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> y[i] >> x[i] >> r[i];
		}
		convertToRange();
		int ret = solveCircular();
		if (ret == INF) {
			cout << "IMPOSSIBLE" << endl;
		}
		else {
			cout << ret << endl;
		}
	}
}