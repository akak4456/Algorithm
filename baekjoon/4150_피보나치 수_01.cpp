//result:맞았습니다!!
#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <string>
#include <queue>
#include <stack>
#include <set>
#include <iterator>
using namespace std;
class BigInteger {
private:
	int arr[1001];
public:
	BigInteger(int num) {
		for (int i = 0; i <= 1000; i++)
			arr[i] = 0;
		int idx = 0;
		while (num > 0) {
			arr[idx] = num % 10;
			num /= 10;
			idx++;
		}
	}
	void makeZero() {
		for (int i = 0; i <= 1000; i++) {
			this->arr[i] = 0;
		}
	}
	void copy(const BigInteger& other) {
		for (int i = 0; i <= 1000; i++) {
			this->arr[i] = 0;
		}
		for (int i = 0; i <= 1000; i++) {
			this->arr[i] = other.arr[i];
		}
	}
	void add(const BigInteger& other) {
		//A = A+B
		for (int i = 0; i <= 1000; i++) {
			this->arr[i] += other.arr[i];
		}
		for (int i = 0; i <= 1000; i++) {
			if (this->arr[i] >= 10) {
				if (i < 1000)
					this->arr[i + 1]++;
				this->arr[i] -= 10;
			}
		}
	}
	void print() {
		bool isStart = false;
		for (int i = 1000; i >= 0; i--) {
			if (isStart) {
				cout << this->arr[i];
			}
			if (!isStart && this->arr[i] != 0) {
				cout << this->arr[i];
				isStart = true;
			}
		}
		cout << '\n';
	}
};
int main() {
	std::ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int N;
	cin >> N;
	BigInteger f1(1), f2(1), f3(0);
	if (N == 1 || N == 2) {
		cout << "1\n";
	}
	else {
		for (int i = 3; i <= N; i++) {
			//cout << "i: " << i << endl;
			f3.makeZero();
			f3.add(f1);
			f3.add(f2);
			f1.copy(f2);
			f2.copy(f3);
			//f1.print();
			//f2.print();
			//f3.print();
		}
		f3.print();
		
	}
}