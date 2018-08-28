#include <stdio.h>

const int MAX = 100;
struct PriorityQueue{
    int data[MAX];
    int len = 1;
    void push(int x)
    {
        data[len++] = x;
        
        int idx = len-1;
        
        while(idx >1){
            if(data[idx] < data[idx/2]){
                int tmp = data[idx];
                data[idx] = data[idx/2];
                data[idx/2] = tmp;
            }
            else break;
            
            idx = idx/2;
        }
        
    }
    void pop()
    {
        data[1] = data[len-1];
        data[len-1] = 0;
        len--;
        
        int idx = 1;
        while(1){
            int pidx = -1;
            
            if(len<=idx*2){
                break;
            }
            else if(1<=idx*2 && idx*2 < len && len<=idx*2 +1){
                pidx = idx*2;
            }
            else{
                if(data[idx*2]<data[idx*2+1]){
                    pidx = idx*2;
                }else{
                    pidx = idx*2+1;
                }
            }
            
            if(data[idx]>data[pidx]){
                int tmp = data[idx];
                data[idx] = data[pidx];
                data[pidx] = tmp;
                
                idx = pidx;
            }else{
                break;
            }
            
        }
    }
    int top()
    {
        return data[1];
    }
};
int main()
{
    return 0;
}
