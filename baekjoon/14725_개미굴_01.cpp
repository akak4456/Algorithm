//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
struct Node {
	string name;
	vector<Node*> nxt;
};
bool sortByName(const Node* a, const Node* b) {
	return a->name < b->name;
}
Node* root = new Node;
int N;
void print(Node* node,int step) {
	if (step > 0) {
		for (int i = 1; i < step; i++) {
			cout << "--";
		}
		cout << node->name << '\n';
	}
	sort(node->nxt.begin(), node->nxt.end(), sortByName);
	for (int i = 0; i < node->nxt.size(); i++) {
		print(node->nxt[i], step + 1);
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> N;
	while(N--) {
		Node* nxtNode = root;
		int k;
		cin >> k;
		for (int i = 0; i < k; i++) {
			string tmpStr;
			cin >> tmpStr;
			bool canPush = true;
			for (int t = 0; t < nxtNode->nxt.size(); t++) {
				if (nxtNode->nxt[t]->name == tmpStr) {
					canPush = false;
					nxtNode = nxtNode->nxt[t];
					break;
				}
			}
			if (canPush) {
				Node* tmp = new Node;
				tmp->name = tmpStr;
				nxtNode->nxt.push_back(tmp);
				nxtNode = tmp;
			}
		}
	}
	print(root,0);
}