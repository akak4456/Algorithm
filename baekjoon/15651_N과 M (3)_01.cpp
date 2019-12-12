//result:맞았습니다!!
#include <iostream>
#include <vector>
using namespace std;
int N, M;
void recursive(vector<int> arr) {
	if (arr.size() == M) {
		for (int i = 0; i < arr.size(); i++)
			cout << arr[i] << ' ';
		cout << '\n';
		return;
	}
	for (int i = 1; i <= N; i++) {
		arr.push_back(i);
		recursive(arr);
		arr.pop_back();
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	vector<int> tmp;
	recursive(tmp);
}