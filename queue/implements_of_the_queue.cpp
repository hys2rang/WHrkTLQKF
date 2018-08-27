/*
문제
이 문제에서는 큐를 구현한다. 큐는 다음 세 개의 연산을 지원한다. 
Push X : 큐에 정수 X를 push한다. 만약 rear 포인터가 더 이상 뒤로 갈 수 없다면, “Overflow”를 출력한다. 
Pop : 큐에서 정수 하나를 pop한다. 만약 front 포인터가 더 이상 뒤로 갈 수 없다면, “Underflow”를 출력한다. 
Front : 큐의 front에 있는 정수를 출력한다. 만약 큐가 비어있다면 “NULL”을 출력한다. 
크기가 n인 큐에 m개의 연산을 하는 프로그램을 작성하시오. 입력의 편의를 위해서 Push는 “1”, Pop은 “2”, Top은 “3”으로 표현한다. 
다음은 크기 4인 큐에 10개의 연산이 입력으로 주어졌을 때의 입력과 출력의 예이다. 
참고로, 다음 예제는 선형 큐의 대표적인 나쁜 예이다. 다음 예제때문에 선형 큐는 쓰이지 않는다.

입력
첫째 줄에 큐의 크기 n, 연산의 개수 m이 주어진다. ( 1 n 100, 1 m 1,000 ) 두 번째 줄부터 연산이 주어진다. 
1은 Push, 2는 Pop, 3은 Front 연산을 의미한다.  

출력
연산의 결과를 출력한다. 

예제 입력
4 15
1 1
1 2
1 3
3
2
2
3
1 4
1 5
3
2
2
1 6
2
3
예제 출력
1
3
Overflow
3
Overflow
Underflow
NULL
*/
#include <iostream>
#include <vector>

using namespace std;

class Queue{
    vector<int> q;
    int f,r;

    public:
    Queue(int x){
        q.resize(x,0);
        f=r=0;
    }
    void push(int x)
    {
        if(r>=q.size()){
            cout<<"Overflow"<<endl;
        }else{
            q[r++]=x;
        }
    }
    void pop()
    {
        if(r-f<=0){
            cout<<"Underflow"<<endl;
        }else{
            q[f++] = 0;
        }
    }
    int front()
    {
        if(r-f<=0){
            return -1;
        }else{
            return q[f];
        }
    }

};
int main()
{
    int n,m;

    cin>>n>>m;

    Queue q(n);

    for(int i=0;i<m;i++){
        int x;
        cin>>x;
        switch(x){
            case 1:
            int y;
            cin>>y;
            q.push(y);
            break;
            case 2:
            q.pop();
            break;
            case 3:
            if(q.front()==-1){
                cout<<"NULL"<<endl;
            }else{
                cout<<q.front()<<endl;
            }
            break;
        }
    }

    return 0;
}