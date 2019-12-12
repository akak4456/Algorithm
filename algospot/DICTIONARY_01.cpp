//result:오답
#include <iostream>
#include <vector>
#include <string>
#include <stack>
using namespace std;
struct Node {
	int data;
	int degree = 0;
	vector<Node*> next;
};
int C, N;
vector<string> words;
Node* nodes[26];
Node* root;
bool visited[26];
bool finish[26];
int cycle;
stack<int> st;
void makeGraph() {
	for (int idx = 0; idx < words.size() - 1; idx++) {
		for (int i = 0; i < (words[idx].size()>words[idx+1].size()? words[idx + 1].size(): words[idx].size()); i++) {
			if (words[idx][i] != words[idx + 1][i]) {
				nodes[words[idx][i] - 97]->next.push_back(nodes[words[idx+1][i] - 97]);
				nodes[words[idx + 1][i]-97]->degree++;
			}
		}
	}
}
void dfs(int v) {
	visited[v] = true;
	for (int i = 0; i < 26; i++) {
		if (!visited[i])
			dfs(i);
		else if (!finish[i])
			cycle = 1;
	}
	finish[v] = true;
	st.push(v);
}
void topologySort() {
	for (int i = 0; i < 26; i++) {
		visited[i] = false;
		finish[i] = false;
	}
	for (int i = 0; i < 26; i++)
		if (!visited[i])
			dfs(i);
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		words.clear();
		root = NULL;
		cycle = 0;
		cin >> N;
		words.resize(N);
		while (!st.empty())
			st.pop();
		for (int i = 0; i < N; i++)
			cin >> words[i];
		for (int i = 0; i < 26; i++) {
			nodes[i] = new Node;
			nodes[i]->data = i;
		}
		makeGraph();
		cout << "ABC" << endl;
		topologySort();
		if (cycle == 1) {
			cout << "INVALID HYPOTHESIS" << endl;
		}
		else {
			cout << "POSSIBLE" << endl;
		}
		for (int i = 0; i < 26; i++) {
			delete nodes[i];
		}
	}
}