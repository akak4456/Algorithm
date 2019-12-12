//result:오답
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
int c;
int n, m;
struct point {
	double y, x;
};
vector<point> hull1, hull2;
vector<pair<point, point> > upper, lower;
void decompose(const vector<point>& hull){
	int N = hull.size();
	for (int i = 0; i < N; i++) {
		if (hull[i].x < hull[(i + 1) % N].x)
			lower.push_back(make_pair(hull[i], hull[(i + 1) % N]));
		else if (hull[i].x > hull[(i + 1) % N].x)
			upper.push_back(make_pair(hull[i], hull[(i + 1) % N]));
	}
}
bool between(const point& a, const point& b, double x) {
	return (a.x <= x && x <= b.x) || (b.x <= x && x <= a.x);
}
double at(const point& a, const point& b, double x) {
	double dy = b.y - a.y;
	double dx = b.x - a.x;
	return a.y + dy * (x - a.x) / dx;
}
double vertical(double x) {
	double minUp = 1e20, maxLow = -1e20;
	for (int i = 0; i < upper.size(); i++) {
		if (between(upper[i].first, upper[i].second, x))
			minUp = min(minUp, at(upper[i].first, upper[i].second, x));
	}
	for (int i = 0; i < lower.size(); i++) {
		if (between(lower[i].first, lower[i].second, x))
			maxLow = max(maxLow, at(lower[i].first, lower[i].second, x));
	}
	return minUp - maxLow;
}
double solve() {
	double lo = 0, hi = 100;
	for (int iter = 0; iter < 100; iter++) {
		double aab = (lo * 2 + hi) / 3.0;
		double abb = (lo + hi * 2) / 3.0;
		if (vertical(aab) < vertical(abb)) {
			lo = aab;
		}
		else {
			hi = abb;
		}
	}
	if (vertical(hi) == 2e20)
		return 0;
	return max(0.0, vertical(hi));
}
int main() {
	std::ios::sync_with_stdio(false);
	cout << fixed;
	cout.precision(10);
	cin >> c;
	while (c--) {
		hull1.clear();
		hull2.clear();
		upper.clear();
		lower.clear();
		cin >> n >> m;
		for (int i = 0; i < n; i++) {
			point tmp;
			cin >> tmp.x >> tmp.y;
			hull1.push_back(tmp);
		}
		for (int i = 0; i < m; i++) {
			point tmp;
			cin >> tmp.x >> tmp.y;
			hull2.push_back(tmp);
		}
		decompose(hull1);
		decompose(hull2);
		cout << solve() << endl;
	}
}