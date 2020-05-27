//result:정답
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <set>
using namespace std;
int gcd(int p,int q){
	if(q == 0) return p;
	return gcd(q,p%q);
}
int n;
int r[1000];
int p[1000];
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	while(test_case--){
		cin >> n;
		for(int i=0;i<n;i++){
			cin >> r[i];
		}
		int g = gcd(r[0],r[1]);
		for(int i=2;i<n;i++){
			g = gcd(g,r[i]);
		}
		for(int i=0;i<n;i++){
			r[i] /= g;
		}
		int max_k = -1;
		for(int i=0;i<n;i++){
			cin >> p[i];
			if(p[i]%r[i] == 0){
				max_k = max(max_k,p[i]/r[i]);
			}else{
				max_k = max(max_k,p[i]/r[i]+1);
			}
		}
		//cout << "g:"<<g<<endl;
		for(int i=0;i<n;i++){
			cout << r[i]*max_k - p[i] << ' ';
		}
		cout << '\n';
	}
}