//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
int L,C;
vector<string> src;
vector<string> ans;
void solve(int startIdx,string param){
	if(param.size() == L){
		int mo = 0,ja=0;
		for(int i=0;i<param.size();i++){
			if(param[i] == 'a'||
				param[i] == 'e'||
				param[i] == 'i'||
				param[i] == 'o'||
				param[i] == 'u'){
					mo++;
				}else{
					ja++;
				}
		}
		if(mo >= 1 && ja >= 2){
			ans.push_back(param);
		}
		return;
	}
	for(int i=startIdx;i<C;i++){
		solve(i+1,param+src[i]);
	}
}
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	cin >> L >> C;
	src.resize(C);
	for(int i=0;i<C;i++){
		cin >> src[i];
	}
	sort(src.begin(),src.end());
	solve(0,"");
	for(int i=0;i<ans.size();i++){
		cout << ans[i] << '\n';
	}
}