/*
문제
두 정수 n, k를 입력받아 k개의 1을 가진 n자리 이진 패턴을 출력하는 프로그램을 작성하세요. 

입력
두 정수 n,k가 입력으로 주어진다. ( 0< n <= 30, 0 <= k < 8 , n>=k )

출력
결과를 내림차순으로 출력한다. 

예제 입력
2 1
예제 출력
10
01

예제 입력
2 0
예제 출력
00

예제 입력
4 2
예제 출력
1100
1010
1001
0110
0101
0011
*/
#include <iostream>
using namespace std;

int n,k;
int arr[30]={0};
void ToBinary(int length,int one);

int main()
{
    cin>>n>>k;

    ToBinary(0,0);
    return 0;
}

void ToBinary(int length,int one)
{
    if(one>k) return;
    if(length==n){
        if(one==k){
            for(int i=0;i<n;i++){
                cout<<arr[i];
            }
            cout<<endl;
            return;
        }           
        return;
    }    

    arr[length] = 1;
    ToBinary(length+1,one+1);
    arr[length]=0;
    ToBinary(length+1,one);
}
