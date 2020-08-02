//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
#define MAX_SIZE 20000+1
#define RED  1
#define BLUE 2

int N,K;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> K;
	vector<int> remain;
	for(int i=1;i<=N;i++){
		remain.push_back(i);
	}
	vector<int> result;
	int remaincnt = N;
	int idx = 0;
	while(remaincnt > 0){
		int cnt = 0;
		while(true){
			if(remain[idx] != -1){
				cnt++;
				if(cnt == K){
					result.push_back(remain[idx]);
					remain[idx] = -1;
					break;
				}
			}
			idx++;
			if(idx == N)
				idx = 0;
		}
		remaincnt--;
	}
	cout << '<';
	for(int i=0;i<result.size();i++){
		cout << result[i];
		if(i == result.size()-1){
			cout << ">\n";
		}else{
			cout << ", ";
		}
	}
}