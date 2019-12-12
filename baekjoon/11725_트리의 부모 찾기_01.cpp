//result:틀렸습니다
#include <iostream>
using namespace std;
int N;
int parent[100001];
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	parent[1] = -1;
	for(int i=0;i<N-1;i++) {
		int a, b;
		cin >> a >> b;
		if (parent[a] == 0)
			parent[a] = b;
		if (parent[b] == 0)
			parent[b] = a;
	}
	for (int i = 2; i <= N; i++)
		cout << parent[i] << '\n';
}