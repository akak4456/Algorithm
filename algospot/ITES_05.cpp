//result:정답
#include <iostream>
#include <queue>
using namespace std;
struct RNG {
	unsigned seed;
	RNG() :seed(1983) {}
	unsigned next() {
		unsigned ret = seed;
		seed = ((seed) * 214013u + 2531011u);
		return ret % 10000 + 1;
	}
};
int C;
int K, N;
queue<int> q;
unsigned int sum = 0;
int cnt = 0;
int main() {
	std::ios::sync_with_stdio(false);
 	cin >> C;
	while (C--) {
		cin >> K >> N;
		while (!q.empty())
			q.pop();
		sum = 0;
		cnt = 0;
		RNG rng;
		for (int i = 1; i <= N; i++) {
			//cout << sum << endl;
			int newA = rng.next();
			if (sum + newA == K) {
				cnt++;
			}
			else if (sum + newA > K) {
				while (!q.empty()&&sum + newA > K) {
					sum -= q.front();
					q.pop();
					if (sum + newA == K) {
						cnt++;
						break;
					}
				}
			}
			sum += newA;
			q.push(newA);
		}
		cout << cnt << endl;
	}
}