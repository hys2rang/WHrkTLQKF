/*
문제
N개의 자연수가 주어질 때, 퀵정렬을 이용하여 이를 정렬하는 프로그램을 작성하시오.

 

입력
첫 번째 줄에 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 두 번째 줄에 N개의 자연수가 주어진다.  

출력
퀵정렬을 이용하여 숫자를 오름차순으로 정렬한 결과를 출력한다.

 

예제 입력
10
5 9 2 8 3 7 4 6 1 10
예제 출력
1 2 3 4 5 6 7 8 9 10
예제 입력
5
2 3 1 2 1
예제 출력
1 1 2 2 3
 
*/
#include <stdio.h>
int getLeft(int arr[],int start, int end, int pivot, int result[]);
int getRight(int arr[],int start, int end, int pivot, int result[]);
void quickSort(int arr[],int start,int end);
int main()
{
    int n;
    int arr[100000];
    
    scanf("%d",&n);
    
    for(int i=0;i<n;i++)
        scanf("%d",&arr[i]);
        
    quickSort(arr,0,n-1);
    
    for(int i=0;i<n;i++){
        printf("%d ",arr[i]);
    }
    return 0;
}
void quickSort(int arr[],int start,int end)
{
    if(start>=end){
        return;
    }else{
        int pivot = arr[start];
        int left[100000],right[100000];
        
        int left_idx = getLeft(arr,start+1,end,pivot,left);
        int right_idx = getRight(arr,start+1,end,pivot,right);
        
        for(int i=0;i<left_idx;i++){
            arr[start+i] = left[i];
        }
        
        arr[start+left_idx] = pivot;
        
        for(int i=0;i<right_idx;i++){
            arr[left_idx+start+1+i] = right[i];
        }
        
        quickSort(arr,start,start+left_idx-1);
        quickSort(arr,start+left_idx+1,end);
    }
}
int getLeft(int arr[],int start, int end, int pivot, int result[])
{
    int idx=0;
    for(int i=start;i<=end;i++){
        if(arr[i]<=pivot){
            result[idx++] = arr[i];
        }
    }
    
    return idx;
}
int getRight(int arr[],int start, int end, int pivot, int result[])
{
    int idx=0;
    for(int i=start;i<=end;i++){
        if(arr[i]>pivot){
            result[idx++] = arr[i];
        }
    }
    
    return idx;
}
