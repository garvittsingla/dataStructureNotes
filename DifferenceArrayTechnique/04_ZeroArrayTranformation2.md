# Leetcode 3356. Zero Array Transformation II


Simple question same as prev ones, just used binary search for some optimization
```cpp
class Solution {
public:
    bool diffarr(vector<int>& nums,vector<vector<int>>&queries,int k){
        vector<int> temp(nums.size());
        //check already 0
        bool allzero = true;
        for(int i = 0 ; i < nums.size() ; i++){
            if(nums[i]>0) allzero = false;
        }
        if(allzero) return true;

        for(int i = 0 ; i < k;i++){
            int start= queries[i][0];
            int end= queries[i][1];
            int val = queries[i][2];

            temp[start] += val;
            if(end < nums.size()-1) temp[end+1]-= val;
        }
        int cum = 0;
        for(int i = 0 ; i < temp.size();i++){
            cum += temp[i];
            if(nums[i]-cum > 0) return false;
        }
        return true;


    }
    int minZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
       int low = 0;
       int high = queries.size();
        int possible = -1;
        if(diffarr(nums, queries, 0)) return 0;
       while(low<=high){
            int mid  = low+(high-low)/2;
            if(diffarr(nums,queries,mid)){
                possible = mid;
                high = mid-1;
            }else{
                low = mid+1;
            }
       }
       return possible;

    }
};
```
