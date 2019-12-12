//result:맞았습니다!!
#include <iostream>
#include <string>
#include <map>
#include <algorithm>
#include <cstring>
using namespace std;
const int MAX = 100000 + 1;
int T, F;
int arr[MAX];
int find(int num) {
	if (arr[num] < 0)
		return num;
	return arr[num] = find(arr[num]);
}
void merge(int aParent, int bParent){
		arr[aParent] += arr[bParent];
		arr[bParent] = aParent;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> F;
		memset(arr, -1, sizeof(arr));
		map<string, int> name;
		int idx = 1;
		while (F--) {
			string tmp1, tmp2;
			cin >> tmp1 >> tmp2;
			if (name.count(tmp1) == 0) {
				name[tmp1] = idx++;
			}
			if (name.count(tmp2) == 0) {
				name[tmp2] = idx++;
			}
			int tmp1Parent = find(name[tmp1]);
			int tmp2Parent = find(name[tmp2]);
			if (tmp1Parent == tmp2Parent) {
				cout << abs(arr[tmp1Parent]) << '\n';
			}
			else {
				merge(tmp1Parent, tmp2Parent);
				cout << abs(arr[tmp1Parent]) << '\n';
			}
		}
	}
}