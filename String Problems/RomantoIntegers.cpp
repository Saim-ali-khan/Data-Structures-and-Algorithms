#include<iostream>
#include<string>
using namespace std;

int valueOf(char ch){
    if(ch == 'I'){
        return 1;
    }
    else if(ch == 'V'){
        return 5;

    }
    else if(ch == 'X'){
        return 10;
    }
    else if(ch == 'L'){
        return 50;
    }
    else if(ch == 'C'){
        return 100;
    }
    else if(ch == 'M'){
        return 1000;
    }
}


int Roman(string str){
    int result=0;
    for(int i=0;i<str.length();i++){
        if(valueOf(str[i]) < valueOf(str[i+1]) && i != str.length()-1 ){
            result += valueOf(str[i+1])-valueOf(str[i]); 
            i++;
        }
        else {
            result += valueOf(str[i]);
        }
    }
    return result;
}
int main()
{
    string str="MMMVII";

    cout<<Roman(str);

}