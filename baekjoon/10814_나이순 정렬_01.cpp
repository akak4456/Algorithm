//result:시간 초과
#include <iostream>
#include <vector>
#include <string>
using namespace std;
int N;
vector<pair<int, string> > person;
void merge(int left, int mid, int right) {
	//cout << left << ' ' << mid << ' ' << right << endl;
	vector<pair<int, string> > oldPerson;
	oldPerson.resize(N);
	for (int i = left; i <= right; i++)
		oldPerson[i] = person[i];
	int leftIdx = left;
	int rightIdx = mid + 1;
	int idx = left;
	while (leftIdx <= mid && rightIdx <= right) {
		if (oldPerson[leftIdx].first <= oldPerson[rightIdx].first) {
			person[idx] = oldPerson[leftIdx];
			idx++;
			leftIdx++;
		}
		else {
			person[idx] = oldPerson[rightIdx];
			idx++;
			rightIdx++;
		}
	}
	while (leftIdx <= mid) {
		person[idx] = oldPerson[leftIdx];
		idx++;
		leftIdx++;
	}
	while (rightIdx <= right) {
		person[idx] = oldPerson[rightIdx];
		idx++;
		rightIdx++;
	}
	/*
	for (int i = 0; i < N; i++) {
		cout << oldPerson[i].first << ' ' << oldPerson[i].second << '\n';
	}
	*/
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
	for (int i = 0; i < N; i++) {
		cin >> person[i].first >> person[i].second;
	}
	mergeSort(0, N - 1);
	for (int i = 0; i < N; i++) {
		cout << person[i].first << ' ' << person[i].second << '\n';
	}
}