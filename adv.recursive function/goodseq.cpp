/*
문제
숫자 1, 2, 3으로만 이루어지는 수열이 있다. 임의의 길이의 인접한 두 개의 부분 수열이 동일한 것 이 있으면, 그 수열을 나쁜 수열이라고 부른다. 
그렇지 않은 수열은 좋은 수열이다.
다음은 나쁜 수열의 예이다.

3__3__

3__2121__323

__123123__213

다음은 좋은 수열의 예이다.

2

32

32123

1232123

길이가 N인 좋은 수열들을 N자리의 정수로 보아 그중 가장 작은 수를 나타내는 수열을 구하는 프로그램 을 작성하라. 
예를 들면, 1213121과 2123212는 모두 좋은 수열이지만 그 중에서 작은 수를 나타내는 수 열 1213121이다. 

입력
입력은 숫자 N하나로 이루어진다. N은 1 이상 80 이하이다. 

출력
첫 번째 줄에 1, 2, 3으로만 이루어져 있는 길이가 N인 좋은 수열들 중에서 가장 작은 수를 나타내 는 수열만 출력한다. 
수열을 이루는 1, 2, 3들 사이에는 빈칸을 두지 않는다. 

예제 입력
7
예제 출력
1213121
*/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int nn;
vector<int> arr;
//int arr[20] = {0};
bool check(int n);
void isgood(int depth);
bool printed = false;
int main()
{
    //freopen("Sample.txt", "r", stdin);

    cin >> nn;
    arr.resize(nn);

    isgood(0);

    return 0;
}
bool check(int n)
{
    if (n == 0)
    {
        return true;
    }

    if (arr[n - 1] == arr[n])
    {
        return false;
    }
    int cnt = (n/2)+1;
        while(cnt>=2){
            vector<int> buf(cnt);
            //int buf[20]={0};
            for(int i=0,j=n;i<cnt;i++,j--){
                buf[i] = arr[j];
            }
            int c =0;
            int k=0;
            for(int i=n-cnt,j=0;j<cnt;i--,j++){
                if(buf[j]==arr[i]){
                    c++;
                }    
                if(c == cnt){
                    return false;
                }  
            }
            
            cnt--;
            
        }
        return true;        

}
void isgood(int depth)
{
    if(printed) return;
    if (depth == nn)
    {
        if (!printed)
        {
            for (int i = 0; i < nn; i++)
            {
                cout << arr[i];
            }
            printed = true;
        }
        return;
    }
    else
    {
        for (int i = 1; i <= 3; i++)
        {
            arr[depth] = i;
            if (check(depth))
            {
                isgood(depth + 1);
            }
        }
    }
}
