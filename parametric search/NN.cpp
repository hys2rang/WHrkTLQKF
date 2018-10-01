/*
문제
알랩이는 구구단표처럼 NN단표를 만들었다고 한다.

NN단표는 2차원 배열의 모양으로 곱셈 1단부터 N단까지의 값들을 적어놓은 형태이다.

NN단표의 배열을 A라고 했을 때, 배열의 들어가는 수 A[i][j]=i*j이다.(즉, 4행 7열에는 28, 7행 5열에는 35가 들어가 있다.)

알랩이는 N단까지 나온 숫자들 중에서 K번째로 작은 수를 찾고 싶어한다.

이때, 중복되는 여러 수들을 고려한다. 즉 N*N개의 모든 수들 중에서 K번째 수를 구하는 것이다.  

입력
첫째 줄에 배열의 크기 N이 주어진다. N은 100,000보다 작거나 같은 자연수이다. 둘째 줄에 K가 주어진다.
K는 N*N보다 작거나 같고, 10,000,000,000보다 작거나 같은 자연수이다.  

출력
K번째 원소를 출력한다. 

예제 입력
3
7
예제 출력
6
 
*/
#include <iostream>

using namespace std;

long long getmin(long long a, long long b);
int main()
{
    int n;
    long long k;

    long long left, right;


    cin >> n >> k;

    left = 1;
    right = n * n;
    long long mid;
    long long res;

    while (left <= right)
    {

        long long order = 0; //NN단표상에서 mid가 몇 번째인지를 찾아낸 값

        mid = (left + right) / 2;

        for (int i = 1; i <= n; i++)
        {
            order+=getmin(mid/i,n);
        }
        if (order < k)
        {
            left = mid + 1;
        }
        else
        {
            res = mid;
            right = mid - 1;
        }
    }

    cout<<res<<endl;

    return 0;
}
long long getmin(long long a, long long b)
{
    if(a>=b){
        return b;
    }else{
        return a;
    }
}
