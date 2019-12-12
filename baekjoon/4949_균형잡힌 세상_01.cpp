//result:맞았습니다!!
#include <iostream>

#include <string>

#include <stack>

using namespace std;

 

int main(void)

{

        ios_base::sync_with_stdio(0);

        cin.tie(0);

        while (1)

        {

                 string s;

                 getline(cin, s);

                 stack<char> st;

 

                 if (s.length() == 1 && s[0] == '.')

                         break;

 

                 bool flag = true;

                 for (int j = 0; j < s.length(); j++)

                 {

                         if (s[j] == '(')

                                 st.push('(');

                         else if (s[j] == '[')

                                 st.push('[');

                         else if (s[j] == ']')

                         {

                                 if (!st.empty() && st.top() == '[')

                                          st.pop();

                                 else

                                 {

                                          flag = false;

                                          break;

                                 }

                         }

                         else if (s[j] == ')')

                         {

                                 if (!st.empty() && st.top() == '(')

                                          st.pop();

                                 else

                                 {

                                          flag = false;

                                          break;

                                 }

                         }

                 }

 

                 if (flag && st.empty())

                         cout << "yes\n";

                 else

                         cout << "no\n";

        }

        return 0;

}