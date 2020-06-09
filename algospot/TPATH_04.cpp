//result:정답
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
struct DisjointSet{
	vector<int> parent,rank;
	DisjointSet(int n):parent(n),rank(n,1){
		for(int i=0;i<n;i++)
			parent[i] = i;
	}
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u,int v){
		u = find(u);v=find(v);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u,v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]++;
	}
};
vector<pair<int,pair<int,int> > > edges;
int kruskalMinUpperBound(int low){
	DisjointSet sets(V);
	for(int i=0;i<edges.size();i++){
		if(edges[i].first < weights[low]) continue;
		
		sets.merge(edges[i].second.first,edges[i].second.second);
		
		if(sets.find(0) == sets.find(V-1))
			return edges[i].first;
	}
	return INF;
}
int minUpperBound(int low){
	return kruskalMinUpperBound(low);
}
int optimized(){
	int ret = INF,foundPathUsing = 0;
	for(int lo = 0;lo<weights.size();lo++){
		bool foundPath = false;
		for(int hi = foundPathUsing;hi<weights.size();hi++){
			if(hasPath(weights[lo],weights[hi])){
				ret = min(ret,weights[hi]-weights[lo]);
				foundPath = true;
				foundPathUsing = hi;
				break;
			}
		}
		if(!foundPath) break;
	}
	return ret;
}
int scanning(){
	int lo = 0,hi = 0, ret = INF;
	while(lo < weights.size()&&hi<weights.size()){
		if(hasPath(weights[lo],weights[hi])){
			ret = min(ret,weights[hi]-weights[lo]);
			lo++;
		}else{
			hi++;
		}
	}
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		weights.clear();
		edges.clear();
		for(int i=0;i<MAX_V;i++)
			adj[i].clear();
		cin >> V >> E;
		for(int i=0;i<E;i++){
			int a,b,c;
			cin >> a >> b >> c;
			adj[a].push_back(make_pair(b,c));
			adj[b].push_back(make_pair(a,c));
			weights.push_back(c);
			edges.push_back(make_pair(c,make_pair(a,b)));
		}
		sort(weights.begin(),weights.end());
		//sort(edges.begin(),edges.end());
		//cout << minWeightDifference() << '\n';
		//cout << optimized()<<'\n';
		cout << scanning()<<'\n';
	}
}