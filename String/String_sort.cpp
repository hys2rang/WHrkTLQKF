/*
문제
n개의 문자열이 주어질 때, 이 문자열을 사전순으로 빠른 순서대로 정렬하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 문자열의 개수 n이 주어진다 ( 1 ≤ n ≤ 100 ) 그 후 n개의 줄에 대하여 정렬하고자 하는 문자열이 주어진다 ( 1 ≤ 문자열의 길이 ≤ 100 )  

출력
문자열을 사전순으로 빠른 순서대로 정렬한 결과를 출력한다.

 

예제 입력
9
acid
apple
banana
acquire
cat
crop
crab
power
cat
예제 출력
acid
acquire
apple
banana
cat
cat
crab
crop
power
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    int n;
    char a[100][100];
    char buf[100];
    
    scanf("%d\n",&n);

    for(int i=0;i<n;i++){
        scanf("%s\n",a[i]);
    }

    for(int i=0;i<n-1;i++){
        for(int j=i+1;j<n;j++){
            if(strcmp(a[i],a[j])>0){
                strcpy(buf,a[i]);
                strcpy(a[i],a[j]);
                strcpy(a[j],buf);
            }
        }
    }

    for(int i=0;i<n;i++){
        cout<<a[i]<<endl;
    }
    
    return 0;
}
