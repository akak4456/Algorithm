//result:맞았습니다!!
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
vector<int> adj1[10];
vector<int> adj2[10];
vector<int> indegree1;
vector<int> indegree2; 
vector<int> result1,result2;
void dfs1(int here){
//	cout << here << endl;
	indegree1[here] = -1;
	result1.push_back(here);
	for(int i=0;i<adj1[here].size();i++){
		int there = adj1[here][i];
		indegree1[there]--;
		if(indegree1[there] == 0){
			dfs1(there);
		}
	}
}
void dfs2(int here){
	indegree2[here] = -1;
	result2.push_back(here);
	for(int i=0;i<adj2[here].size();i++){
		int there = adj2[here][i];
		indegree2[there]--;
		if(indegree2[there] == 0){
			dfs2(there);
		}
	}
}
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
	indegree1 = vector<int>(N,0);
	indegree2 = vector<int>(N,0);
	for(int i=0;i<N-1;i++){
		if(inequi[i] == '<'){
			adj1[i].push_back(i+1);
			indegree1[i+1]++;
			adj2[i+1].push_back(i);
			indegree2[i]++;
		}else if(inequi[i] == '>'){
			adj1[i+1].push_back(i);
			indegree1[i]++;
			adj2[i].push_back(i+1);
			indegree2[i+1]++;
		}
	}
	
	for(int p=0;p<N;p++){
		if(indegree1[p] == 0){
			//cout << "DFS\n";
			dfs1(p);
		}
	}
	
	char ans1[11];
	ans1[N] = '\0';
	for(int i=0;i<result1.size();i++){
		ans1[result1[i]] = '0'+i;
	}
	
	for(int p=0;p<N;p++){
		if(indegree2[p] == 0){
			dfs2(p);
		}
	}
	char ans2[11];
	ans2[N] = '\0';
	for(int i=0;i<result2.size();i++){
		//cout << result2[i] << endl;
		ans2[result2[i]] = '9'-i;
	}
	cout << ans2 << '\n';
	cout << ans1 << '\n';
}