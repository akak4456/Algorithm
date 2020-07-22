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
int T[16];
int P[16];
int cache[16];
int solve(int day){
	if(day > N+1)
		return 0;
	int& ret = cache[day];
	if(ret != -1) return ret;
	ret = 0;
	if(day+T[day] <= N+1)
		ret = solve(day+T[day])+P[day];
	ret = max(ret,solve(day+1));
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N;
	T[0] = 1;
	P[0] = 0;
	for(int i=1;i<=N;i++){
		cin >> T[i] >> P[i];
	}
	memset(cache,-1,sizeof(cache));
	cout << solve(0) << '\n';
}