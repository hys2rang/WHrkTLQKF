/*
예제 입력
3
예제 출력
  *
 ***
*****
*/
#include <stdio.h>

int main()
{
    int i,j,k,n;
    
    scanf("%d",&n);
    
    for(i=0;i<n;i++){
        for(j=0;j<n-i-1;j++){
            printf(" ");
        }
        for(k=0;k<2*i+1;k++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
