//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
int N,M;
vector<int> A,B,C;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	A.resize(N);
	B.resize(M);
	C.resize(N+M);
	for(int i=0;i<N;i++)
		cin >> A[i];
	for(int i=0;i<M;i++)
		cin >> B[i];
	int aIdx = 0,bIdx = 0;
	int cIdx = 0;
	while(aIdx < A.size() && bIdx < B.size()){
		if(A[aIdx] < B[bIdx]){
			C[cIdx++] = A[aIdx++];
		}else{
			C[cIdx++] = B[bIdx++];
		}
	}
	while(aIdx < A.size()){
		C[cIdx++] = A[aIdx++];
	}
	while(bIdx < B.size()){
		C[cIdx++] = B[bIdx++];
	}
	for(int i=0;i<N+M;i++){
		cout << C[i] << ' ';
	}
	cout << '\n';
}