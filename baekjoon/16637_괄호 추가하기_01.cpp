//result:맞았습니다!!
#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
string subStr(string src, int from, int to) {
	string ret;
	for (int i = from; i < to; i++) {
		ret += src[i];
	}
	return ret;
}
int best = -(1 << 31);
void solve(string str,int pos) {
	vector<int> operand;
	vector<char> op;
	int startPoint = 0;
	for (int i = 1; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '*') {
			operand.push_back(stoi(subStr(str, startPoint, i)));
			op.push_back(str[i]);
			startPoint = i + 1;
			if (str[i + 1] == '-') {
				i++;
			}
		}
	}
	operand.push_back(stoi(subStr(str, startPoint, str.size())));
	if (pos + 1 < op.size()) {
		for (int i = pos + 1; i < op.size(); i++) {
			vector<int> newOperand;
			vector<char> newOp;
			for (int j = 0; j < operand.size(); j++) {
				if (j != i && j != i + 1) {
					newOperand.push_back(operand[j]);
					if (j != operand.size() - 1)
						newOp.push_back(op[j]);
				}
				else {
					if (op[j] == '+') {
						newOperand.push_back(operand[j] + operand[j + 1]);
					}
					else if (op[j] == '-') {
						newOperand.push_back(operand[j] - operand[j + 1]);
					}
					else if (op[j] == '*') {
						newOperand.push_back(operand[j] * operand[j + 1]);
					}
					if (j + 1 != operand.size() - 1)
						newOp.push_back(op[j + 1]);
					j++;
				}
			}
			string s = "";
			for (int j = 0; j < newOp.size(); j++) {
				s += to_string(newOperand[j]) + newOp[j];
			}
			s += to_string(newOperand[newOperand.size() - 1]);
			solve(s, i);
		}
	}
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+') {
			operand[i + 1] = operand[i] + operand[i + 1];
		}
		else if (op[i] == '-') {
			operand[i + 1] = operand[i] - operand[i + 1];
		}
		else if (op[i] == '*') {
			operand[i + 1] = operand[i] * operand[i + 1];
		}
	}
	if (operand[operand.size() - 1] > best) {
		best = operand[operand.size() - 1];
	}
	//cout << str << ' ' << operand[operand.size() - 1] << endl;
}
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	string str;
	cin >> N >> str;
	solve(str, -1);
	cout << best << '\n';
}