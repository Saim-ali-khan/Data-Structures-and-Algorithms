#include<iostream>
using namespace std;
int jumps(int ary[],int n){
    int i=0,jump=0;
    while(i<n){
        i+=ary[i];
        jump++;
    }
    return jump;
}
int main()
{
    int ary[6]={3,5,2,2,1,2};
    cout<<"Jumps : "<<jumps(ary,6);
}