//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
using namespace std;
struct DisjointSet{
	vector<int> parent,rank;
	DisjointSet(int n):parent(n),rank(n,1){
		for(int i=0;i<n;i++){
			parent[i] = i;
		}
	}
	int find(int u){
		if(u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u,int v){
		u = find(u); v=find(v);
		if(u == v) return;
		if(rank[u] > rank[v]) swap(u,v);
		parent[u] = v;
		if(rank[u] == rank[v]) rank[v]++;
	}
};
const int MAX_V = 500;
int V,M;
double adj[MAX_V][MAX_V];
double krusukal(){
	double ret = 0;
	vector<pair<double,pair<int,int> > > edges;
	for(int u=0;u<V;u++){
		for(int v=0;v<V;v++){
			if(u == v) continue;
			edges.push_back(make_pair(adj[u][v],make_pair(u,v)));
		}
	}
	sort(edges.begin(),edges.end());
	DisjointSet sets(V);
	for(int i=0;i<edges.size();i++){
		double cost = edges[i].first;
		int u = edges[i].second.first,v = edges[i].second.second;
		if(sets.find(u) == sets.find(v)) continue;
		sets.merge(u,v);
		ret += cost;
	}
	return ret;
}
vector<pair<int,int> > coord;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	cout<<fixed;
	cout.precision(10);
	while(test_case--){
		cin >> V >> M;
		coord.resize(V);
		for(int i=0;i<V;i++)
			cin >> coord[i].first;
		for(int i=0;i<V;i++)
			cin >> coord[i].second;
		for(int i=0;i<V;i++){
			for(int j=0;j<V;j++){
				double cost = sqrt(pow(coord[i].first-coord[j].first,2)+pow(coord[i].second-coord[j].second,2));
				adj[i][j] = cost;
			}
		}
		for(int i=0;i<M;i++){
			int a,b;
			cin >> a >> b;
			adj[a][b] = adj[b][a] = 0;
		}
		cout << krusukal() << '\n';
	}
}