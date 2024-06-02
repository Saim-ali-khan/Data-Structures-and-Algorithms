#include <iostream>
using namespace std;

int findN(int ary[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (ary[i] < 0)
        {
            return i;
        }
    }
    return -1;
}
int findP(int ary[], int s, int e)
{
    for (int i = s; i <= e; i++)
    {
        if (ary[i] >= 0)
        {
            return i;
        }
    }
    return -1;
}
void alterNP(int ary[], int n)
{

    for (int i = 0; i < n; i++)
    {
        if (i % 2 == 0 && !(ary[i] < 0))
        {
            int ind = findN(ary, i + 1, n - 1);
            if (ind != -1)
            {
                int temp = ary[i];
                ary[i] = ary[ind];
                ary[ind] = temp;
            }
        }
        else if (i % 2 != 0 && !(ary[i] > 0))
        {
            int ind = findP(ary, i + 1, n - 1);
            if (ind != -1)
            {
                int temp = ary[i];
                ary[i] = ary[ind];
                ary[ind] = temp;
            }
        }
    }
}

int main()
{
    int ary[10] = {3, -5, 2, 6, 2, 6, -8, 9, 2, -1};
    alterNP(ary, 10);
    for (int l = 0; l < 10; l++)
    {
        cout << ary[l] << ' ';
    }
    return 0;
}