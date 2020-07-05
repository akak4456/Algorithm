//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
#include <queue>
using namespace std;
const int MAX_N = 100;
const int MAX_M = 100;
int n,m;
bool adj[MAX_N][MAX_M];
vector<int> aMatch,bMatch;
vector<bool> visited;

bool dfs(int a){
	if(visited[a]) return false;
	visited[a] = true;
	for(int b = 0;b<m;b++){
		if(adj[a][b]){
			if(bMatch[b] == -1 || dfs(bMatch[b])){
				aMatch[a] = b;
				bMatch[b] = a;
				return true;
			}
		}
	}
	return false;
}
int bipartiteMatch(){
	aMatch = vector<int>(n,-1);
	bMatch = vector<int>(m,-1);
	int size = 0;
	for(int start = 0;start<n;start++){
		visited = vector<bool>(n,false);
		if(dfs(start))
			size++;
	}
	return size;
}
const int dx[2] = {-1,1};
const int dy[2] = {1,1};
vector<string> board;
int id[2][8][8];
int placeBishops(){
	memset(id,-1,sizeof(id));
	int count[2] = {0,0};
	for(int dir = 0;dir<2;dir++){
		for(int y=0;y<board.size();y++){
			for(int x = 0;x < board.size();x++){
				if(board[y][x] == '.'&&id[dir][y][x] == -1){
					int cy = y, cx = x;
					while(0<=cy && cy < board.size() &&
						0<=cx && cx < board.size()&&
						board[cy][cx] == '.'){
							id[dir][cy][cx] = count[dir];
							cy += dy[dir];
							cx += dx[dir];
					}
					count[dir]++;
				}
			}
		}
	}
	n = count[0];
	m = count[1];
	memset(adj,0,sizeof(adj));
	for(int y=0;y<board.size();y++)
		for(int x=0;x<board.size();x++)
			if(board[y][x] == '.')
				adj[id[0][y][x]][id[1][y][x]] = 1;
	return bipartiteMatch();
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		int N;
		cin >> N;
		board.clear();
		for(int i=0;i<N;i++){
			string tmp;
			cin >> tmp;
			board.push_back(tmp);
		}
		cout << placeBishops() << '\n';
	}
}