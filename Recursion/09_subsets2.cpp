#include<bits/stdc++.h>

using namespace std;
vector<vector<int>> result;
void picknotpick(vector<int> nums,int index,vector<int> ds){
    if(index >= nums.size() ){
        result.push_back(ds);
        return;
    }
    //picking the elemenet 
    ds.push_back(nums[index]);
    picknotpick(nums,index+1,ds);

    ds.pop_back();
    int i = index+1;
    while(i < nums.size() && nums[i] == nums[i-1]) i++;

    picknotpick(nums,i,ds);
}
void loopmethod(vector<int> nums,int index, vector<int> ds){
    result.push_back(ds);

    for(int i = index ; i < nums.size() ; i++){
        if(i > index && nums[i] == nums[i-1]) continue;
        ds.push_back(nums[i]);
        loopmethod(nums,i+1,ds);
        ds.pop_back();
    }
}
int main(){
    vector<int> nums = {1,2,2};
    vector<int> ds;
    // picknotpick(nums,0,ds);
    loopmethod(nums,0,ds);
    for(auto it : result){
        cout << " { ";
        for(auto ele:it){
            cout << ele << " " ;
        }
        cout << " } " << endl;
    }
}