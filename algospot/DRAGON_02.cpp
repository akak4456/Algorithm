//result:정답
#include <iostream>
#include <string>
#include <cmath>
#include <algorithm>
using namespace std;
const int MOD = 1000000000;
int stringLength(int n){
	int ret1=1;
	for(int i=1;i<=n+1;i++){
		ret1 *= 2;
		ret1 = min(ret1,MOD);
	}
	int ret2 = 1;
	for(int i=1;i<=n;i++){
		ret2 *= 2;
		ret2 = min(ret2,MOD);
	}
	return min((ret1+ret2-1),MOD);
}
string atString(int p,int generation){
	if(p == 1){
		return "F";
	}
	if(p == 2){
		return "X";
	}
	if(p == 3){
		return "+";
	}
	if(p == 4){
		return "Y";
	}
	if(p == 5){
		return "F";
	}
	int len = stringLength(generation-1);
	if(p <= len){
		return atString(p,generation-1);
	}else if(p == len+1){
		return "+";
	}else if(p == len+len/2+2){
		return "-";
	}else{
		return atString(p-len-1,generation-1);
	}
}
int main(){
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int c;
	cin >> c;
	
	while(c--){
		int n,p,l;
		cin >> n >> p >> l;
		string ans = "";
		for(int i=p;i<p+l;i++){
			ans += atString(i,n);
		}
		cout << ans << '\n';
	}
}