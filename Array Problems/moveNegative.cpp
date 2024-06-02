#include<iostream>
using namespace std;
void movNeg(int ary[],int n){

    for(int i=0;i<n;i++){

        if(ary[i]>=0){
            for(int j=i+1;j<n;j++)
            {
                if(ary[j]<0){
                    int temp=ary[j];
                    ary[j]=ary[i];
                    ary[i]=temp;
                }
            }
        }
    }
}

int main()
{
    int ary[10]={3,-5,2,6,2,6,-8,9,2,-1};
    movNeg(ary,10);
    for(int l=0;l<10;l++){
        cout<<ary[l]<<' ';
    }
    
}