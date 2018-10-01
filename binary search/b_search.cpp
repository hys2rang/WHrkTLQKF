/*
문제
n개의 오름차순으로 정렬된 숫자가 주어지고, 그 후 q개의 질문이 주어진다. 
각각의 질문은 특정 숫자가 n개의 숫자 내에 존재하는지를 판별하는 것이다. 모든 q개의 질문에 대하여 답을 하는 프로그램을 작성하시오.  

입력
첫 번째 줄에 숫자의 개수 n, 그리고 질문의 개수 q가 주어진다 ( 1 ≤ n ≤ 100,000, 1 ≤ q ≤ 100,000) 이는 오름차순으로 정렬되어 주어진다. 
두 번째 줄에 n개의 숫자가 주어진다. 세 번째 줄에 q개의 질문이 주어진다.  

출력
각 질문에 대하여 숫자가 존재하면 YES, 아니면 NO를 한 줄에 하나씩 출력한다.


예제 입력
10 4
1 2 4 8 10 11 12 14 15 19
4 5 8 17
예제 출력
YES
NO
YES
NO
*/
#include <iostream>
#include <vector>

using namespace std;

vector<int> arr;

int BinarySearch(int start,int end,int value);
int main()
{
    int n;
    int tc,num;

    cin>>n>>tc;

    arr.resize(n,0);
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    for(int i=0;i<tc;i++){
        cin>>num;
        if(BinarySearch(0,n-1,num)!=-1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
}
int BinarySearch(int start,int end,int value)
{
    if(start>end) return -1;
    else if(start == end){
        if(arr[start] == value){
            return start;
        }else{
            return -1;
        }
    }else{
        int mid = (start+end)/2;
        if(arr[mid] == value) return mid;
        else if(arr[mid]<value){
            BinarySearch(mid+1,end,value);
        }else{
            BinarySearch(start,mid-1,value);
        }
    }
}
