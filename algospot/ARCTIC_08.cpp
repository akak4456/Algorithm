//result:정답
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int N;
vector<pair<double,double> > pos;//x,y
vector<bool> visited;
void dfs(int src,double D){
	visited[src] = true;
	for(int i=0;i<N;i++){
		if(!visited[i]){
			double x1 = pos[src].first;
			double y1 = pos[src].second;
			double x2 = pos[i].first;
			double y2 = pos[i].second;
			double dist = sqrt(pow(x1-x2,2)+pow(y1-y2,2));
			if(dist <= D){
				dfs(i,D);
			}
		}
	}
}
bool decision(double D){
	visited = vector<bool>(N,false);
	dfs(0,D);
	for(int i=0;i<N;i++){
		if(!visited[i])
			return false;
	}
	return true;
}
double solve(){
	double lo = 0,hi = 1000;
	for(int i=0;i<50;i++){
		double mid = (lo+hi)/2;
		if(decision(mid)){
			hi = mid;
		}else{
			lo = mid;
		}
	}
	return lo;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	cout << fixed;
	cout.precision(2);
	while(test_case--){
		cin >> N;
		pos.clear();
		pos.resize(N);
		for(int i=0;i<N;i++){
			cin >> pos[i].first >> pos[i].second;
		}
		cout << solve() << '\n';
	}
}