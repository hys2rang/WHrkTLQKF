/*
문제
접시가 a, b, c, d 가 있고, 알파벳 순으로 한쪽이 막혀 있는 세척기에 들어간다고 할 때, 
b a c d 순으로 꺼내기 위해서는 push, push, pop, pop, push, pop, push, pop을 하면 된다. 
세척기에서 꺼내는 순서가 주어질 때 그 동작을 출력하는 프로그램을 작성하시오. 
만약 주어진 순서대로 접시를 꺼낼 수 없다면 “impossible”을 출력한다. 

입력
첫째 줄에 소문자 알파벳이 주어진다. 중복된 소문자 알파벳은 입력되지 않는다. 알파벳 소문자는 26개이다.  

출력
접시를 꺼내는 것이 가능한 경우 push, pop의 순서를 출력한다. 이것이 불가능하다면 impossible을 출력한다.  

예제 입력
bacd
예제 출력
push
push
pop
pop
push
pop
push
pop

예제 입력
dabc
예제 출력
impossible
*/
#include <iostream>
#include <stack>
#include <string.h>

using namespace std;

int main()
{
    stack<char> s1;
    string str[100];

    char buf[26];
    int in[26] = {0};

    scanf("%s\n", buf);

    for (int i = 0; i < strlen(buf); i++)
    {
        in[buf[i]-97]++;
    }

    int pos = 0;
    int cnt = 0;

    for (int i = 0; i < 26; i++)
    {
        if (in[i] > 0)
        {
            char c = i+97;
            s1.push(c);
            str[cnt++] = "push";
            while (!s1.empty() && s1.top() == buf[pos])
            {
                pos++;
                s1.pop();
                str[cnt++] = "pop";
            }
        }
    }

    if (!s1.empty())
    {
        cout << "impossible" << endl;
    }
    else
    {
        for (int i = 0; i < cnt; i++)
        {
            cout << str[i] << endl;
        }
    }

    return 0;
}