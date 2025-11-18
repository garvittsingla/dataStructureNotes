#include<bits/stdc++.h>

using namespace std;
vector<int> insert(vector<int> &arr,int temp){
    if(arr.size() == 0 || arr.back() <= temp){
        arr.push_back(temp);
        return arr;
    }

    int value = arr.back();
    arr.pop_back();
    arr = insert(arr,temp);
    arr.push_back(value);
    return arr;
}
vector<int> mysort(vector<int> &arr){
    if(arr.size() == 0){
        return arr;
    }
    int last = arr.back();
    arr.pop_back();
    arr = mysort(arr);
    arr = insert(arr,last);
    return arr;
}
int main(void){
    vector<int> arr = {5,4,3,2,1};
    mysort(arr);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}