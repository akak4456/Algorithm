//result:정답
/*
최소 누적 등수, 최대 효용과 같이
최소 최대가 나오면 이것은 최적화 문제이다.
최적화 문제를 푸는 데에는 dp를 적용할 수도 있고 여러가지
방법이 있지만 이 문제와 같이 dp적용도 힘들고 최적화 문제 자체로만
보면 감이 안잡히는 경우가 있다.
이럴 때에는 결정 문제를 한번 생각해 보자
*/
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cmath>
using namespace std;
int n,k;
int c[1000],r[1000];
bool decision(double average){
	vector<double> v;
	for(int i=0;i<n;i++){
		v.push_back(average*c[i]-r[i]);
	}
	sort(v.begin(),v.end());
	double sum = 0;
	for(int i=n-k;i < n;i++)
	sum += v[i];
	return sum >= 0;
}
double optimize(){
	double left = 0,right = 1;
	for(int i=0;i<100;i++){
		double mid = (left+right)/2;
		if(decision(mid)){
			right = mid;
		}else{
			left = mid;
		}
	}
	return left;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int test_case;
	cin >> test_case;
	cout << fixed;
	cout.precision(8);
	while(test_case--){
		cin >> n >> k;
		for(int i=0;i<n;i++){
			cin >> r[i] >> c[i];
		}
		cout << optimize() << '\n';
	}
}