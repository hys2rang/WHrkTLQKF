/*
이전다음
문제
서로 다른 n개의 정수가 주어질 때, 이를 합병정렬을 이용하여 오름차순으로 정렬하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 n이 주어진다. ( 1 ≤ n ≤ 100,000 ) 두번째 줄에 n개의 정수가 주어진다.  

출력
첫 번째 줄에 n개의 숫자를 합병정렬을 이용하여 오름차순으로 정렬한 결과를 출력한다.

 

예제 입력
10
2 5 3 4 8 7 -1 9 10 2
예제 출력
-1 2 2 3 4 5 7 8 9 10 
*/
#include <iostream>
#include <vector>

using namespace std;
int arr[100000];
int tmp[100000];
int n;
void merging(int s1,int e1,int s2,int e2);
void mergeSort(int start,int end);

int main()
{
    cin>>n;

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    mergeSort(0,n-1);

    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}

void mergeSort(int start,int end)
{
    if(start>=end){
        return;
    }else{
        int mid;
        mid = (start+end)/2;
        mergeSort(start,mid);
        mergeSort(mid+1,end);
        merging(start,mid,mid+1,end);
    }
}
void merging(int s1,int e1,int s2,int e2)
{
    int p,q;
    
    int tmp_idx =0;

    p = s1;
    q = s2;

    while(p<=e1 && q<=e2){
        if(arr[p]<=arr[q]){
            tmp[tmp_idx++] = arr[p++];
        }else{
            tmp[tmp_idx++] = arr[q++];
        }
    }
    if(p>e1){
        for(int i=q;i<=e2;i++){
            tmp[tmp_idx++] = arr[i];
        }
    }else{
        for(int i=p;i<=e1;i++){
            tmp[tmp_idx++] = arr[i];
        }
    }

    for(int i=s1;i<=e2;i++){
        arr[i] = tmp[i-s1];
    }

    return;
}
