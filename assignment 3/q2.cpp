#include<iostream>
#include<stack>
using namespace std;
int main(){
    string str="DataStructure";
    stack<char>sc;
    string s=" ";    //empty string


     for(int i=0;i<str.length();i++){       //insert each character into this stack
             sc.push(str[i]);
     }

    while(!sc.empty()){
         s+=sc.top();
         sc.pop();
    }

    cout<<"Reversed string: "<< s;
return 0;
}