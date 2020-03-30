//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
const int MOD = 1000000009;
const int MAX_N = 1000000;
long long int D[MAX_N+1];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int X;
	priority_queue<int,vector<int>,greater<int> > pq;
	int len = 64;
	cin >> X;
	pq.push(64);
	while (X < len) {
		int t = pq.top();
	//	cout << pq.size() << endl;
		pq.pop();
		
		if (len - t/2 >= X) {
			len -= t / 2;
			pq.push(t / 2);
		}
		else {
			pq.push(t / 2);
			pq.push(t / 2);
		}
		//cout << t << ' ' << t / 2 << ' ' << len << ' ' << pq.size() << endl;
	//	cout << len <<' ' << pq.size()<< endl;
	}
	cout << pq.size() << endl;
}