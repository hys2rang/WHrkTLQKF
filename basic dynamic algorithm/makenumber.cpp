/*
문제
숫자 1, 2, 3을 이용하여 숫자 N을 만드는 경우의 수를 출력하는 프로그램을 작성하시오. 
예를 들어, N이 4일 경우에는 다음의 7가지 경우가 존재한다. 단, 경우의 수가 매우 많을 수 있으므로, 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.

1+1+1+1
1+1+2
1+2+1
2+1+1
2+2
1+3
3+1 

입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 )  

출력
1, 2, 3을 이용하여 N을 만들 수 있는 경우의 수를 1,000,007 로 나눈 나머지를 출력한다.  

예제 입력
4
예제 출력
7 

예제 입력
200
예제 출력
290816
*/
#include <cstdio>

using namespace std;
const int MAX = 100000;
int Table[MAX];
int n,m;
int main()
{
    scanf("%d",&n);
    
    Table[1] = 1;
    int sum=0;
    for(int i=2;i<=3;i++){
        sum+=Table[i-1];
        Table[i] = sum+1;
    }
    
    for(int i = 4;i<=n;i++){
        for(int j=i-3;j<=i-1;j++){
            Table[i]+=Table[j];
            Table[i] = Table[i]%1000007;
        }
    }
    
    printf("%d\n",Table[n]);
    return 0;
}
