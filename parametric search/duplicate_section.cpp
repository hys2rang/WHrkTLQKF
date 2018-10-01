/*
문제
n개의 숫자가 주어지고, 이 중에서 r개의 연속된 숫자를 선택했을 때, 이 연속 부분 내에는 숫자가 중복되지 않기를 원한다. 
예를 들어, 다음과 같이 10개의 숫자에서 3개의 연속된 숫자를 선택할 수 있다.

이렇게 선택을 하면, 선택된 숫자들 사이에서는 중복이 존재하지 않는다. r의 최댓값을 구하는 프로그램을 작성하시오. 
위의 경우, (4, 2, 1, 3)을 선택하면 되므로 r의 최댓값은 4이다. r이 5 이상이 될 경우, 중복 없이 연속 부분을 선택하는 것이 불가능하다. 

입력
첫째 줄에는 숫자의 개수 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 둘째 줄에 n개의 숫자가 주어진다. 각 숫자는 항상 1보다 크거나 같고, n보다 작거나 같다.  

출력
r의 최댓값을 출력한다. 

예제 입력
10
1 3 1 2 4 2 1 3 2 1
예제 출력
4

예제 입력
7
7 1 4 2 5 3 6
예제 출력
7
*/
#include <iostream>

using namespace std;

int main()
{
    int range = 0;
    int n;
    
    int arr[100000];

    cin >> n;

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    int left = 0;
    int right = n;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        bool dup = false;
        int cnt=0;
        int buf[100000]={0};

        for (int i = 0; i < mid; i++)
        {
            if (buf[arr[i]] == 0)
                cnt++;
            buf[arr[i]]++;
        }

        for (int i = mid-1; i < n; i++)
        {
            if(cnt<mid){
                if(buf[arr[i-mid+1]]==1){
                    cnt--;
                }
                buf[arr[i-mid+1]]--;

                if(buf[arr[i+1]]==0) cnt++;
                buf[arr[i+1]]++;
            }else{
                dup = true;
                break;
            }
        }

        if (dup)
        {
            range = max(mid, range);
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
        
    }

    cout << range;

    return 0;
}
