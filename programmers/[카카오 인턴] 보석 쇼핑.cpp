#include <string>
#include <vector>
#include <map>
using namespace std;
map<string,int> idx;
vector<int> solution(vector<string> gems) {
    vector<int> answer;
    int cnt = 0;
    for(int i=0;i<gems.size();i++){
        if(idx.find(gems[i]) == idx.end()){
            idx.insert(make_pair(gems[i],cnt));
            cnt++;
        }
    }
    //인덱스 부여
    int start = 0,end = 0;
    int zeroCnt = idx.size();
    vector<int> gemsCnt = vector<int>(idx.size(),0);
    int minDist = 987654321;
    int minStart,minEnd;
    while(start < gems.size()&&end < gems.size()){
        int id = idx.find(gems[end])->second;
        if(gemsCnt[id] == 0){
            zeroCnt--;
        }
        gemsCnt[id]++;
        if(zeroCnt == 0){
            while(start<gems.size()&&zeroCnt == 0){
                int dist = end - start + 1;
                if(minDist > dist){
                    minStart = start;
                    minEnd = end;
                    minDist = dist;
                }
                int prevId = idx.find(gems[start])->second;
                if(gemsCnt[prevId]-1 == 0){
                    zeroCnt++;
                }
                gemsCnt[prevId]--;
                start++;
            }
        }
        end++;
    }
    answer.push_back(minStart+1);
    answer.push_back(minEnd+1);
    return answer;
}