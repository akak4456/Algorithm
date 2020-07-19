//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <cstring>
#include <string>
#include <algorithm>
#include <set>
using namespace std;
int main(){
	cin.tie(NULL);
	cout.tie(NULL);
	std::ios::sync_with_stdio(false);
	int N,M;
	cin >> N >> M;
	set<string> s1,s2,intersect;
	for(int i=0;i<N;i++){
		string tmp;
		cin >> tmp;
		s1.insert(tmp);
	}
	for(int i=0;i<M;i++){
		string tmp;
		cin >> tmp;
		s2.insert(tmp);
	}
	set_intersection(s1.begin(),s1.end(),s2.begin(),s2.end(),
                  std::inserter(intersect,intersect.begin()));
    cout << intersect.size() << '\n';
    vector<string> result;
    for(set<string>::iterator it = intersect.begin();it != intersect.end();it++){
    	result.push_back(*it);
	}
	sort(result.begin(),result.end());
	for(int i=0;i<result.size();i++){
		cout << result[i] << '\n';
	}
}