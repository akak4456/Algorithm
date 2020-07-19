//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
using namespace std;
int height[9];
int sum = 0;

int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	for(int i=0;i<9;i++){
		cin >> height[i];
		sum += height[i];
	}
	vector<int> result;
	bool isFinish = false;
	for(int i=0;i<9;i++){
		for(int j=0;j<9;j++){
			if(i == j)
				continue;
			if(sum - height[i] - height[j] == 100){
				isFinish = true;
				for(int k=0;k<9;k++){
					if(i==k || j== k)
						continue;
					result.push_back(height[k]);
				}
				break;
			}
		}
		if(isFinish)
			break;
	}
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();i++)
		cout << result[i] << '\n';
}