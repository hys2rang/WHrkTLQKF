/*
자연수n,m이 주어질 때, n부터m까지 존재하는 소수를 모두 출력하는 프로그램을 작성하여라. 
여기서 소수란, 약수가 1과 자기자신밖에 존재하지 않는 수를 말한다.

예제 입력
1 10
예제 출력
2 3 5 7 

예제 입력
13 30
예제 출력
13 17 19 23 29
*/
#include <stdio.h>

int main()
{
    int n,m;
    int i,j;
    int flag = 0;
    scanf("%d %d",&n,&m);
    for(i=n;i<=m;i++){
        for(j=2;j<i;j++){
            if(i%j==0){
                flag = 1;
                break;
            }
        }
        if(flag == 0 && i!=1){
            printf("%d ",i);
        }else{
            flag = 0;
        }
    }
    return 0;
}
