//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
const int INF = 987654321;
int n,k;
int coin[100];
int cache[10001][100];
int solve(int remain,int idx){
	if(remain < 0){
		return INF;
	}
	if(remain == 0)
		return 0;
	if(idx == n)
		return INF;
	int& ret = cache[remain][idx];
	if(ret != -1)return ret;
	ret = solve(remain-coin[idx],idx)+1;
	ret = min(ret,solve(remain,idx+1));
	return ret;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> n >> k;
	for(int i=0;i<n;i++){
		cin >> coin[i];
	}
	memset(cache,-1,sizeof(cache));
	int ans = solve(k,0);
	if(ans == INF)
		cout << "-1\n";
	else
		cout << ans << '\n';
//	cout << solve(k,0) << '\n';
}