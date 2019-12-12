//result:정답
#include <iostream>
#include <list>
using namespace std;
int C;
int N, K;
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N >> K;
		list<int> man;
		for (int i = 0; i < N; i++) {
			man.push_back(i + 1);
		}
		list<int>::iterator it = man.begin();
		while (man.size() > 2) {
			it = man.erase(it);
			if (it == man.end())
				it = man.begin();
			for (int i = 0; i < K-1; i++) {
				it++;
				if (it == man.end())
					it = man.begin();		
			}
		}
		for (it = man.begin(); it != man.end(); it++)
			cout << *it << " ";
		cout << endl;
		man.clear();
	}
}