//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
const int MAX_N = 10000000;
int factors[MAX_N];
void getFactorsBrute(){
	for(int div=1;div<=MAX_N;div++)
		for(int multiple = div;multiple <= MAX_N;multiple += div)
			factors[multiple] += 1;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	getFactorsBrute();
	while(test_case--){
		int n,lo,hi;
		cin >> n >> lo >> hi;
		int ans = 0;
		for(int i=lo;i<=hi;i++){
		//	cout << "factor:"<<factor(i) << endl;
			if(n == factors[i]){
				ans++;
			}
		}
		cout << ans << '\n';
	}
}