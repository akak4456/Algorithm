//result:시간초과
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAX = 987654321;
int C;
int N;
class State {
public:
	int state = 0;
	void changeState(int num, int rod) {
		int token1 = (num - 1) * 2;
		int token2 = (num - 1) * 2 + 1;
		state &= ~(1 << token1);
		state &= ~(1 << token2);
		if (rod == 1) {
			state |= (1 << token1);
		}
		else if (rod == 2) {
			state |= (1 << token2);
		}
		else if (rod == 3) {
			state |= (1 << token1);
			state |= (1 << token2);
		}
	}
	int getState(int num) {
		int token1 = (num - 1) * 2;
		int token2 = (num - 1) * 2 + 1;
		int ret = 0;
		if ((state & (1 << token1)) == 1) ret += 1;
		if ((state & (1 << token2)) == 1) ret += 2;
		return ret;
	}
	vector<State> getAdjacent() {
		vector<State> ret;
		int minNum[4] = { MAX,MAX,MAX,MAX };
		for (int i = 1; i <= N; i++) {
			int rod = getState(i);
			if (i < minNum[rod]) {
				minNum[rod] = i;
			}
		}
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++) {
				if (minNum[i] < minNum[j]) {
					changeState(minNum[i], j);
					ret.push_back(*this);
					changeState(minNum[i], i);
				}
			}
		}
		return ret;
	}
	bool operator < (const State& rhs) const {
		return this->state < rhs.state;
	}
	bool operator == (const State& rhs) const {
		return this->state == rhs.state;
	}
};
int best;
void dfs(State here, const State& finish, int steps) {
	if (steps >= best) return;
	if (here == finish) { best = steps; return; }
	vector<State> adjacent = here.getAdjacent();
	for (int i = 0; i < adjacent.size(); i++)
		dfs(adjacent[i], finish, steps + 1);
}
int ids(State start, State finish, int growthStep) {
	for (int limit = 0;; limit += growthStep) {
		best = limit + 1;
		dfs(start, finish, 0);
		if (best <= limit) return best;
	}
	return -1;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		State finish;
		for (int i = 1; i <= N; i++) {
			finish.changeState(i, 3);
		}
		State start;
		for (int i = 0; i < 4; i++) {
			int cnt;
			cin >> cnt;
			while (cnt--) {
				int t;
				cin >> t;
				start.changeState(t, i);
			}
		}
		cout << ids(start, finish, 1);
	}
}