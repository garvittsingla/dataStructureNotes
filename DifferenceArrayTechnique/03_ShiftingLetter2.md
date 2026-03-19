# Leetcode 2381. Shifting Letters II


Same as the prev problem, we will find the cummilative shift and at that at the end of the array
```cpp
class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        vector<int> temp(s.size(),0);
        for(int i = 0 ; i < shifts.size();i++){
            int start = shifts[i][0];
            int end = shifts[i][1];
            int shift = shifts[i][2] == 1 ? 1 : -1;
            temp[start] += shift;
            if(end < s.size()-1) temp[end+1] -= shift; 

        }
        int cummilative = 0;
        string ans = "";
        for(int i = 0 ; i < temp.size();i++){
            cummilative += temp[i];
            cummilative = cummilative%26; // wrapping around 
            if(cummilative<0) cummilative+=26; //if -ve make it positve 
            char newchar = (((s[i]-'a') + cummilative) % 26) + 'a'; //complex but understandable
            ans += newchar;
        }
        return ans;
    }
};
```
