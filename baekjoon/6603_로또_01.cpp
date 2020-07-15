//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
using namespace std;
vector<int> candidate;
void solve(vector<int> result,int start){
	if(result.size() == 6){
		for(int i=0;i<6;i++)
			cout << result[i] << ' ';
		cout << '\n';
		return;
	}
	for(int i=start;i<candidate.size();i++){
		result.push_back(candidate[i]);
		solve(result,i+1);
		result.pop_back();
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int n;
	while(true){
		cin >> n;
		if(n == 0)
		break;
		candidate.clear();
		candidate.resize(n);
		for(int i=0;i<n;i++)
			cin >> candidate[i];
		vector<int> tmp;
		solve(tmp,0);
		cout << '\n';
	}
}