//result:정답
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>
#include <cmath>
#include <queue>
#include <stack>
using namespace std;
double n, p;
int m;
double balance(double amount, int duration, double rates, double monthlyPayment) {
    double balance = amount;
    for (int i = 0; i < duration; i++) {
        balance *= (1.0 + (rates / 1200.0));
        balance -= monthlyPayment;
    }
    return balance;
}
double payment(double amount, int duration, double rates) {
    double lo = 0, hi = amount * (1.0 + (rates / 1200.0));
    for (int iter = 0; iter < 100; iter++) {
        double mid = (lo + hi) / 2.0;
        if (balance(amount, duration, rates, mid) <= 0)
            hi = mid;
        else lo = mid;
    }
    return hi;
}
int main() {
    std::ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cout << fixed;
    cout.precision(10);
    int test_case;
  //  cout << getSize(1023);
    cin >> test_case;
    while (test_case--) {
        cin >> n >> m >> p;
        cout << payment(n, m, p) << '\n';
    }
}