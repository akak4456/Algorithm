//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define MAX_SIZE 20000+1
#define RED  1
#define BLUE 2

int K,V,E;
vector<int> graph[MAX_SIZE];
int visited[MAX_SIZE];
void bfs(int start);
bool isBipartiteGraph();
void bfs(int start){
	queue<int> q;
	int color = RED;
	
	visited[start] = color;
	q.push(start);
	while(!q.empty()){
		int now = q.front();
		q.pop();
		if(visited[now] == RED){
			color = BLUE;
		}
		else if(visited[now] == BLUE){
			color = RED;
		}
		
		int gsize = graph[now].size();
		for(int i=0;i<gsize;i++){
			int next = graph[now][i];
			if(!visited[next]){
				visited[next] = color;
				q.push(next);
			}
		}
	}
}
bool isBipartiteGraph(){
	for(int i=1;i<=V;i++){
		int gsize = graph[i].size();
		for(int j=0;j<gsize;j++){
			int next = graph[i][j];
			if(visited[i] == visited[next])
				return false;
		}
	}
	return true;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> K;
	while(K--){
		cin >> V >> E;
		memset(visited,0,sizeof(visited));
		for(int i=0;i<MAX_SIZE;i++){
			graph[i].clear();
		}
		for(int i=0;i<E;i++){
			int a,b;
			cin >> a >> b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
		for(int i=1;i<=V;i++){
			if(!visited[i]){
				bfs(i);
			}
		}
		if(isBipartiteGraph()){
			cout << "YES\n";
		}else{
			cout << "NO\n";
		}
	}
}