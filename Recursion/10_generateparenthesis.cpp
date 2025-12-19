#include<bits/stdc++.h>

using namespace std;

vector<string> ans;
void generate(int n,int open,int close,string ds){
    if(open == n && close == n){
        ans.push_back(ds);
        return;
    }

    if(open < n){
        generate(n,open+1,close,ds+"(");
    }

    if(close<open){
        generate(n,open,close+1,ds+")");
    }
}
int main(void){
    int n = 2;
    generate(n,0,0,"");
    for (auto& s : ans) {
        cout << s << endl;
    }
}

