/*
문제
히스토그램이란, 아래 그림과 같이 직사각형이 배열되어 있는 것을 말한다. 각 직사각형의 가로 길이는 1로 모두 같고, 세로 길이는 다를 수 있다. 
예를 들어, 아래 그림은 높이가 2, 1, 4, 5, 1, 3, 3 인 직사각형으로 이루어진 히스토그램이다.

히스토그램이 주어질 때, 가장 큰 직사각형의 너비를 출력하는 프로그램을 작성하시오. 위의 예제에서는 최대 직사각형의 너비가 그림과 같이 8이다. 

입력
첫째 줄에 히스토그램을 이루는 직사각형의 개수 N이 주어진다. ( 1 ≤ N ≤ 100,000 ) 둘째 줄에는 각 직사각형의 높이가 주어진다.  

출력
최대 직사각형의 너비를 출력한다. 

예제 입력
7
2 1 4 5 1 3 3
예제 출력
8
*/
#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>

using namespace std;

int main()
{
    stack<int> s;
    int n;

    cin>>n;
    vector<int> arr(n,0);

    for(int i=0;i<n;i++){
        cin>>arr[i];
    }  
    
    int M = 0;

    for(int i=0;i<n;i++){        
        int left = i;
        while(!s.empty() && arr[s.top()]>arr[i]){
            int h=arr[s.top()];
            s.pop();
            int w = i;

            if(!s.empty()){
                w = i-s.top()-1;
            }

            M=max(M,h*w);
        }
        s.push(i);
    }

    while(!s.empty()){
        int h = arr[s.top()];
        s.pop();
        int w = n;

        if(!s.empty()){
            w=n-s.top()-1;
        }
        M=max(M,h*w);
    }

    cout<<M;

    return 0;
}
