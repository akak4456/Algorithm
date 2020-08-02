//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int a,b,c,d,e,f;
	cin >> a >> b >> c >> d >> e >> f;
	
	cout << (e*c-b*f)/(a*e-b*d) << ' ' << (-c*d+a*f)/(a*e - b*d) << '\n';
}