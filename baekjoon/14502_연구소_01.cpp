//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int dy[4] = {-1,0,1,0};
const int dx[4] = {0,1,0,-1};
int N,M;
int m[8][8];
int new_map[8][8];
bool visited[8][8];
void dfs(int y,int x){
	visited[y][x] = true;
	for(int i=0;i<4;i++){
		int ny = y+dy[i];
		int nx = x+dx[i];
		if(ny < 0 || ny >= N || nx < 0 || nx >= M)
			continue;
		if(!visited[ny][nx]&&new_map[ny][nx] != 1){
			new_map[ny][nx] = 2;
			dfs(ny,nx);
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> m[i][j];
		}
	}
	int best = -1;
	for(int i=0;i<N*M;i++){
		for(int j=i+1;j<N*M;j++){
			for(int k=j+1;k<N*M;k++){
				if(m[i/M][i%M]+m[j/M][j%M]+m[k/M][k%M] > 0)
					continue;
				for(int y = 0;y<N;y++){
					for(int x=0;x<M;x++){
						new_map[y][x] = m[y][x];
					}
				}
				new_map[i/M][i%M] = 1;
				new_map[j/M][j%M] = 1;
				new_map[k/M][k%M] = 1;
				memset(visited,0,sizeof(visited));
				for(int y=0;y<N;y++){
					for(int x=0;x<M;x++){
						if(!visited[y][x] && new_map[y][x] == 2){
							dfs(y,x);
						}
					} 
				}
				int cnt = 0;
				for(int y=0;y<N;y++){
					for(int x=0;x<M;x++){
						if(new_map[y][x] == 0){
							cnt++;
						}
					} 
				}
				best = max(best,cnt);
				
			}
		}
	}
	cout << best << '\n';
}