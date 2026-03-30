## 3346. Maximum Frequency of an Element After Performing Operations I

This is difficult to analyze type question

Any element in nums[i] can be either added by k or subtracted by k, so what we can do is make a array of that max size and then apply the diff array technique to do out tasks, taking tha 0 as threshold cause the elements in the array cannot be negative , 

Just doing the same for updating the start and subtracting from the end


Then after making the array, we can make the max of that element in the array, so we have to subtract that we already have , removing it will will give the number of needed conversions, after comparing the num of operations that can be done , we can calculate max result by adding max possible conversion with the already present in nums

```cpp
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxelement = *max_element(nums.begin(),nums.end()) + k;
        vector<int> diff(maxelement+2,0);
        unordered_map<int,int> mpp;
        for(int i = 0 ; i < nums.size();i++){
            mpp[nums[i]]++;
            int maxval= max(nums[i]-k,0);
            int minval =min(nums[i]+k,maxelement);
            diff[maxval]++;
            diff[minval+1]--;



        }
        int result = 1;
        int cumm = 0;
        for(int target = 0; target <= maxelement;target++){
            cumm += diff[target];
            int targetfreq = mpp[target];
            int needconversion = cumm - targetfreq;
            int maxpossible = min(numOperations,needconversion);
            result = max(result,maxpossible + targetfreq);
        }
        return result;

    }
};
```
