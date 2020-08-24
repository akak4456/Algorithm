//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
const int MOD = 1000000007;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n;
	cin >> n;
	if(n == 0){
		cout << "0\n";
	}else if(n == 1){
		cout << "1\n";
	}else{
		long long int a,b,c;
		a = 0;
		b = 0;
		c = 1;
		for(int i=2;i<=n;i++){
		//	cout << (b+c)%MOD << endl;
			a = (b+c)%MOD;
			a %= MOD;
			b = c;
			c = a;
		}
		cout << a%MOD << "\n"; 
	}
	
}