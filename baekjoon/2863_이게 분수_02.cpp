//result:맞았습니다!!
#include <iostream>
using namespace std;
double A,B,C,D;
void rotate(){
	double newA,newB,newC,newD;
	newA = C;
	newB = A;
	newC = D;
	newD = B;
	A = newA;
	B = newB;
	C = newC;
	D = newD;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> A >> B >> C >> D;
	int cnt = 0;
	double maxVal = -1;
	for(int i=0;i<4;i++){
		//cout << A/C + B/D << endl;
		if(A/C+B/D > maxVal){
			cnt = i;
			maxVal = A/C + B/D;
		}
		rotate();
	}
	cout << cnt << '\n';
}