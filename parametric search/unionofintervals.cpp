/*
문제
구간은 [s, e] 로 나타내고, 이 의미는 s, (s+1), (s+2), …, (e-1), e 와 같이 숫자를 나열한 것을 의미한다. 
예를 들어, [1, 4]는 1, 2, 3, 4로 숫자를 나열한 것을 의미한다. n개의 구간이 있고, 이 구간들의 숫자를 모두다 새로운 배열 S에 넣어 정렬을 한다. 
이 때 S[i] 의 값이 무엇인지 출력하는 프로그램을 작성하시오. 예를 들어, 3개의 구간 [1, 3], [2, 10], [1, 8] 이 있고, S[5]를 알고싶다고 하자. 
그러면 S = [1, 1, 2, 2, 2, 3, 3, 3, 4, 4, 5, 5, 6, 6, 7, 7, 8, 8, 9, 10] 이 되고, 따라서 S[5]는 3이 된다. 
배열의 인덱스는 0부터 시작한다는 것에 주의하자. 

입력
첫 번째 줄에 구간의 개수 n이 주어진다 ( 1 ≤ n ≤ 10,000 ) 두 번째 줄부터 각 구간을 나타내는 숫자 s, e가 주어진다. 
( 1 ≤ s ≤ e ≤ 1,000,000,000 ) 그 후, 마지막 줄에는 값을 알고 싶은 숫자의 위치 i가 주어진다. 
( 1 ≤ i ≤ 10,000,000,000,000 ) i번째 위치에는 항상 숫자가 존재한다고 가정한다.  

출력
S[i]를 출력한다.  

예제 입력
2
1 4
3 5
3
예제 출력
3
예제 입력
3
1 3
2 10
1 8
5
예제 출력
3
*/
#include <iostream>
#include <algorithm>

using namespace std;

int main()
{
    int buf[20000]={0};
    int n;
    long long k;
    long long res;
    int left, right;

    left = 1;
    right = 1;

    ///freopen("Sample.txt", "r", stdin);

    cin >> n;

    for (int i = 0; i <2*n; i=i+2)
    {
        cin >> buf[i]>>buf[i+1];
        left = min(left, buf[i]);
        right = max(right, buf[i+1]);
    }
    cin >> k;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        long long cnt = 0;

        for (int i = 0; i < 2 * n; i = i + 2)
        {
            if (buf[i] <= mid && buf[i+1]>=mid)
            {
                cnt += mid - buf[i];              
            }
            else if(buf[i+1]<mid)
            {
                cnt += buf[i + 1] - buf[i]+1;
            }
        }
        if(right == left || cnt == k){
            res = mid;
        }
        
        if (cnt > k)
        {            
            right=mid-1;
        }
        else
        {
            left = mid+1;
        }
    }

    cout << res;

    return 0;
}
