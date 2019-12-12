//result:맞았습니다!!
#include <iostream>
using namespace std;

int fibo(int n){
    if(n == 0)
        return 0;
    else if(n <= 2)
        return 1;
    return fibo(n-1)+fibo(n-2);
}
int main(){
    int N;
    cin >> N;
    cout << fibo(N);
}