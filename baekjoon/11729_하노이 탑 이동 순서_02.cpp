//result:맞았습니다!!
/*
endl쓰면 오래 걸림
*/
#include <iostream>
#include <vector>
using namespace std;
int cnt = 0;
vector<pair<int, int > > result;
void hanoi(int num,int from,int by,int to) {
	if (num == 1) {
		result.push_back(make_pair(from, to));
		cnt++;
		return;
	}
	hanoi(num - 1, from, to, by);
	result.push_back(make_pair(from, to));
	cnt++;
	hanoi(num - 1, by, from, to);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int n;
	cin >> n;
	hanoi(n,1, 2, 3);
	cout << cnt << endl;
	for (int i = 0; i < result.size(); i++)
		cout << result[i].first << ' ' << result[i].second << '\n';
}