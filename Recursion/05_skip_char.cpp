#include<bits/stdc++.h>

using namespace std;
string skipchar(string str,char ch){
    if(str.size()==0){
        return "";
    }

    char currentchar = str[0];
    if(currentchar==ch){
        return skipchar(str.substr(1, str.size()),ch);
    }else{
        return currentchar+skipchar(str.substr(1, str.size()),ch);
    }
}
int main(void){
    string str = "helloworld";
    string final = "";
    cout << skipchar(str,'l');
}