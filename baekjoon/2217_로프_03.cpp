//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<int> rope;
	rope.resize(N);
	for(int i=0;i<N;i++){
		cin >> rope[i];
	}
	sort(rope.begin(), rope.end());
	long long int maxVal = -1;
	for (int i = N - 1; i >= 0; i--) {
		long long int maxWeight = rope[i] * (N - i);
		if (maxWeight > maxVal)
			maxVal = maxWeight;
	}
	cout << maxVal << '\n';
}