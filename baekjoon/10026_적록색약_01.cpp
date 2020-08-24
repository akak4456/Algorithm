//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int N;
char board[100][100];
int visited[100][100];
void dfs(int y,int x,char ch){
	visited[y][x] = 1;
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= N)
			continue;
		if(visited[ny][nx] == 0 && board[ny][nx] == ch){
			dfs(ny,nx,ch);
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cin >> board[i][j];
		}
	}
	int cnt1 = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visited[i][j] == 0){
				cnt1++;
				dfs(i,j,board[i][j]);
			}
		}
	}
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(board[i][j] == 'G'){
				board[i][j] = 'R';
			}
		}
	}
	memset(visited,0,sizeof(visited));
	int cnt2 = 0;
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			if(visited[i][j] == 0){
				cnt2++;
				dfs(i,j,board[i][j]);
			}
		}
	}
	cout << cnt1 << ' ' << cnt2 << '\n';
	
}