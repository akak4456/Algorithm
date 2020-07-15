//result:맞았습니다!! 
#include <iostream>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int A,B,C;
	cin >> A >> B >> C;
	if(A+B == C){
		cout << A << "+" << B << "=" << C << '\n';
	}else if(A-B == C){
		cout << A << "-" << B << "=" << C << '\n';
	}else if(A*B == C){
		cout << A << "*" << B << "=" << C << '\n';
	}else if(A/B == C){
		cout << A << "/" << B << "=" << C << '\n';
	}else if(A == B+C){
		cout << A << "="<<B << "+" << C <<'\n';
	}else if(A == B-C){
		cout << A << "="<<B << "-" << C <<'\n';
	}else if(A == B*C){
		cout << A << "="<<B << "*" << C <<'\n';
	}else if(A == B/C){
		cout << A << "="<<B << "/" << C <<'\n';
	}
}
