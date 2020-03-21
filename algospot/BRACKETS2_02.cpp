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
        string src;
        cin >> src;
        stack<char> st;
        bool canDo = true;
        for (int i = 0; i < src.size(); i++) {
            if (src[i] == '(') {
                st.push('(');
            }else if (src[i] == '{') {
                st.push('{');
            }else if (src[i] == '[') {
                st.push('[');
            }
            else if (src[i] == ')') {
                if (st.empty() || st.top() != '(') {
                    canDo = false;
                    break;
                }
                st.pop();
            }
            else if (src[i] == '}') {
                if (st.empty() || st.top() != '{') {
                    canDo = false;
                    break;
                }
                st.pop();
            }
            else if (src[i] == ']') {
                if (st.empty() || st.top() != '[') {
                    canDo = false;
                    break;
                }
                st.pop();
            }
        }
        if (!st.empty())
            canDo = false;
        if (canDo)
            cout << "YES\n";
        else
            cout << "NO\n";
    }
}