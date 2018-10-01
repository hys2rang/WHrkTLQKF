/*
문제
두 자연수가 주어질 때 그들의 곱셈을 계산하는 프로그램을 작성하시오. 각 수는 1 이상 10^100 미만의 범위를 가진다.  

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.  

출력
첫 번째 줄에 곱셈의 결과를 출력한다.  

예제 입력
123112981293812938139
1298928491101221811
예제 출력
159914959026945386297336486942660549729
 
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char buf1[105];
    char buf2[105];

    int num1[105] = {0};

    int num2[105] = {0};

    int ans[205] = {0};

    int start = 0;
    int n;

    scanf("%s\n", buf1);
    scanf("%s\n", buf2);

    n = strlen(buf1) > strlen(buf2) ? strlen(buf1) : strlen(buf2);

    for (int i = 0; i < strlen(buf1); i++)
    {
        num1[i] = buf1[i] - '0';
    }

    for (int i = 0; i < strlen(buf2); i++)
    {
        num2[i] = buf2[i] - '0';
    }

    if (strlen(buf1) - n == 0)
    {
        //buf1이 더 길면 buf2를 밀어줌
        for (int i = strlen(buf2) - 1; i >= 0; i--)
        {
            num2[i + (n - strlen(buf2))] = num2[i];
        }
        for (int i = 0; i < n - strlen(buf2); i++)
        {
            num2[i] = 0;
        }
    }
    else
    {
        for (int i = strlen(buf1) - 1; i >= 0; i--)
        {
            num1[i + (n - strlen(buf1))] = num1[i];
        }
        for (int i = 0; i < n - strlen(buf1); i++)
        {
            num1[i] = 0;
        }
    }

    for (int i = n - 1, j = strlen(buf1)+strlen(buf2); i >= 0; i--, j--)
    {
        for (int k = n - 1,l=j; k >= 0; k--,l--)
        {
            if(num1[k]*num2[i]>=10){
                ans[l-1]+=(num1[k]*num2[i])/10;
            }
            ans[l]+=(num1[k]*num2[i])%10;
            if(ans[l]>=10){
                ans[l-1]+=(ans[l]/10);
                ans[l] = ans[l] %10;
            }
        }
    }

    for (int i = 0; i < strlen(buf1)+strlen(buf2) + 1; i++)
    {
        if (ans[i] != 0)
        {
            start = i;
            break;
        }
        if(i==strlen(buf1)+strlen(buf2)){
            start = strlen(buf1)+strlen(buf2);
        }
    }

    for (int i = start; i < strlen(buf1)+strlen(buf2) + 1; i++)
    {
        cout << ans[i];
    }

    return 0;
}
