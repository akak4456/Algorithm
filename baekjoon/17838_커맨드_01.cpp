//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
#include <queue>
using namespace std;
bool solve(string str){
	if(str.size() != 7)
		return false;
	if(str[0] != str[1])
		return false;
	if(str[2] != str[3])
		return false;
	if(str[5] != str[6])
		return false;
	if(str[0] != str[4])
		return false;
	if(str[2] != str[5])
		return false;
	if(str[0] == str[2])
		return false;
	return true;
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int T;
	cin >> T;
	while(T--){
		string str;
		cin >> str;
		if(solve(str)){
			cout << "1\n";
		}else{
			cout << "0\n";
		}
	}
}