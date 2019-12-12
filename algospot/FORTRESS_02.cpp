//result:오답
#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
struct Node {
	int x, y, r,idx;
	int depth = 0;
	Node* parent = NULL;
	vector<Node*> child;
};
Node* root;
vector<Node*> nodes;
int C, N;
bool isContain(Node* a, Node* b) {
	double dist = sqrt(pow(a->x - b->x, 2) + pow(a->y - b->y, 2));
	//cout << b->r << " " << a->r << endl;
	return dist < (b->r - a->r);
}
void print() {
	for (int i = 0; i < N; i++) {
		cout << nodes[i]->idx;
		if (nodes[i]->parent != NULL)
			cout << " parent:" << nodes[i]->parent->idx;
		for (int j = 0; j < nodes[i]->child.size(); j++) {
			cout << " child:"<<nodes[i]->child[j]->idx;
		}
		cout << endl;
	}
}
int main() {
	std::ios::sync_with_stdio(false);
	cin >> C;
	while (C--) {
		cin >> N;
		root = NULL;
		nodes.clear();
		for (int i = 0; i < N; i++) {
			Node* tmp = new Node;
			cin >> tmp->x >> tmp->y >> tmp->r;
			tmp->idx = i;
			nodes.push_back(tmp);
			if (i == 0)
				root = tmp;
		}
		for (int i = 1; i < N; i++) {
			int minR = 987654321;
			int minIdx = -1;
			for(int j=0;j<N;j++){
				if (isContain(nodes[i], nodes[j])) {
					if (nodes[j]->r < minR) {
						minR = nodes[j]->r;
						minIdx = j;
					}
				}
			}
			//cout << i << " " << minIdx << endl;
			nodes[i]->parent = nodes[minIdx];
			nodes[minIdx]->child.push_back(nodes[i]);
			nodes[i]->depth = nodes[minIdx]->depth + 1;
		}
		//print();
		vector<pair<int, int> > ans;
		for (int i = 0; i < N; i++) {
			if (nodes[i]->child.size() == 0) {
				ans.push_back({ nodes[i]->depth ,i});
			}
		}
		sort(ans.begin(), ans.end());
		int sum = ans.back().first;
		int idx = ans.back().second;
		vector<int> ancestor;
		ancestor.push_back(idx);
		while(nodes[ancestor.back()]->parent != NULL) {
			ancestor.push_back(nodes[ancestor.back()]->parent->idx);
		}
		ans.pop_back();
		//cout << ans.size() << endl;
		if (ans.size() > 0) {
			while (true) {
				bool canDo = true;
				int tmp = ans.back().first;
				idx = ans.back().second;
				//cout << tmp << endl;
				while (nodes[idx]->parent != NULL) {
					for (int i = 0; i < ancestor.size(); i++) {
						if (nodes[idx]->parent->idx == ancestor[i]&&(nodes[idx]->parent->parent != NULL)) {
							canDo = false;
							break;
						}
					}
					if (!canDo)
						break;
					idx = nodes[idx]->parent->idx;
				}
				if (canDo) {
					sum += tmp;
					break;
				}
				if (ans.size() > 0)
					ans.pop_back();
				else
					break;
			}
		}
		cout << sum << endl;
		for (int i = 0; i < N; i++) {
			delete nodes[i];
		}
	}
}