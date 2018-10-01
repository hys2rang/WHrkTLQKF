/*
문제
서로 다른 n개의 원소들 중에서 r개만을 뽑아 일렬로 나열하는 것을 순열이라 한다. 
예를 들어, 3개의 원소 a, b, c 중에서 2개만을 뽑아 나열하면 ab, ac, ba, bc, ca, cb 의 6가지 경우가 있다. 
n과 r이 주어질 때, n개의 소문자 중에서 r개만을 뽑아 나열하는 모든 경우를 출력하는 프로그램을 작성하시오. 
단, a부터 시작하여 연속으로 n개의 알파벳을 갖고 있다고 하자.  

입력
첫 번째 줄에 n과 r이 주어진다. ( 1 ≤ n ≤ 26, 1 ≤ r ≤ n )  

출력
각 줄에 n개의 소문자 중에서 r개만을 뽑아 나열하는 경우를 사전순으로 나열한 결과를 출력한다. 

예제 입력
4 2
예제 출력
ab
ac
ad
ba
bc
bd
ca
cb
cd
da
db
dc
*/
#include <iostream>
#include <vector>

using namespace std;

void permutation(int cur, int depth); // 현재 높이, 목표 높이
void swap(int a, int b);
vector<char> alpha;
vector<bool> visited;
vector<int> order;
int n;

int main()
{
    int r;

    cin>>n>>r; //원소의 개수, 높이
    alpha.resize(n);
    visited.resize(n,false);
    order.resize(n);

    alpha[0] = 'a';

    for(int i=1;i<n;i++){
        alpha[i] = alpha[i-1]+1;
    }

    permutation(0,r);

    return 0;
}
void permutation(int cur, int depth)
{
    if(cur==depth){
        for(int i=0;i<depth;i++){
            for(int j=0;j<n;j++){
                if(visited[j] && order[j] == i){
                    cout<<alpha[j];
                    break;
                }
            }
        }
        cout<<endl;
        return;
    }else{
        for(int i=0;i<n;i++){
            if(!visited[i]){
                visited[i] = true;
                order[i] = cur;
                permutation(cur+1,depth);
                visited[i] = false;
            }
        }
    }
}
