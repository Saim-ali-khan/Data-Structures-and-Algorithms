#include <iostream>
using namespace std;

int comEl(int ary1[], int ary2[], int n1, int n2, int no)
{
    int comno = 0;

    for (int i = 0; i < n1; i++)
    {
        for (int j = 0; j < n2; j++)
        {
            if (ary1[i] == ary2[j])
            {
                comno++;
                if (comno == no)
                {
                    return ary1[i];
                }
            }
        }
    }
    return -1;
}

int indexOf(int ary[], int n, int f)
{
    int i = 0;
    while (i < n)
    {
        if (f == ary[i])
        {
            return i;
        }
        i++;
    }
}

int arsum(int ary[], int s, int e)
{
    int sum = 0;
    for (int i = s; i <= e; i++)
    {
        sum += ary[i];
    }
    return sum;
}

int maxPath(int ary1[], int ary2[], int n1, int n2)
{
    int com, com1, com2, total = 0, ars1, ars2;
    int s1 = 0, s2 = 0;
    for (int i = 1; i < n2; i++)
    {
        com = comEl(ary1, ary2, n1, n2, i);
        if (com != -1)
        {
            com1 = indexOf(ary1, n1, com);
            com2 = indexOf(ary2, n2, com);
            
            ars1 = arsum(ary1, s1, com1);
            ars2 = arsum(ary2, s2, com2);
            s1=com1+1;
            s2=com2+1;
            if (ars1 >= ars2)
            {
                total += ars1;
            }
            else
            {
                total += ars2;
            }
        }
        else
        {
            ars1 = arsum(ary1, s1, n1 - 1);
            ars2 = arsum(ary2, s2, n2 - 1);
            if (ars1 >= ars2)
            {
                total += ars1;
                return total;
            }
            else
            {
                total += ars2;
                return total;
            }
            
        }
    }

    return total;
}

int main()
{
    int ary1[5] = {0, 2, 6, 7, 10};
    int ary2[4] = {1, 2, 7, 9};
    cout<<"running\n";
    cout << maxPath(ary1, ary2, 5, 4);

    return 0;
}