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
vector<int> adj1[10];
vector<int> adj2[10]; 
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
	vector<int> indegree1(N,0);
	vector<int> indegree2(N,0);
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
	queue<int> q;
	
	vector<int> result1;
	while(true){
		bool isupdated = false;
		for(int p=0;p<N;p++){
			if(indegree1[p] == 0){
				q.push(p);
				isupdated = true;
				while(!q.empty()){
					int here = q.front();
					indegree1[here] = -1;
					q.pop();
					result1.push_back(here);
					for(int i=0;i<adj1[here].size();i++){
						int there = adj1[here][i];
						indegree1[there]--;
						if(indegree1[there] == 0){
							q.push(there);
						}
					}			
				}
				break;
			}
		}
		if(!isupdated)
		break;
	}
	
	char ans1[11];
	ans1[N] = '\0';
	for(int i=0;i<result1.size();i++){
		ans1[result1[i]] = '0'+i;
	}
	
	vector<int> result2;
	while(true){
		bool isupdated = false;
		for(int p=0;p<N;p++){
			if(indegree2[p] == 0){
				q.push(p);
				isupdated = true;
				while(!q.empty()){
					int here = q.front();
					indegree2[here] = -1;
					q.pop();
					result2.push_back(here);
					for(int i=0;i<adj2[here].size();i++){
						int there = adj2[here][i];
						indegree2[there]--;
						if(indegree2[there] == 0){
							q.push(there);
						}
					}			
				}
				break;
			}
		}
		if(!isupdated)
		break;
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