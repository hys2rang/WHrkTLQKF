#include <stdio.h>

const int MAX = 100;
struct priorityQueue{
    int data[MAX];
    int len=0;
    void push(int x)
    {
        data[len++] = x;
        
    }
    void pop()
    {
        int myMax = -1, myMaxidx = -1;
        for(int i=0;i<len;i++){
            if(data[i]>myMax){
                myMax = data[i];
                myMaxidx = i;
            }
        }
        for(int i=myMaxidx;i<len;i++){
            data[i] = data[i+1];
        }
        len--;
    }
    int top()
    {
        int myMax = -1;
        
        for(int i=0;i<len;i++){
            if(data[i]>myMax){
                myMax = data[i];
            }
        }
        return myMax;
    }
};

int main()
{
    priorityQueue myPQ;
    
    myPQ.push(1);
    myPQ.push(4);
    myPQ.pop();
    
    printf("%d\n",myPQ.top());
    return 0;
}
