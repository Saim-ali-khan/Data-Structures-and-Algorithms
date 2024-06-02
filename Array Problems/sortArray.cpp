#include <iostream>
using namespace std;

int minI(int arr[], int s, int e)
{
    int minn = s;
    int small = arr[s];
    for (int i = s; i <= e; i++)
    {
        if (small > arr[i])
        {
            small = arr[i];
            minn = i;
        }
    }
    return minn;
}

void sort(int ary[], int n)
{

    for (int i = 0; i < n - 1; i++)
    {
        int mi = minI(ary, i, n - 1);
        int temp = ary[i];
        ary[i] = ary[mi];
        ary[mi] = temp;
    }
}

int main()
{
    int ary[10] = {3, -5, 2, 6, 2, 6, -8, 9, 2, -1};
    sort(ary, 10);
    for (int l = 0; l < 10; l++)
    {
        cout << ary[l] << ' ';
    }
    return 0;
}