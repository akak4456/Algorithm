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
int V;
int capacity[300][300],flow[300][300];

int networkFlow(int source,int sink){
	memset(flow,0,sizeof(flow));
	int totalFlow = 0;
	while(true){
		vector<int> parent(300,-1);
		queue<int> q;
		parent[source] = source;
		q.push(source);
		while(!q.empty()&&parent[sink] == -1){
			int here = q.front();q.pop();
			for(int there = 0;there < V;there++)
				if(capacity[here][there] - flow[here][there] > 0&&
				parent[there] == -1){
					q.push(there);
					parent[there] = here;
				}
		}
		if(parent[sink] == -1) break;
		int amount = INF;
		for(int p = sink;p != source;p = parent[p])
			amount = min(capacity[parent[p]][p]-flow[parent[p]][p],amount);
		
		for(int p = sink;p != source;p = parent[p]){
			flow[parent[p]][p] += amount;
			flow[p][parent[p]] -= amount;
		}
		totalFlow += amount;
	}
	return totalFlow;
}
int n,m;
int wins[12], match[100][2];

bool canWinWith(int totalWins){
	if(*max_element(wins+1,wins+n) >= totalWins)
		return false;
	
	V = 2 + m + n;
	
	memset(capacity,0,sizeof(capacity));
	for(int i=0;i<m;i++){
		capacity[0][2+i] = 1;
		for(int j=0;j<2;j++)
			capacity[2+i][2+m+match[i][j]] = 1;
	}
	
	for(int i=0;i<n;i++){
		int maxWin = (i == 0?totalWins:totalWins-1);
		capacity[2+m+i][1] = maxWin-wins[i];
	}
	//cout << networkFlow(0,1) << endl;;
	return (networkFlow(0,1) == m&&(capacity[2+m][1]-flow[2+m][1]) == 0 );
	
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		cin >> n >> m;
		for(int i=0;i<n;i++)
			cin >> wins[i];
		for(int i=0;i<m;i++)
			cin >> match[i][0] >> match[i][1];
		int ans = -1;
		for(int i=1;i<=1100;i++){
			if(canWinWith(i)){
				ans = i;
				break;
			}
		}
		cout << ans << '\n';
	}
}