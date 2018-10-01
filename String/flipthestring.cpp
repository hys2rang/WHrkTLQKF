/*
문제
문자열이 주어질 때, 이를 뒤집어서 출력하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )  

출력
문자열을 뒤집은 결과를 출력한다.

 

예제 입력
Hello World!
예제 출력
!dlroW olleH
 
*/
#include <iostream>
#include <string.h>

using namespace std;
int main()
{
    char buf[1000];

    fgets(buf,1000,stdin);

    for(int i=strlen(buf)-1;i>=0;i--){
        cout<<buf[i];
    }

    return 0;
}
