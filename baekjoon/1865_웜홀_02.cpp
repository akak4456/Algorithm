//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MAX_V = 500;
const int INF = 987654321;
int V,M,W;
vector<pair<int,int> > adj[MAX_V];
bool reachable[MAX_V][MAX_V];

vector<int> bellman2(int src){
	vector<int> upper(V,INF);
	upper[src] = 0;
	for(int iter = 0;iter < V-1;iter++){
		for(int here = 0;here<V;here++){
			for(int i=0;i<adj[here].size();i++){
				int there = adj[here][i].first;
				int cost = adj[here][i].second;
				
				upper[there] = min(upper[there],upper[here]+cost);
			}
		}
	}
	for(int here = 0; here < V;here++){
		for(int i=0;i<adj[here].size();i++){
			int there = adj[here][i].first;
			int cost = adj[here][i].second;
			if(upper[here] + cost < upper[there]){
				upper.clear();
				return upper;
			}
		}
	}
	return upper;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		for(int i=0;i<MAX_V;i++){
			adj[i].clear();
		}
		cin >> V>>M>>W;
		for(int i=0;i<M;i++){
			int a,b,d;
			cin >> a >> b >> d;
			adj[a-1].push_back(make_pair(b-1,d));
			adj[b-1].push_back(make_pair(a-1,d));
			//도로는 양방향인 것을 놓침
		}
		for(int i=0;i<W;i++){
			int a,b,d;
			cin >> a >> b >> d;
			adj[a-1].push_back(make_pair(b-1,-d));
		//	adj[b-1].push_back(make_pair(a-1,-d));
		}
		if(bellman2(0).size() > 0){
			cout << "NO\n";
		}else{
			cout << "YES\n";
		}
	}
}