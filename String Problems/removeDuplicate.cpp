#include<iostream>
#include<string>
using namespace std;

int contains(string str,char srch){
    
    for(int i=0;str[i]!='\0';i++)
    {
        if(srch == str[i]){
            return 1;
        }
    }
    return -1;
}
string removeDup(string str){
    string res;
    res.push_back(str[0]);

    for(int i=1;i<str.length();i++){
        int s=contains(res,str[i]);
        if(s==-1)
        {
            res.push_back(str[i]);
        }
    }
    return res;
}

int main()
{
    string str="geeksforgeeks";
    cout<<removeDup(str);


}