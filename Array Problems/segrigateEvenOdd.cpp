#include <iostream>
using namespace std;

void segregate(int ary[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (ary[i] % 2 != 0)
        {
            for (int j = i + 1; j < n; j++)
            {
                if (ary[j] % 2 == 0)
                {
                    int temp = ary[i];
                    ary[i] = ary[j];
                    ary[j] = temp;
                }
            }
        }
    }
}
void seg(int ary[],int n){
    int leftIndex=0;
    int rightIndex=n-1;

    while(leftIndex<rightIndex){

        while(ary[leftIndex]%2==0 && leftIndex<rightIndex)
        {
            leftIndex++;
        }
        while(ary[rightIndex]%2!=0 && leftIndex<rightIndex)
        {
            rightIndex--;
        }

        if(leftIndex<rightIndex){
            int temp = ary[rightIndex];
            ary[rightIndex] =ary[leftIndex] ;
            ary[leftIndex] = temp;
        }

    }
}

int main()
{
    int ary[10] = {3,7,1,2,4,7,8,4,3,99};
    seg(ary, 10);
    for (int l = 0; l < 10; l++)
    {
        cout << ary[l] << ' ';
    }
}