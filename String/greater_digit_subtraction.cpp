/*
문제
두 자연수가 주어질 때 그들의 뺄셈을 계산하는 프로그램을 작성하시오. 각 수는 1 이상 10^100 미만의 범위를 가진다.  

입력
첫 번째 줄과 두 번째 줄에 각각 하나의 자연수가 주어진다.  

출력
첫 번째 줄에 뺄셈의 결과를 출력한다.  

예제 입력
1962831868293922
2528838232
예제 출력
1962829339455690
 

예제 입력
18592918185
2195812983912895799129
예제 출력
-2195812983894302880944
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

    int ans[105] = {0};

    int start = 0;
    int n;
    bool sign = false;

 //   freopen("Sample.txt","r",stdin);
    
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

    for (int i = 0; i < n; i++)
    {
        if (num1[i + 1] == num2[i + 1] && num1[i + 2] >= num2[i + 2])
            ;
        else if (ans[i + 1] + num1[i + 1] <= num2[i + 1] && i != n - 1)
        {
            ans[i] += -1;
            ans[i + 1] += 10;
        }
        ans[i] += num1[i] - num2[i];
        if(ans[i] == -1 && i!=0){
            ans[i-1]--;
            ans[i] = 9;
        }
    }

    for (int i = 0; i < n; i++)
    {
        if (ans[i] != 0)
        {
            start = i;
            break;
        }

        if (i == n - 1)
        {
            cout << 0 << endl;
            return 0;
        }
    }

    if (ans[start] < 0 && n!=1)
    {
        if (ans[start] == -1)
        {
            sign = true;
        }
        ans[start]++;

        ans[n - 1] = 10 - ans[n - 1];

        for (int i = start + 1; i < n - 1; i++)
        {
            ans[i] = 9 - ans[i];
        }
    }
    

    for(int i=0;i<n;i++){
        if (ans[i] != 0)
        {
            start = i;
            break;
        }
    }

    if (sign == true)
    {
        ans[start] *= -1;
    }

    for (int i = start; i < n; i++)
    {
        cout << ans[i];
    }
    cout << endl;

    return 0;
}
