#include <iostream>
using namespace std;
void swap(int *a,int *b){
    int temp=*a;
    *a=*b;
    *b=temp;
}
void reverse(int ary[], int s, int e)
{
    int d = e - s;
    if(d%2==0){
        
    }
    for (int i = s, k = 0; i < (d / 2)-1; i++, k++)
    {
        swap(&ary[i],&ary[e-k]);
    }
}
void Rrotate(int ary[], int n, int d)
{
   reverse(ary,0,d);
   reverse(ary,d+1,n-1);
    reverse(ary,0,n-1);
}

void rotate(int ary[], int n, int t)
{
    for (int l = 1; l <= t; l++)
    {
        int a = ary[0];
        for (int i = 0; i < n - 1; i++)
        {
            ary[i] = ary[i + 1];
        }
        ary[n - 1] = a;
    }
}
int main()
{
    int ary[10] = {3, -5, 2, 6, 2, 6, -8, 9, 2, -1};
    reverse(ary,0,9);
    //Rrotate(ary,10,2);
    for (int l = 0; l < 10; l++)
    {
        cout << ary[l] << ' ';
    }
}