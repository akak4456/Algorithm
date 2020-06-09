//result:시간초과
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
const int INF = 987654321;
const int MAX_V = 2000;
int V,E;
vector<pair<int,int> > adj[MAX_V];
vector<int> weights;

int minUpperBound(int low);

int minWeightDifference(){
	int ret = INF;
	for(int i=0;i<weights.size();i++){
		ret = min(ret,minUpperBound(i)-weights[i]);
	}
	return ret;
}
bool hasPath(int lo,int hi){
	queue<int> q;
	vector<bool> visited(V,false);
	q.push(0);
	visited[0] = true;
	while(!q.empty()){
		int f = q.front();
		q.pop();
		visited[f] = true;
		if(f == V-1)
			return true;
		for(int i=0;i<adj[f].size();i++){
			int there = adj[f][i].first;
			int cost = adj[f][i].second;
			if(!visited[there] && cost >= lo && cost <= hi){
				q.push(there);
				visited[there] = true;
			}
		}
	}
	return false;
}
int binarySearchMinUpperBound(int low){
	int lo = low-1,hi=weights.size();
	while(lo+1<hi){
		int mid = (lo+hi)/2;
		if(hasPath(weights[low],weights[mid]))
			hi=mid;
		else
			lo=mid;
	}
	if(hi==weights.size())return INF;
	return weights[hi];
}
int minUpperBound(int low){
	return binarySearchMinUpperBound(low);
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		weights.clear();
		for(int i=0;i<MAX_V;i++)
			adj[i].clear();
		cin >> V >> E;
		for(int i=0;i<E;i++){
			int a,b,c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b,c));
			adj[b].push_back(make_pair(a,c));
			weights.push_back(c);
		}
		sort(weights.begin(),weights.end());
		cout << minWeightDifference() << '\n';
	}
}