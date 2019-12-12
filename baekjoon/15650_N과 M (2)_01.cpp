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
	for (int i = arr.back(); i <= N; i++) {
		bool isCan = true;
		for (int j = 0; j < arr.size(); j++) {
			if (i == arr[j]) {
				isCan = false;
				break;
			}
		}
		if (isCan) {
			arr.push_back(i);
			recursive(arr);
			arr.pop_back();
		}
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for (int i = 1; i <= N; i++) {
		vector<int> tmp;
		tmp.push_back(i);
		recursive(tmp);
		tmp.pop_back();
	}
}