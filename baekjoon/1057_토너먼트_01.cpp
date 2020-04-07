//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
using namespace std;
int solve(vector<int> player, int depth) {
	if (player.size() == 1)
		return -1;
	vector<int> newPlayer;
	for (int i = 0; i < player.size(); i += 2) {
		if (i + 1 >= player.size()) {
			newPlayer.push_back(player[i]);
		}
		else {
			if (player[i]*player[i+1] == 1) {
				newPlayer.push_back(1);
			}
			else if (player[i] * player[i + 1] == 6) {
				return depth;
			}
			else {
				if (player[i] == 2 || player[i + 1] == 2) {
					newPlayer.push_back(2);
				}
				if (player[i] == 3 || player[i + 1] == 3) {
					newPlayer.push_back(3);
				}
			}
		}
	}
	return solve(newPlayer, depth + 1);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	vector<int> player;
	player.resize(N);
	int p1, p2;
	cin >> p1 >> p2;
	for (int i = 0; i < N; i++) {
		if (p1 == i + 1)
			player[i] = 2;
		else if (p2 == i + 1)
			player[i] = 3;
		else
			player[i] = 1;
	}
	cout << solve(player, 1) << '\n';
}