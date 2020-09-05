//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <cstring>
using namespace std;
int cnt[26];
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	string src;
	cin >> src;
	for(int i=0;i<src.size();i++){
		cnt[src[i]-'a']++;
	}
	for(int i=0;i<26;i++){
		cout << cnt[i] << ' ';
	}
	cout << '\n';
}