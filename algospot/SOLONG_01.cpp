//result:컴파일 실패
#include <iostream>
#include <vector>
#include <queue>
#include <string>
using namespace std;
const int ALPHABETS = 26;
int toNumber(char ch) {
	return ch - 'A';
}
struct TrieNode {
	int depth;
	TrieNode* children[ALPHABETS];
	priority_queue<pair<int, string>, vector<pair<int, string> >, greater<> > pq;
	bool terminal;
	TrieNode():terminal(false),depth(0) {
		for (int i = 0; i < ALPHABETS; i++)
			children[i] = NULL;
	}
	~TrieNode() {
		for (int i = 0; i < ALPHABETS; i++)
			if (children[i])
				delete children[i];
	}
	void insert(const char* key,pair<int, string> p) {
		if (*key == 0) {
			terminal = true;
		}
		else {
			int next = toNumber(*key);
			if (children[next] == NULL)
				children[next] = new TrieNode();
			children[next]->pq.push(p);
			children[next]->depth = this->depth + 1;
			children[next]->insert(key + 1, p);
		}
	}
	TrieNode* find(const char* key) {
		if (*key == 0) return this;
		int next = toNumber(*key);
		if (children[next] == NULL) return NULL;
		return children[next]->find(key + 1);
	}
};
int C;
int N, M;

int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while(C--) {
		cin >> N >> M;
		TrieNode* root = new TrieNode;
		for (int i = 0; i < N; i++) {
			string t1;
			int t2;
			cin >> t1 >> t2;
			root->insert(t1.c_str(), make_pair(t2, t1));
		}
		int sum = 0;
		for (int i = 0; i < M; i++) {
			char str[11];
			cin >> str;
			char tmp[11];
			for (int j = 1; j <= 10; j++) {
				tmp[j - 1] = str[j - 1];
				tmp[j] = '\0';
				TrieNode* ans = root->find(tmp);
				if (ans == NULL) {
					sum += strlen(str);
					break;
				}
				if (strcmp(ans->pq.top().second.c_str(), str) == 0) {
					sum++;
					sum += ans->depth;
					break;
				}
			}
			cout << sum << endl;
		}
		cout << sum << endl;
		delete root;
	}
}