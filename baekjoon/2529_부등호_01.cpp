//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N;
vector<char> inequi;
vector<int> adj[10]; 
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	inequi.resize(N);
	for(int i=0;i<N;i++){
		cin >> inequi[i];
	}
	N++;
	vector<int> indegree(N,0);
	for(int i=0;i<N-1;i++){
		if(inequi[i] == '<'){
			adj[i].push_back(i+1);
			indegree[i+1]++;
		}else if(inequi[i] == '>'){
			adj[i+1].push_back(i);
			indegree[i]++;
		}
	}
	queue<int> q;
	vector<int> indegree1(indegree);
	for(int i=0;i<N;i++){
		if(indegree1[i] == 0){
			q.push(i);
		}
	}
	vector<int> result1;
	while(!q.empty()){
		int here = q.front();
		q.pop();
		result1.push_back(here);
		for(int i=0;i<adj[here].size();i++){
			int there = adj[here][i];
			indegree1[there]--;
			if(indegree1[there] == 0){
				q.push(there);
			}
		}
	}
	char ans1[11];
	ans1[N] = '\0';
	for(int i=0;i<result1.size();i++){
		ans1[result1[i]] = '0'+i;
	}
	
	vector<int> indegree2(indegree);
	for(int i=N-1;i>=0;i--){
		if(indegree2[i] == 0){
			q.push(i);
		}
	}
	vector<int> result2;
	while(!q.empty()){
		int here = q.front();
		//cout << here << endl;
		q.pop();
		result2.push_back(here);
		for(int i=adj[here].size()-1;i>=0;i--){
			int there = adj[here][i];
			indegree2[there]--;
			if(indegree2[there] == 0){
				q.push(there);
			}
		}
	}
	char ans2[11];
	ans2[N] = '\0';
	reverse(result2.begin(),result2.end());
	for(int i=0;i<result2.size();i++){
		//cout << result2[i] << endl;
		ans2[result2[i]] = '9'-i;
	}
	cout << ans2 << '\n';
	cout << ans1 << '\n';
}