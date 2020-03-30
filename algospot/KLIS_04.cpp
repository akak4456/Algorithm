//result:시간초과
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
#include <queue>
#include <map>
using namespace std;
int cache[500];
int N, K;
int arr[500];
int solve(int idx) {
    if (idx == N - 1)
        return cache[idx]=1;
    int& ret = cache[idx];
    if (ret != -1) return ret;
    ret = 1;
    for (int i = idx + 1; i < N; i++) {
        if (arr[idx] < arr[i]) {
            ret = max(ret, solve(i) + 1);
        }
    }
    return ret;
}
int getTh(int idx) {
  //  cout << "ARR " << arr[idx] << endl;
    vector<int> candidate;
    for (int i = idx + 1; i < N; i++) {
        if (cache[idx] - 1 == cache[i] && arr[idx] < arr[i]) {
            candidate.push_back(i);
        }
    }
    if (candidate.size() == 0)
        return 1;
   // cout << "GETTH " << idx << ' ' << candidate.size() << endl;
    int ret = 0;
    for (int i = 0; i < candidate.size(); i++) {
     //   cout << "CANDIDATE " << candidate[i] << endl;
        ret += getTh(candidate[i]);
    }
    return ret;
}
vector<int> result;
void getResult(int remain,int remainK) {
  //  cout << remain << ' ' << remainK << endl;
    vector<pair<int, int> >vec;
    for (int i = 0; i < N; i++) {
        if (cache[i] == remain&&(result.empty()||result.back() < arr[i])) {
            vec.push_back(make_pair(arr[i], i));
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        int getth = getTh(vec[i].second);
       // cout << vec[i].first<<" getTH:" << getth<< endl;
        if (remainK <= getth) {
            result.push_back(vec[i].first);
            getResult(remain - 1, remainK);
            return;
        }
        remainK -= getth;
    }
    /*
    for (int i = 0; i < vec.size(); i++) {
        vector<pair<int,int> > newVec;
        for (int j = 0; j < N; j++) {
            if (cache[j] == remain - 1 && vec[i].first < arr[j]) {
                newVec.push_back(make_pair(arr[j],j));
            }
        }
        sort(newVec.begin(), newVec.end());
        if (newVec.size() == 0) {
            remainK--;
            if (remainK < 0) {
                result.push_back(vec[i].first);
                return;
            }
        }
        for (int j = 0; j < newVec.size(); j++) {
            cout << "newVecFirst:" << newVec[j].first << endl;
            cout << "getTh:" << getTh(newVec[j].second) << endl;
            int getth = getTh(newVec[j].second);
            if (remainK <= getth) {
                result.push_back(vec[i].first);
                getResult(remain - 1, remainK);
                return;
            }
            remainK -= getth;
        }
        
    }
    */
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        result.clear();
        memset(cache, -1, sizeof(cache));
        cin >> N >> K;
        for (int i = 0; i < N; i++)
            cin >> arr[i];
        for (int i = 0; i < N; i++) {
            if (cache[i] == -1)
                solve(i);
        }
        getResult(solve(0), K);
        cout << result.size() << '\n';
        for (int i = 0; i < result.size(); i++) {
            cout << result[i] << ' ';
        }
        cout << '\n';
    }
}