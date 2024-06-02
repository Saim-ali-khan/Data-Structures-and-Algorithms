#include <iostream>
using namespace std;

int max(int ary[], int n)
{
    int max = ary[0];
    for (int i = 1; i < n; i++)
    {
        if (max < ary[i])
        {
            max = ary[i];
        }
    }
    return max;
}
int kthmax(int ary[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        int comp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (ary[i] > ary[j])
                {
                    comp++;
                }
            }
        }
        if (comp == (n - k))
        {
            return ary[i];
        }
    }
    return -1;
}
int min(int ary[], int n)
{
    int min = ary[0];
    for (int i = 1; i < n; i++)
    {
        if (min > ary[i])
        {
            min = ary[i];
        }
    }
    return min;
}
int kthmin(int ary[], int n, int k)
{
    for (int i = 0; i < n; i++)
    {
        int comp = 0;
        for (int j = 0; j < n; j++)
        {
            if (i != j)
            {
                if (ary[i] < ary[j])
                {
                    comp++;
                }
            }
        }
        if (comp == (n - k))
        {
            return ary[i];
        }
    }
    return -1;
}

int main()
{
    int ary[10] = {3, 4, 7, 2, 6, 8, 1, 99, 21, 5};
    cout << "Max number: " << max(ary, 10) << endl;
    cout << 3 << " Max number: " << kthmax(ary, 10, 3) << endl;
    cout << "Min number: " << min(ary, 10) << endl;
    cout << 3 << " Min number: " << kthmin(ary, 10, 3) << endl;
}