//result:틀렸습니다
#include <iostream>
using namespace std;

int fibo(int n){
    if(n <= 0)
        return 0;
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int N;
    cin >> N;
    cout << fibo(N);
}
