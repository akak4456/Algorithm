//result:정답
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
const int MAX = 1000000000 + 1;
const string EXPAND_X = "X+YF";
const string EXPAND_Y = "FX-Y";
int length[51];
int c;
int n,p,l;
void precalc() {
	length[0] = 1;
	for (int i = 1; i <= 50; i++) {
		length[i] = min(MAX, length[i - 1] * 2 + 2);
	}
}
char expand(const string& dragonCurve, int generations, int skip) {
	if (generations == 0) {
		return dragonCurve[skip];
	}
	for (int i = 0; i < dragonCurve.size(); i++) {
		if (dragonCurve[i] == 'X' || dragonCurve[i] == 'Y') {
			if (skip >= length[generations]) {
				skip -= length[generations];
			}
			else if (dragonCurve[i] == 'X') {
				return expand(EXPAND_X, generations - 1, skip);
			}else{
				return expand(EXPAND_Y,generations - 1,skip);
			}
		}
		else if (skip > 0) {
			skip--;
		}
		else {
			return dragonCurve[i];
		}
	}
	return '#';
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> c;
	precalc();
	while (c--) {
		cin >> n >> p >> l;
		for (int i = 0; i < l; i++) {
			cout << expand("FX", n, p+i-1);
		}
		cout << endl;
	}
}