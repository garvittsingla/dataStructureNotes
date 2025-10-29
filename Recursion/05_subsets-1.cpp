#include<iostream>
#include<bits/stdc++.h>

using namespace std;

vector<vector<int>> result;
void helper(int index , vector<int> &ds , vector<int> &nums){
    //Base case to add in the result
    if(index >= nums.size()){
        result.push_back(ds);
        return;
    }
    //Multiple recursion calls
    ds.push_back(nums[index]);
    helper(index+1,ds,nums);
    ds.pop_back();
    helper(index+1,ds,nums);
}
int main(void){
    vector<int> nums = {3,1,2};
    vector<int> ds;
    helper(0,ds,nums);
    for(auto it:result){
        cout << "{";
        for(auto ele : it){
            cout << " " << ele << " ";
        }
        cout << "}" << endl;
    }
}