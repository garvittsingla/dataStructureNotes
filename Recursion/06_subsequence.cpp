#include<bits/stdc++.h>

using namespace std;
void sub(string p,string up){
    if(up.length()==0){
        cout << p << endl;
        return;
    }
    char character = up[0];
    sub(p+character,up.substr(1,up.length()));
    sub(p,up.substr(1,up.length()));
}
int main(void){
    sub("","abc");
}