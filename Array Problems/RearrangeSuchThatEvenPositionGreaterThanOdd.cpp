#include<iostream>
using namespace std;

void ArrangeEvenP(int ary[],int n){
    for(int i=1;i<n;i++)
    {
        if(i%2==0)
        {
            if(!(ary[i]>=ary[i-1]))
            {
                int temp = ary[i];
                ary[i] = ary[i-1];
                ary[i-1]= temp;
            }
        }
        else{
            if(!(ary[i]<=ary[i-1])){
                int temp = ary[i];
                ary[i] = ary[i-1];
                ary[i-1]= temp;
            }
        }
    }
}

int main()
{
    int ary[4]={1,2,2,1};
    ArrangeEvenP(ary,4);
    for(int l=0;l<4;l++){
        cout<<ary[l]<<' ';
    }
    
}