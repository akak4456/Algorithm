//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int minVal = 987654321;
int maxVal = -1;
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	string A, B;
	cin >> A >> B;
	//cout << stoi(A) +1<< endl;
	string minA = A, minB = B;
	for (int i = 0; i < minA.size(); i++) {
		if (minA[i] == '6')
			minA[i] = '5';
	}
	for (int i = 0; i < minB.size(); i++) {
		if (minB[i] == '6')
			minB[i] = '5';
	}
	cout << stoi(minA) + stoi(minB) << ' ';
	string maxA = A, maxB = B;
	for (int i = 0; i < maxA.size(); i++) {
		if (maxA[i] == '5')
			maxA[i] = '6';
	}
	for (int i = 0; i < maxB.size(); i++) {
		if (maxB[i] == '5')
			maxB[i] = '6';
	}
	cout << stoi(maxA) + stoi(maxB) << '\n';
}