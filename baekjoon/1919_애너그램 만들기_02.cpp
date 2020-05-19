//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator> // inserter
using namespace std;
const int MOD = 45678;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	cin >> A >> B;
	multiset<char> mul1;
	multiset<char> mul2;
	int added = 0;
	while (A.size() < B.size()) {
		A += "1";
		added++;
	}
	while (B.size() < A.size()) {
		B += "1";
		added++;
	}
	for (int i = 0; i < A.size(); i++) {
		mul1.insert(A[i]);
	}
	for (int i = 0; i < B.size(); i++) {
		mul2.insert(B[i]);
	}
	multiset<char> intersection;
	set_intersection(mul1.begin(), mul1.end(), mul2.begin(), mul2.end(), inserter(intersection, intersection.begin()));
	cout << ((A.size()-intersection.size())*2 - added) << '\n';
}