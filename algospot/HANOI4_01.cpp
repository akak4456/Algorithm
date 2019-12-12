//result:오답
#include <iostream>
#include <vector>
#include <map>
using namespace std;
const int MAX = 987654321;
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
	vector<State> getAdjacent() {
		vector<State> ret;
		return ret;
	}
};
int main() {

}