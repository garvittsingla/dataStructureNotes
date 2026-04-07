# Dynamic Programming

1. It can be told as  advanced recursion that is done to optimise the function calls and to optimise the working of the recursions
2. Dp is often considered as a way to divide a probelem into many subproblems and solving them


## Knapsack
Knapsack is another name of any type of bag

### It tells you have a bag of limited capacity and some items to store it in having differenct values , you hav to maximise that value.

## Type of knapsack
1. 0/1 Knapsack -> When we can either take a item in whole or not , and not in fractions
2. Fractional Knapsack -> When we can take a item in fractions without taking in a whole
3. Unbounded -> When we can take a single itsm multipe times is known as unbounded knapsack
When we have choices , we can use knapsack



## 0/1 knapsack 
#### Recursive code Knapsack 0/1
```cpp
class Solution {
public:
    int recurse(int W, vector<int> &val, vector<int> &wt, int index) {
        if (index == val.size() || W == 0)
            return 0;
        if (wt[index] <= W) {
            return max(
                val[index] + recurse(W - wt[index], val, wt, index + 1), // include
                recurse(W, val, wt, index + 1)                           // exclude
            );
        }
        else {
            return recurse(W, val, wt, index + 1);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        return recurse(W, val, wt, 0);
    }
};
```

#### Memoized code
```cpp
class Solution {
public:
    int recurse(int W, vector<int> &val, vector<int> &wt, int index,vector<vector<int>> &dp) {
        if (index == 0) {
            if (wt[0] <= W) return val[0];
            else return 0;
        }
        if(dp[index][W]!=-1) return dp[index][W];
        if (wt[index] <= W) {
            return dp[index][W] = max(
                val[index] + recurse(W - wt[index], val, wt, index - 1,dp), // include
                recurse(W, val, wt, index - 1,dp)                           // exclude
            );
        }
        else {
            return  dp[index][W] = recurse(W, val, wt, index - 1,dp);
        }
    }

    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        vector<vector<int>> dp(val.size(), vector<int>(W + 1, -1));
        return recurse(W, val, wt, val.size()-1,dp);
    }
};
```
#### Tabulation
We avoid recursion , and only take the space is called tabulation
The first row and col can be considered as seeding or the base case for iterative approach
```cpp
class Solution {
  public:
    int knapsack(int W, vector<int> &val, vector<int> &wt) {
        int n = wt.size();
    vector<vector<int>> dp(W + 1, vector<int>(n + 1));

    for (int i = 0; i <= W; i++)
        {
            for (int j = 0; j <= n; j++)
            {
                if (i == 0 || j == 0)
                {
                    dp[i][j] = 0;
                }
                else if (wt[j - 1] <= i)
                {
                    int pick = val[j - 1] + dp[i - wt[j - 1]][j - 1];
                    int non_pick = dp[i][j - 1];
    
                    dp[i][j] = max(pick, non_pick);
                }
                else
                {
                    dp[i][j] = dp[i][j - 1];
                }
            }
        }

        return dp[W][n];
    }
};
```
## Some famous knapsack problems
1. Subset sum problem
2. Equal sum partition
3. Minimum subset sum difference
4. Target sum
