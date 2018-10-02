/*
문제
n과 m이 주어질 때, n^m을 구하는 프로그램을 작성하시오. 단, n^m의 값이 커질 수 있기 때문에, 정답을 10,007 으로 나눈 나머지를 출력한다. 

입력
첫 번째 줄에 숫자 n과 m이 주어진다. ( 1 ≤ n ≤ 100, 1 ≤ m ≤ 1,000,000,000,000,000,000 )  

출력
첫째 줄에 nm을 10,007 으로 나눈 나머지를 출력한다. 

예제 입력
3 4
예제 출력
81
*/
#include <iostream>
#include <algorithm>
#include <math.h>

using namespace std;

unsigned long long getpower(long a, long b);
long n,x;
int main()
{
    cin>>n>>x;
    
    int ans = getpower(n,x);

    cout<<ans;

    return 0;
}
unsigned long long getpower(long a, long b)
{
    if(b == 1){
        return a;
    }else{
        unsigned long long tmp = getpower(a,b/2);
        if(b%2 == 0){            
            return (tmp * tmp) %10007;
        }else{
            return (a*tmp * tmp) %10007;
        }
    }
}
