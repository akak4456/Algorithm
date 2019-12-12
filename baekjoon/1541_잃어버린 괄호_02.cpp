//result:맞았습니다!!
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
	std::ios::sync_with_stdio(false);
	string input;
	cin >> input;
	string num = "";
	vector<int> nums;
	vector<char> op;
	for (int i = 0; i < input.size(); i++) {
		if (input[i] == '+' || input[i] == '-') {
			op.push_back(input[i]);
			nums.push_back(stoi(num));
			num = "";
		}
		else if (i == input.size() - 1) {
			num += input[i];
			nums.push_back(stoi(num));
			num = "";
		}
		else {
			num += input[i];
		}
	}
	int sum = 0;
	bool minus = false;
	for (int i = 0; i < op.size(); i++) {
		if (minus)
			sum -= nums[i];
		else
			sum += nums[i];
		if (op[i] == '-')
			minus = true;
	}
	if (minus)
		sum -= nums.back();
	else
		sum += nums.back();
	cout << sum << '\n';
}