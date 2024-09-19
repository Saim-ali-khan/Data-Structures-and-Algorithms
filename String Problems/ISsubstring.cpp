#include <iostream>
using namespace std;

int IsSubstring(string str1, string str2)
{
    int match = 0;
    for (int i = 0; i < str1.length(); i++)
    {
        match = 0;
        if (str1[i] == str2[0])
        {
            for (int j = 0; j < str2.length(); j++)
            {
                if (str2[j] == str1[i + j])
                {
                    match++;
                }
            }
            if (match == str2.length())
            {
                return 1;
            }
        }
    }
    return 0;
}

int main()
{
    string str = "It is the best place .";
    string str2 = "place .";

    cout << IsSubstring(str, str2);
}
