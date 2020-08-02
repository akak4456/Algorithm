//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N,M;
vector<int> adj[1000];
vector<bool> visited;
void dfs(int here){
	visited[here] = true;
	for(int i=0;i<adj[here].size();i++){
		int there = adj[here][i];
		if(!visited[there])
			dfs(there);
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	visited = vector<bool>(N,false);
	for(int i=0;i<M;i++){
		int a,b;
		cin >> a >> b;
		adj[a-1].push_back(b-1);
		adj[b-1].push_back(a-1);
	}
	int cnt = 0;
	for(int i=0;i<N;i++){
		if(!visited[i]){
			cnt++;
			dfs(i);
		}
	}
	cout << cnt << '\n';
}