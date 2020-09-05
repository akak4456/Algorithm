//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	int cnt1,cnt2,cnt3;
	cnt1 = T/300;
	T %= 300;
	cnt2 = T/60;
	T %= 60;
	cnt3 = T/10;
	T %= 10;
	if(T > 0){
		cout << "-1\n";
	}else{
		cout << cnt1 << ' ' << cnt2 << ' ' << cnt3 <<'\n';
	}
}