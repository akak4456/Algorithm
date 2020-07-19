//result:틀렸습니다
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int arr[20];
int N,S;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> N >> S;
	for(int i=0;i<N;i++)
		cin >> arr[i];
	int result = 0;
	for(int cnt = 1;cnt<=N;cnt++){
		for(int start = 0;start<=N-cnt;start++){
			int sum = 0;
			for(int t = 0;t<cnt;t++){
				sum += arr[start+t];
			}
			//cout << sum << endl;
			if(sum == S)
				result++;
		}
	}
	cout << result << '\n';
}