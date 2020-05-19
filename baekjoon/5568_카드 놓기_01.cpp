//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
using namespace std;
int n, k;
vector<string> cards;
set<string> result;
void makeInteger(int candidate,vector<string>& usedCard) {
	if (usedCard.size() == k) {
		string ans = "";
		for (int i = 0; i < usedCard.size(); i++) {
			ans += usedCard[i];
		}
		result.insert(ans);
		return;
	}
	for (int i = 0; i < n; i++) {
		if ((candidate & (1 << i)) > 0)
			continue;
		usedCard.push_back(cards[i]);
		makeInteger(candidate + (1 << i), usedCard);
		usedCard.pop_back();
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> n >> k;
	cards.resize(n);
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	vector<string> tmp;
	makeInteger(0,tmp);
	cout << result.size() << '\n';
}