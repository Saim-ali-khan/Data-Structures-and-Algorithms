#include <iostream>
#include <string>
using namespace std;

void smallestWord(string str)
{
    int count = 0;
    int lword = 100;
    int s = 0, e = 0;
    for (int i = 0; i <= str.length(); i++)
    {

        if (str[i] == ' ' || str[i] == '\0')
        {

            if (count < lword)
            {
                lword = count;
                e = i - 1;
                s = i - lword;
            }
            count = 0;
        }
        else
        {
            count++;
        }
    }
    for (int l = s; l <= e; l++)
    {
        cout << str[l];
    }
}

int main()
{
    string str("pakistan and in");
    smallestWord(str);
}