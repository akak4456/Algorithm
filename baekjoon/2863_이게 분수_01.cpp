//result:틀렸습니다
#include <iostream>
using namespace std;
int A,B,C,D;
void rotate(){
	int newA,newB,newC,newD;
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
	int maxVal = -1;
	for(int i=0;i<3;i++){
		//cout << A/C + B/D << endl;
		if(A/C+B/D > maxVal){
			cnt = i;
			maxVal = A/C + B/D;
		}
		rotate();
	}
	cout << cnt << '\n';
}