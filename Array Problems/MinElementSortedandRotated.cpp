#include <iostream>
using namespace std;
int minEl(int ary[], int n)
{
    if (ary[0] > ary[n - 1])
    {
        for (int i = 1; i < n; i++)
        {
            if (!(ary[i] >= ary[i - 1]))
            {

                return ary[i];
            }
        }
        return ary[0];
    }
    else{

        return ary[0];
    }
}
int main()
{
    int ary[5] = {2,3,4,5,6};
    cout << "Minimum Element in a Rotated and sorted : " << minEl(ary, 5);
}