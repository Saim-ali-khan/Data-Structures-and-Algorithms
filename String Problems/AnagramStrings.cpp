#include<iostream>
#include<string>
using namespace std;

int contain(string str,char srch){

    for(int i=0;i<str.length();i++)
    {
        if(str[i]==srch){
            return 1;
        }

    }
    return 0;
}

int Anagram(string str1,string str2){
    for(int j=0;j<str1.length();j++)
    {
        int s=contain(str2,str1[j]);
        if(s==0){
            return 0;
        }
    }
    return 1;
}

int main()
{
    string str="tel";
    string str2="letl";

    cout<<Anagram(str,str2);
    
}