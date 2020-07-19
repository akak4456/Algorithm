//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int arr[20];
int N,S;
int result = 0;
void solve(int prevsum,int used,int start){
	for(int i=start;i<N;i++){
		if((used&(1<<i)) == 0){
			if(prevsum + arr[i] == S)
				result++;
			solve(prevsum + arr[i],used+(1<<i),i+1);
		}
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> S;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	solve(0,0,0);
	cout << result << '\n';
}