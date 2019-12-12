//result:틀렸습니다
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
	for (int i = 0; i < op.size(); i++) {
		if (op[i] == '+') {
			nums[i] = nums[i] + nums[i + 1];
			for (int j = i + 1; j < nums.size()-1; j++) {
				nums[j] = nums[j + 1];
			}
			nums.pop_back();
			for (int j = i; j < op.size() - 1; j++) {
				op[j] = op[j + 1];
			}
			op.pop_back();
		}
	}
	int sum = nums[0];
	for (int i = 1; i < nums.size(); i++) {
		sum -= nums[i];
	}
	cout << sum << '\n';
}