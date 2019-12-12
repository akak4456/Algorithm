//result:시간 초과
#include <iostream>
#include <map>
#include <string>
using namespace std;

map<string, pair<string,int> > id;
int T;
int F;
string find(string p) {
	map<string, pair<string, int> >::iterator it = id.find(p);
	if (it->second.first == p) return p;
	else return it->second.first = find(it->second.first);
}
void uni(string p, string q) {
	p = find(p);
	q = find(q);
	map<string, pair<string, int> >::iterator it1 = id.find(p);
	map<string, pair<string, int> >::iterator it2 = id.find(q);
	it1->second.first = q;
	it2->second.second += it1->second.second;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cin >> T;
	while (T--) {
		cin >> F;
		while (F--) {
			string t1, t2;
			cin >> t1 >> t2;
			map<string, pair<string, int> >::iterator it = id.find(t1);
			if (it == id.end()) {
				id.insert(make_pair(t1, make_pair(t1, 1)));
			}
			it = id.find(t2);
			if (it == id.end()) {
				id.insert(make_pair(t2, make_pair(t2, 1)));
			}
			uni(t1, t2);
			it = id.find(t2);
			cout << it->second.second << endl;
		}
		id.clear();
	}
}