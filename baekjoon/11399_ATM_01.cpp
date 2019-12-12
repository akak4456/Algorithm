//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> wait;
	wait.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> wait[i];
	}
	sort(wait.begin(), wait.end());
	int sum = 0;
	int sumMin = 0;
	for (int i = 0; i < N; i++) {
		sum += wait[i];
		sumMin += sum;
	}
	cout << sumMin << '\n';
}