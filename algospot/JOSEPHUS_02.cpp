//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <stack>
#include <list>
using namespace std;
int N, K;
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    int test_case;
    //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        cin >> N >> K;
        list<int> person;
        for (int i = 1; i <= N; i++) {
            person.push_back(i);
        }
        list<int>::iterator it = person.begin();
        while (person.size() > 2) {
           // cout << *it << endl;
            it = person.erase(it);
            if (person.size() == 2)
                break;
            for (int cnt = 0; cnt < K-1; cnt++) {
                //cout << *it << endl;
                if (it == person.end()) {
                    it = person.begin();
                }
                it++;
                if (it == person.end()) {
                    it = person.begin();
                }
            }
        }
        for (it = person.begin(); it != person.end(); it++) {
            cout << *it << ' ';
        }
        cout << '\n';
    }
}