//result:시간초과
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
struct Dist {
	int num1;
	int num2;
	double dist;
};
int C;
int N;
vector<pair<double, double> > points;
vector<vector<Dist> > dists;
bool decision(double mid) {
	vector<int> cand;
	cand.push_back(0);
	int count = 0;
	while (count < cand.size()) {
		int idx = cand[count];
		for (int i = 0; i < dists[idx].size(); i++) {
			if (dists[idx][i].dist <= mid) {
				bool canPush = true;
				for (int j = 0; j < cand.size(); j++) {
					if (cand[j] == dists[idx][i].num2) {
						canPush = false;
						break;
					}
				}
				if (canPush) {
					cand.push_back(dists[idx][i].num2);
				}
			}
		}
		count++;
	}
	return (cand.size() == N);
}
double optimize() {
	double lo = 0,hi=1420;
	for (int it = 0; it < 1000; it++) {
		double mid = (lo + hi) / 2.0;
		if (decision(mid))
			hi = mid;
		else
			lo = mid;
	}
	return lo;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		points.clear();
		dists.clear();
		for (int i = 0; i < N; i++) {
			double x, y;
			cin >> x >> y;
			points.push_back(make_pair(x, y));
		}
		for (int i = 0; i < N; i++) {
			vector<Dist> tmpVec;
			for (int j = i + 1; j < N; j++) {
				double dist = sqrt(pow(points[i].first - points[j].first, 2) + pow(points[i].second - points[j].second, 2));
				Dist tmp;
				tmp.num1 = i;
				tmp.num2 = j;
				tmp.dist = dist;
				tmpVec.push_back(tmp);
			}
			dists.push_back(tmpVec);
			tmpVec.clear();
		}
		cout << optimize() << endl;
	}
}