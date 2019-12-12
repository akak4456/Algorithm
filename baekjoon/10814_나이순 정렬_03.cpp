//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<pair<int, string> > person;
vector<pair<int, string> > sorted;
void merge(int left, int mid, int right) {
	//cout << left << ' ' << mid << ' ' << right << endl;
	int leftIdx = left;
	int rightIdx = mid + 1;
	int idx = left;
	while (leftIdx <= mid && rightIdx <= right) {
		if (person[leftIdx].first <= person[rightIdx].first) {
			sorted[idx++] = person[leftIdx++];
		}
		else {
			sorted[idx++] = person[rightIdx++];
		}
	}
	while (leftIdx <= mid) {
		sorted[idx++] = person[leftIdx++];
	}
	while (rightIdx <= right) {
		sorted[idx++] = person[rightIdx++];
	}
	for (int i = left; i <= right; i++) {
		person[i] = sorted[i];
	}
}
void mergeSort(int left,int right) {
	int mid = (left + right) / 2;
	if (left < right) {
		mergeSort(left, mid);
		mergeSort(mid + 1, right);
		merge(left, mid, right);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	person.resize(N);
	sorted.resize(N);
	for (int i = 0; i < N; i++) {
		cin >> person[i].first >> person[i].second;
	}
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << sorted[i].first << ' ' << sorted[i].second << '\n';
	}
}