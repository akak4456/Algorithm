//result:맞았습니다!!
#include <iostream>
#include <cstdio>
#include <algorithm>
#include <vector>
 
using namespace std;
 
vector<int> vc;
 
const int MAX = 1000001;
int main()
{
    int n;
    scanf("%d", &n);
 
    for (int i = 0; i < n; i++)
    {
        int val;
        scanf("%d", &val);
        vc.push_back(val);
    }
 
    vector<int> lis(n + 1, MAX);
    
 
    for (int i = 0; i < n; i++)
    {
        auto it = lower_bound(lis.begin(), lis.end(), vc[i]) - lis.begin();
        lis[it] = vc[i];
    }
 
    int cnt = 0;
    for (int i = 0; i < n; i++)
        if (lis[i] != MAX)
            cnt++;
 
    printf("%d", cnt);
 
    return 0;
}