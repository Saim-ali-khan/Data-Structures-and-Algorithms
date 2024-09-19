#include<iostream>
using namespace std;


int palindrome(string str){
    int mid=(str.length()-1)/2;
    int res=0;
    for(int i=0;i<=mid;i++){

        if(str[i] == str[str.length()-1-i])
        {
            res++;
            continue;
        }
    }
    if(res==mid+1){
        return 1;
    }
    return 0;
}
int main()
{
    string str="200002";
    cout<<palindrome(str);
}