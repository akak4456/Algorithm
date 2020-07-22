//result:시간 초과
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
const int dx[4] = {-1,0,1,0};
const int dy[4] = {0,-1,0,1};
int N,M,G,R;
int originBoard[50][50];
vector<pair<int,int> > candidate;
vector<pair<int,int> > green;
vector<pair<int,int> > red;
int maxcnt = -1;
void bfs(){
	int board[50][50];
	for(int i=0;i<50;i++){
		for(int j=0;j<50;j++){
			board[i][j] = originBoard[i][j];
		}
	}
	queue<pair<pair<int,int>,int> >q;
	int cnt = 0;
	for(int i=0;i<green.size();i++){
		board[green[i].first][green[i].second] = 3;
		q.push(make_pair(green[i],0));
	}
	for(int i=0;i<red.size();i++){
		board[red[i].first][red[i].second] = 4;
		q.push(make_pair(red[i],0));
	}
	while(!q.empty()){
		pair<int,int> pt = q.front().first;
		int step = q.front().second;
		q.pop();
		int y = pt.first;
		int x = pt.second;
		if(board[y][x] == 3){
			for(int i=0;i<4;i++){
				if(y+dy[i] < 0 || y+dy[i] >= N||x+dx[i] < 0 || x+dx[i] >= M){
					continue;
				}
				if(board[y+dy[i]][x+dx[i]] == 1){
					q.push(make_pair(make_pair(y+dy[i],x+dx[i]),step+1));
					board[y+dy[i]][x+dx[i]] = 3 + (step+1)*2;
				}else if(board[y+dy[i]][x+dx[i]] == 4+(step+1)*2){
					board[y+dy[i]][x+dx[i]] = -1;
					cnt++;
				}
			}
		}else if(board[y][x] == 4){
			for(int i=0;i<4;i++){
				if(y+dy[i] < 0 || y+dy[i] >= N||x+dx[i] < 0 || x+dx[i] >= M){
					continue;
				}
				if(board[y+dy[i]][x+dx[i]] == 1){
					q.push(make_pair(make_pair(y+dy[i],x+dx[i]),step+1));
					board[y+dy[i]][x+dx[i]] = 4 + (step+1) * 2;
				}else if(board[y+dy[i]][x+dx[i]] == 3 + (step+1)*2){
					board[y+dy[i]][x+dx[i]] = -1;
					cnt++;
				}
			}
		}
	}
	maxcnt = max(cnt,maxcnt);
}
void chooseRed(int used,int start,int cnt){
	if(cnt == R){
		bfs();
		return;
	}
	for(int i=0;i<candidate.size();i++){
		if((used&(1<<i)) == 0){
			red.push_back(candidate[i]);
			chooseRed(used|(1<<i),i+1,cnt+1);
			red.pop_back();
		}
	}
}
void chooseGreen(int used,int start,int cnt){
	if(cnt == G){
		chooseRed(used,0,0);
		return;
	}
	for(int i=0;i<candidate.size();i++){
		if((used&(1<<i)) == 0){
			green.push_back(candidate[i]);
			chooseGreen(used|(1<<i),i+1,cnt+1);
			green.pop_back();
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M >> G >> R;
	for(int i=0;i<N;i++){
		for(int j=0;j<M;j++){
			cin >> originBoard[i][j];
			if(originBoard[i][j] == 2){
				candidate.push_back(make_pair(i,j));
			}
		}
	}
	chooseGreen(0,0,0);
	cout << maxcnt << '\n';
}