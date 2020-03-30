//result:오답
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
vector<int> result;
int getth[500];
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
    int& ret = getth[idx];
    if (ret != -1) return ret;
    vector<int> candidate;
    for (int i = idx + 1; i < N; i++) {
        if (cache[idx] - 1 == cache[i] && arr[idx] < arr[i]) {
            candidate.push_back(i);
        }
    }
    if (candidate.size() == 0)
        return ret = 1;
    ret = 0;
    for (int i = 0; i < candidate.size(); i++) {
        ret += getTh(candidate[i]);
    }
    return ret;
}

void getResult(int remain,int remainK) {
    vector<pair<int, int> >vec;
    for (int i = 0; i < N; i++) {
        if (cache[i] == remain&&(result.empty()||result.back() < arr[i])) {
            vec.push_back(make_pair(arr[i], i));
        }
    }
    sort(vec.begin(), vec.end());
    for (int i = 0; i < vec.size(); i++) {
        if (remainK <= getTh(vec[i].second)) {
            result.push_back(vec[i].first);
            getResult(remain - 1, remainK);
            return;
        }
        remainK -= getTh(vec[i].second);
    }
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    cin >> test_case;
    while (test_case--) {
        result.clear();
        memset(getth, -1, sizeof(getth));
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