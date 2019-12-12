//result:맞았습니다!!
#include <iostream>
#include <string>
 
using namespace std;
 
int main() {
    char a;
    a = getchar();
 
    while (a != -1) {
        putchar(a);
        a = getchar();
    }
 
    return 0;
}