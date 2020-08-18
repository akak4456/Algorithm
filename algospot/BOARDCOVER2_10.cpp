//result:시간초과
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
vector<string> board;
vector<string> block;
int H,W,R,C;
vector<vector<pair<int,int> > > rotations;
vector<string> rotate(vector<string> origin){
	vector<string> ret = vector<string>(origin[0].size(),"");
	
	for(int i=0;i<origin[0].size();i++){
		for(int j=origin.size()-1;j>=0;j--){
			ret[i] += origin[j][i];
		}
	}
	return ret;
}
void generateRotate(vector<string> block){
	rotations.clear();
	for(int rot=0;rot<4;rot++){
		int startY = -1,startX = -1;
		vector<pair<int,int> > cand;
		for(int i=0;i<block.size();i++){
			for(int j=0;j<block[0].size();j++){
				if(block[i][j] == '#'){
					if(startY == -1){
						startY = i;
						startX = j;
					}
					cand.push_back(make_pair(i-startY,j-startX));
				}
			}
		}
		rotations.push_back(cand);
		block = rotate(block);
	}
	sort(rotations.begin(),rotations.end());
	rotations.erase(unique(rotations.begin(),rotations.end()),rotations.end());
}
int best;
int covered[10][10];
bool canPut(int y,int x,vector<pair<int,int> > block){
	for(int i=0;i<block.size();i++){
		int ny = y+block[i].first;
		int nx = x+block[i].second;
		if(ny <0 || ny >= H || nx < 0 || nx >= W)
			return false;
		if(covered[ny][nx] == 1)
			return false; 
	}
	return true;
}
void set(int y,int x,vector<pair<int,int> > block){
	for(int i=0;i<block.size();i++){
		covered[y+block[i].first][x+block[i].second] = 1;
	}
}
void unset(int y,int x,vector<pair<int,int> > block){
	for(int i=0;i<block.size();i++){
		covered[y+block[i].first][x+block[i].second] = 0;
	}
}
void search(int placed){
	int y=-1,x=-1;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			if(covered[i][j] == 0){
				y = i;
				x = j;
				break;
			}
		}
		if(y != -1) break;
	}
	if(y == -1){
		best = max(best,placed);
		return;
	}
	for(int i=0;i<rotations.size();i++){
		if(canPut(y,x,rotations[i])){
			set(y,x,rotations[i]);
			search(placed+1);
			unset(y,x,rotations[i]);
		}
	}
	covered[y][x] = 1;
	search(placed);
	covered[y][x] = 0;
}
int solve(){
	best = 0;
	for(int i=0;i<H;i++){
		for(int j=0;j<W;j++){
			covered[i][j] = (board[i][j] == '#' ? 1 : 0);
		}
	}
	search(0);
	return best;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		cin >> H >> W >> R >> C;
		board.clear();
		block.clear();
		for(int i=0;i<H;i++){
			string tmp;
			cin >> tmp;
			board.push_back(tmp);
		}
		for(int i=0;i<R;i++){
			string tmp;
			cin >> tmp;
			block.push_back(tmp);
		}
		generateRotate(block);
		cout << solve() << '\n';
	}
}