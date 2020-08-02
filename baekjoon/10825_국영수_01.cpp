//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
struct Node{
	string name;
	int korean;
	int english;
	int math;
};
bool sortby(const Node& a,const Node& b){
	if(a.korean < b.korean)
		return false;
	else if(a.korean == b.korean){
		if(a.english > b.english)
			return false;
		else if(a.english == b.english){
			if(a.math < b.math)
				return false;
			else if(a.math == b.math){
				return a.name < b.name;
			}else{
				return true;
			}
		}else{
			return true;
		}
	}else{
		return true;
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	vector<Node> nodes;
	int N;
	cin >> N;
	nodes.resize(N);
	for(int i=0;i<N;i++){
		cin >> nodes[i].name >> nodes[i].korean >> nodes[i].english >> nodes[i].math;
	}
	sort(nodes.begin(),nodes.end(),sortby);
	for(int i=0;i<nodes.size();i++){
		cout << nodes[i].name << '\n';
	}
}