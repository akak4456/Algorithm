//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;
int N;
int S[21][21];
int minValue = 987654321;
void solve(vector<int> startTeam) {
	if (startTeam.size() == N / 2) {
		int startSum = 0;
		int linkSum = 0;
		vector<int> linkTeam;
		for (int i = 1; i <= N; i++) {
			bool isCan = true;
			for (int j = 0; j < startTeam.size(); j++) {
				if (i == startTeam[j]) {
					isCan = false;
					break;
				}
			}
			if (isCan) {
				linkTeam.push_back(i);
			}
		}
		//cout << "startTeam:";
		for (int i = 0; i < startTeam.size(); i++) {
			//cout << startTeam[i] << ' ';
			for (int j = i+1; j < startTeam.size(); j++) {
				startSum += S[startTeam[i]][startTeam[j]] + S[startTeam[j]][startTeam[i]];
			}
		}
		//cout << endl;
		//cout << "linkTeam:";
		for (int i = 0; i < linkTeam.size(); i++) {
			//cout << linkTeam[i] << ' ';
			for (int j = i+1; j < linkTeam.size(); j++) {
				linkSum += S[linkTeam[i]][linkTeam[j]] + S[linkTeam[j]][linkTeam[i]];
			}
		}
		//cout << endl;
		if (abs(startSum - linkSum) < minValue) {
			minValue = abs(startSum - linkSum);
		}
		return;
	}
	for (int i = startTeam.back()+1; i <= N; i++) {
		startTeam.push_back(i);
		solve(startTeam);
		startTeam.pop_back();
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> N;
	for (int y = 1; y <= N; y++)
		for (int x = 1; x <= N; x++)
			cin >> S[y][x];
	vector<int> tmp;
	for (int i = 1; i <= N; i++) {
		tmp.push_back(i);
		solve(tmp);
		tmp.pop_back();
	}
	cout << minValue << endl;
}