#include "bits/stdc++.h"
#include <algorithm>


using namespace std;


int maxSubsetMemo(vector<int> &nums1,vector<int> &nums2,vector<int> &nums3,int day,int lastdone){
    if(day == nums1.size()-1){
        if(lastdone == 1){
            return nums2[day];
        }
        else if(lastdone == 2){
            return nums3[day];
        }
        else{
            return nums1[day];
        }
    };
    int ans = 0;
    for(int i = 1; i <= 3 ; i++){
        if(i == lastdone) continue;
        if(i == 1){
            ans = max(ans,nums1[day] + maxSubsetMemo(nums1,nums2,nums3,day+1,i));
        }
        else if(i == 2){
            ans = max(ans,nums2[day] + maxSubsetMemo(nums1,nums2,nums3,day+1,i));
        }
        else{
            ans = max(ans,nums3[day] + maxSubsetMemo(nums1,nums2,nums3,day+1,i));
        }
    }
    return ans;
};
int tabulation(vector<int> &nums1,vector<int> &nums2,vector<int> &nums3){
    int days = nums1.size();
    vector<vector<int>> dp(days,vector<int>(4,0));
}
int main(){
    //days 1 2 3
    vector<int> activity1 = {10, 20 ,30};
    vector<int> activity2 = {40, 50 ,60};
    vector<int> activity3 = {70,80,90};

   

    // cout << maxSubsetMemo(activity1, activity2,activity3,0,-1) << endl;
    cout << tabulation(activity1, activity2,activity3) << endl;

}
