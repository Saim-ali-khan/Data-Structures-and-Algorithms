#include<iostream>
using namespace std;



// Elements of array which are greater than all the elements on the right side is called leader element.
void printLeaders(int ary[],int n){

    for(int i=0;i<n-1;i++)
    {
        int com=0;
        for(int j=i+1;j<n;j++)
        {
            if(ary[i]>ary[j]){
                com++;
            }
        }
        if(com==n-1-i){
            cout<<ary[i]<<" ";
        }
    }
}
int main(){

    int ary[10]={3,1,2,4,1,6,6,5,3,2};
    printLeaders(ary,10);

    return 0;
}