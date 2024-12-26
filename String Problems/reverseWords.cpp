#include<iostream>
#include<string>
using namespace std;

void reverseWords(string str){
    int last=str.length();
    for(int i=str.length()-1;i>=0;i--)
    {
        if(str[i]== ' '){
            cout<<" ";
            for(int j=i+1;j<last ;j++){
                cout<<str[j];
            }
            last=i;
        }
        else if(i==0){
            cout<<" ";
            for(int j=0;str[j]!= ' ';j++){
                cout<<str[j];
            }
            break;
        }
    }
}

int main()
{
    string str("   i am bad boy of a Big City            ");
    reverseWords(str);
}