//result:맞았습니다!!
#include <iostream>
using namespace std;
int N,M;
int A[10000];
int partialSum[10000];
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> M;
	for(int i=0;i<N;i++){
		cin >> A[i];
	}
	partialSum[0] = A[0];
	for(int i=1;i<N;i++){
		partialSum[i] = partialSum[i-1]+A[i];
	}
	int start = 0,end = 0;
	int sum = A[0];
	int cnt = 0;
	while(true){
		
		if(sum == M){
			cnt++;
			sum -= A[start];
			sum += A[end+1];
			start++;
			end++;
		}else if(sum > M){
			sum -= A[start];
			start++;
		}else{
			end++;
			sum += A[end];
		}
		//cout << start << ' ' << end << endl;
		if(end == N){
			break;
		}
	}
	cout << cnt << '\n';
}