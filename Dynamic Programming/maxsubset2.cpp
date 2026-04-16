#include "bits/stdc++.h"
#include <algorithm>


using namespace std;


int maxSubset(vector<int> &nums1,vector<int> &nums2){
    int n = nums1.size();
    vector<int> dp(n+1,0);
    dp[0] = 0; //nothing till now
    dp[1] = max(nums1[0],nums2[0]);
    for(int i = 2 ; i <= n ; i++){
        int take = max(nums1[i-1], nums2[i-1]);
        if(i > 1) take += dp[i-2];
        int nottake = dp[i-1];
        dp[i] = max(take,nottake);


    }
    return dp[n];

};
int main(){
    vector<int> nums1 = {2,3,4,-8,2};
    vector<int> nums2 = {-5,8,3,1,-4};

    cout << maxSubset(nums1, nums2) << endl;

}
