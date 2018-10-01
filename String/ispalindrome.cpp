/*
문제
문자열이 주어질 때, 이것이 팰린드롬인지 조사하는 프로그램을 작성하시오. 팰린드롬이란, 앞으로 읽을 때와 뒤로 읽을 때의 결과가 같은 문자열을 말한다.  

입력
첫 번째 줄에 문자열이 주어진다. ( 1 ≤ 문자열의 길이 ≤ 1,000 )  

출력
입력된 문자열이 팰린드롬이면 YES, 아니면 NO를 출력한다. 

예제 입력
abcba
예제 출력
YES 

예제 입력
abcbd
예제 출력
NO
*/
#include <iostream>
#include <string.h>

using namespace std;

int main()
{
    char a[1000];
    bool flag = true;

    fgets(a,1000,stdin);

    for(int i=0;i<strlen(a);i++){
        if(a[i] != a[strlen(a)-1-i]){
            flag = false;
            break;
        }
    }

    if(flag){
        cout<<"YES"<<endl;
    }else{
        cout<<"NO"<<endl;
    }

}
