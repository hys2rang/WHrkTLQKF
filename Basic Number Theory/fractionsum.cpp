/*
문제
분자 분모가 모두 자연수인 두 분수의 합 또한 분자 분모가 자연수인 분수로 표현할 수 있다.

두 분수가 주어졌을 때, 그 합을 기약분수의 형태로 구하는 프로그램을 작성하시오.

기약분수란 더 이상 약분되지 않는 분수를 의미한다.  

입력
첫째 줄과 둘째 줄에, 각 분수의 분자와 분모를 뜻하는 두 개의 자연수가 순서대로 주어진다. 입력되는 네 자연수는 모두 30,000 이하이다. 

출력
첫째 줄에 구하고자 하는 기약분수의 분자와 분모를 뜻하는 두 개의 자연수를 공백으로 구분하여 순서대로 출력한다.

예제 입력
2 7
3 5
예제 출력
31 35 
*/
#include <iostream>
#include <vector>

using namespace std;

long getgcd(long a, long b);

int main()
{
    long mom1,mom2,son1,son2;
    long lcm;
    long sum=0;


    cin>>son1>>mom1>>son2>>mom2;

    if(mom1==0 || mom2 ==0){
        return 0;
    }

    lcm = mom1*mom2 / getgcd(mom1,mom2);    
    sum = son1*lcm/mom1+son2*lcm/mom2;

    cout<< sum/getgcd(sum,lcm)<<" "<<lcm/getgcd(sum,lcm)<<endl;

    return 0;
}

long getgcd(long a, long b)
{
    long c;
    while (b)
    {
        c = a % b;
        a = b;
        b = c;
    }
    return a;
}
