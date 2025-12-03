#include <bits/stdc++.h>

using namespace std;
vector<vector<int>> result;

//Pick - Not pick method
void solve(vector<int> nums,vector<int> ds,int index){
    if(index>=nums.size()){
        result.push_back(ds);
        return;
    }

    //pick a element
    ds.push_back(nums[index]);
    solve(nums,ds,index+1);
    //remove the element
    ds.pop_back();
    solve(nums,ds,index+1);
}
//Loop approach
void solve2(vector<int> nums,vector<int> ds,int index){
    result.push_back(ds);

    for(int i = index ; i < nums.size() ; i++){
        ds.push_back(nums[i]);
        solve2(nums,ds,i+1);
        ds.pop_back();
    }
}
int main (){
    vector<int> arr  = {1,2,3};
    vector<int> ds;
    solve2(arr,ds,0);
    for(auto it:result){
        cout << "{ ";
        for(auto ele:it){
            cout << ele << " ";
        }
        cout << "}" << endl;
    }

}