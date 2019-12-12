//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <vector>
#include <algorithm>
using namespace std;
vector<int> preorder;
void postorder(int begin,int end) {
	if (begin > end)
		return;
	if (begin == end) {
		cout << preorder[begin] << '\n';
		return;
	}
	int root = preorder[begin];
	//cout << "root:" << root << endl;
	int mid = begin+1;
	while (mid<preorder.size()&&root > preorder[mid])
		mid++;
	postorder(begin+1, mid - 1);
	postorder(mid, end);
	cout << root << '\n';
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int tmp;
	while (cin >> tmp) {
		preorder.push_back(tmp);
	}
	//cout << preorder.size() << endl;
	postorder(0, preorder.size() - 1);
}