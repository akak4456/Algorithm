//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	long long int N;
	/*전에 이것을 int라고 해서 틀렸음
	그래서 오버플로우 발생
	(int)*(int)=(int)임을 잊지 말자
	*/
	cin >> N;
	long long int sum = 0;
	for (int i = 0; i < N; i++) {
		sum += i * (N + 1);
	}
	cout << sum << '\n';
}