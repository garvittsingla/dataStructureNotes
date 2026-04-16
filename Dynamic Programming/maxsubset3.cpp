#include "bits/stdc++.h"
#include <algorithm>


using namespace std;


int maxSubset(vector<int> &nums1,vector<int> &nums2,vector<int> &nums3){
    int n = nums1.size();
    vector<int> dp(n+1,0);
    dp[0] = 0; //nothing till now
    dp[1] = max({nums1[0], nums2[0], nums3[0]});
    for(int i = 2 ; i <= n ; i++){

    }
    return dp[n];

};
int main(){
    vector<int> nums1 = {10, 40 ,70};
    vector<int> nums2 = {20, 50 ,80};
    vector<int> nums3 = {30 ,60 ,90};

    cout << maxSubset(nums1, nums2,nums3) << endl;

}
