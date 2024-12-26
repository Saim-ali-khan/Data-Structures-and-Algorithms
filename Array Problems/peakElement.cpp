#include<iostream>
#include<conio.h>
using namespace std;

void printPeak(int ary[],int n){

    for(int i=0;i<n;i++){

        if(i==0){
            if(ary[i]>ary[i+1]){
                cout<<ary[i]<<" ";
                i++;
            }
        }
        else if(i==n-1)
        {
            if(ary[i]>ary[i-1]){
                cout<<ary[i]<<" ";                
            }
        }
        else{
            if(ary[i]>ary[i-1] && ary[i]>ary[i+1]){
                cout<<ary[i]<<" ";
                i++;
            }
        }
    }
}

int main()
{
    getch();
    int ary[10]={3,1,4,3,2,5,2,4,2,9};
    printPeak(ary,10);
    getch();
    return 0;
}