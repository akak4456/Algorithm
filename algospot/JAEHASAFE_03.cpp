//result:정답
#include <iostream>

#include <string>

#include <vector>

using namespace std;

 

//N에서 자기 자신을 찾으면서 나타나는 부분 일치를 이용해 pi[]를 계산

//pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이

vector<int> getPartialMatch(const string &N)

{

        int m = N.size();

        vector<int> pi(m, 0);

 

        //KMP로 자기 자신을 찾는다

        //N을 N에서 찾는다. begin=0이면 자기 자신을 찾아버리니까 안됨!

        int begin = 1, matched = 0;

        //비교할 문자가 N의 끝에 도달할 때까지 찾으면서 부분 일치를 모두 기록

        while (begin + matched < m)

        {

                 if (N[begin + matched] == N[matched])

                 {

                         ++matched;

                         pi[begin + matched - 1] = matched;;

                 }

                 else

                 {

                         if (matched == 0)

                                 ++begin;

                         else

                         {

                                 begin += matched - pi[matched - 1];

                                 matched = pi[matched - 1];

                         }

                 }

        }

        return pi;

}

 

//짚더미 H의 부분 문자열로 바늘 N이 출현하는 시작 위치들을 모두 반환

vector<int> kmpSearch(const string &H, const string &N)

{

        int n = H.size(), m = N.size();

        vector<int> result;

        //pi[i]=N[..i]의 접미사도 되고 접두사도 되는 문자열의 최대 길이

        vector<int> pi = getPartialMatch(N);

 

        //begin = matched = 0에서부터 시작

        int begin = 0, matched = 0;

        while (begin <= n - m)

        {

                 //만약 짚더미의 해당 글자가 바늘의 해당 글자와 같다면

                 if (matched < m && H[begin + matched] == N[matched])

                 {

                         ++matched;

                         //결과적으로 m 글자가 모두 일치했다면 답에 추가

                         if (matched == m)

                                 result.push_back(begin);

                 }

                 else

                 {

                         //예외: matched가 0인 경우에는 다음 칸에서부터 계속

                         if (matched == 0)

                                 ++begin;

                         else

                         {

                                 begin += matched - pi[matched - 1];

                                 //begin을 옮겼다고 처음부터 다시 비교할 필요 없음

                                 //옮긴 후에도 pi[matched-1]만큼은 항상 일치

                                 matched = pi[matched - 1];

                         }

                 }

        }

        return result;

}

 

//문자열 original을 target으로 만들기 위해 환형 시프트를 몇 번이나 해야하는지 반환

//환형문자열을 두배로 늘려서 일반 문자열처럼 만듬

int shift(const string &original, const string &target)

{

        return kmpSearch(original + original, target)[0]; //반시계 방향

}

 

int main(void)

{

        int test_case;

        cin >> test_case;

 

        for (int i = 0; i < test_case; i++)

        {

                 int N;

                 cin >> N;

 

                 vector<string> dial;

 

                 for (int i = 0; i <= N; i++)

                 {

                         string temp;

                         cin >> temp;

                         dial.push_back(temp);

                 }

 

                 int result = 0;

                 for (int i = 0; i < N; i++)

                 {

                         int clockwise = i % 2;

 

                         //dial[i]를 dial[i+1]처럼 만들기 위해 반시계방향으로 돌린 횟수 = dail[i+1]이 dial[i]처럼 만들기 위해 시계방향으로 돌린 횟수

                         if (clockwise)

                                 result += shift(dial[i], dial[i + 1]); //시계 방향

                         else

                                 result += shift(dial[i + 1], dial[i]); //반시계 방향

                 }

                 cout << result << endl;

        }

}