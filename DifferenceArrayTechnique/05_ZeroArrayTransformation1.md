# Leetcode 3355. Zero Array Transformation I

Same template question 

```cpp
class Solution {
public:
    bool isZeroArray(vector<int>& nums, vector<vector<int>>& queries) {
        //check if it is already 0
        bool allzero = true;
        for(int i = 0 ; i < nums.size();i++){
            if(nums[i]>0) allzero = false;
        }
        if(allzero) return true;

        vector<int> temp(nums.size(),0);
        for(int i = 0 ; i < queries.size();i++){
            int start = queries[i][0];
            int end = queries[i][1];

            temp[start] += 1;
            if(end < nums.size()-1) temp[end+1] -= 1;
        }

        //now checking
        int cumm = 0;
        for(int i = 0 ; i < temp.size();i++){
            cumm += temp[i];
            if((nums[i]-cumm)>0) return false;
        }
        return true;


    }
};
```
