/*
문제
괄호 문자열(Parenthesis String, PS)은 두 개의 괄호 기호인 ‘(’ 와 ‘)’ 만으로 구성되어 있는 문자열이다. 
그 중에서 괄호의 모양이 바르게 구성된 문자열을 올바른 괄호 문자열(Valid PS, VPS)이라고 부른다. 
한 쌍의 괄호 기호로 된 “( )” 문자열은 기본 VPS 이라고 부른다. 만일 x 가 VPS 라면 이것을 하나의 괄호에 넣은 새로운 문자열 “(x)”도 VPS 가 된다. 
그리고 두 VPS x 와 y를 접합(concatenation)시킨 새로운 문자열 xy도 VPS 가 된다. 
예를 들어 “(())()”와 “((()))” 는 VPS 이지만 “(()(”, “(())()))” , 그리고 “(()” 는 모두 VPS 가 아닌 문자열이다. 
여러분은 입력으로 주어진 괄호 문자열이 VPS 인지 아닌지를 판단해서 그 결과를 YES 와 NO 로 나태내야 한다. 

입력
첫째 줄에 괄호 문자열이 한 줄에 주어진다. 하나의 괄호 문자열의 길이는 2 이상 50 이하이다.  

출력
만일 입력 괄호 문자열이 올바른 괄호 문자열(VPS)이면 “YES”, 아니면 “NO”를 한 줄에 하나씩 차례대로 출력해야 한다. 

예제 입력
(())())
예제 출력
NO
*/
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
    stack<char> s1;
    char buf[50];
    bool is = true;


    scanf("%s\n", buf);

    for (int i = 0; i < strlen(buf); i++)
    {
        if (buf[i] == '(')
        {
            s1.push(buf[i]);
        }
        else if (buf[i] == ')')
        {
            if (!s1.empty())
            {
                if (s1.top() != '(')
                {
                    break;
                }
                else if (s1.top() == '(')
                {
                    s1.pop();
                }
            }
        }
    }
    if (s1.empty())
    {
        cout << "YES";
    }
    else
    {
        cout << "NO";
    }

    return 0;
}
