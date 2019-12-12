//result:맞았습니다!!
#include <iostream>
#include <cmath>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int x, y, w, h;
	cin >> x >> y >> w >> h;
	int minLen = 987654321;
	if (x < minLen)
		minLen = x;
	if (w - x < minLen)
		minLen = w - x;
	if (y < minLen)
		minLen = y;
	if (h - y < minLen)
		minLen = h - y;;
	cout << minLen << '\n';
}