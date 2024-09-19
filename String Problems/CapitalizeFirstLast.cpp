#include <iostream>
using namespace std;

void changeCase(string str, int index)
{
}

void capitalizeFLW(string str)
{

    for (int i = 0; i < str.length(); i++)
    {
        if (str[i] != ' ')
        {
            for (int j = i; j <= str.length(); j++)
            {
                if (str[j] == ' ' || str[j]=='\0')
                {
                    if (!(str[i] >= 65 && str[i] <= 90))
                    {
                        str[i]=str[i]-32;
                    }
                    if (!(str[j-1] >= 65 && str[j-1] <= 90))
                    {
                        str[j-1]=str[j-1]-32;
                    }
                    i = j;
                    break;
                }
            }
        }
    }
    cout << str;
}

int main()
{
    string str = "hello we are   going   ";
    capitalizeFLW(str);
}