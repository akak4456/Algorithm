//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
const int MAX_N = 10000000;
int minFactor[MAX_N + 1];
void eratosthenes2(){
	minFactor[0] = minFactor[1] = -1;
	for(int i=2;i<=MAX_N;i++)
		minFactor[i] = i;
	int sqrtn = int(sqrt(MAX_N));
	for(int i=2;i<=sqrtn;i++){
		if(minFactor[i] == i){
			for(int j=i*i;j<=MAX_N;j+=i){
				if(minFactor[j] == j)
					minFactor[j] = i;
			}
		}
	}
}
int factor(int n){
	int before = minFactor[n];
	int ret = 1;
	int tmp = 2;
	n /= minFactor[n];
	while(n > 1){
		if(before != minFactor[n]){
			ret *= tmp;
			tmp = 2;
			before = minFactor[n];
		}else{
			tmp++;
		}
		n /= minFactor[n];
	}
	//cout << tmp << endl;
	return ret * tmp;
}
int n;
int lo;
int hi;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	eratosthenes2();
	cin >> test_case;
	while(test_case--){
		cin >> n >> lo >> hi;
		int ans = 0;
		for(int i=lo;i<=hi;i++){
		//	cout << "factor:"<<factor(i) << endl;
			if(n == factor(i)){
				ans++;
			}
		}
		cout << ans << '\n';
	}
}