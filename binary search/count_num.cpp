/*
문제
n개의 숫자가 주어지고, q개의 질문이 주어진다. 각각의 질문은 n개의 숫자 중에서 특정 숫자가 몇개나 있는지를 묻는다. 
q개의 질문에 모두 답하는 프로그램을 작성하시오.

입력
첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 두 번째 줄에 n개의 숫자가 주어진다. 
세 번째 줄에 q개의 질문이 주어진다.  

출력
각 질문에 대하여 숫자의 개수를 한 줄에 하나씩 출력한다.  

예제 입력
10 4
1 3 4 3 2 3 1 2 5 10
1 3 9 10
예제 출력
2
3
0
1
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<int> arr;
int BinarySearch(int start, int end, int value);
int main()
{
    int n,tc;   

    cin>>n>>tc;
    arr.resize(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    sort(arr.begin(),arr.end());

    for(int i=0;i<tc;i++){
        int num;
        int cnt=0;
        cin>>num;
        int start = BinarySearch(0,n-1,num);

        for(int i=start-1;i>=0;i--){
            if(arr[i]<num) break;
            if(arr[i]==num){
                cnt++;
            }
        }
        for(int i=start;i<n;i++){
            if(arr[i]>num) break;
            if(arr[i]==num){
                cnt++;
            }
        }
        cout<<cnt<<endl;
    }

    return 0;
}

int BinarySearch(int start, int end, int value)
{
    if (start > end)
        return -1;
    else if (start == end)
    {
        if (arr[start] == value)
        {
            return start;
        }
        else
        {
            return -1;
        }
    }
    else
    {
        int mid = (start + end) / 2;
        if (arr[mid] == value)
            return mid;
        else if (arr[mid] < value)
        {
            BinarySearch(mid + 1, end, value);
        }
        else
        {
            BinarySearch(start, mid - 1, value);
        }
    }
}
