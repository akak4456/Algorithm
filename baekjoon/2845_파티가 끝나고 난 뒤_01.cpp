//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int L,P;
	cin >> L >> P;
	int t[5];
	for(int i=0;i<5;i++){
		cin >> t[i];
	}
	for(int i=0;i<5;i++){
		cout << (t[i]-L*P) << ' ';
	}
	cout << '\n';
}