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
	int score;
	int remain;
};
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N;
	cin >> N;
	vector<Node> nodes;
	int ans = 0;
	for(int i=0;i<N;i++){
		int t;
		cin >> t;
		if(t == 1){
			Node tmp;
			cin >> tmp.score >> tmp.remain;
			tmp.remain--;
			if(tmp.remain == 0){
				ans += tmp.score;
			}else{
				nodes.push_back(tmp);
			}
			
		}else if(t == 0){
			if(nodes.size() > 0){
				nodes[nodes.size()-1];
				nodes[nodes.size()-1].remain--;
				//cout << nodes[nodes.size()-1].remain << endl;
				if(nodes[nodes.size()-1].remain == 0){
					ans += nodes[nodes.size()-1].score;
					nodes.pop_back();
				}
			}
		}
	}
	cout << ans << '\n';
}