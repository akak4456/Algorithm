//result:맞았습니다!!
#include <iostream>
#include <cmath>
#define M_PI 3.14159265358979323846

using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	int R;
	cin >> R;
	double a1 = (double)R * (double)R * M_PI;
	double a2 = 2 * (double)R * (double)R;
	cout << fixed;
	cout.precision(6);
	cout << a1 << '\n' << a2 << '\n';
}