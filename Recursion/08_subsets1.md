# Subsets / Power Set Problem

## Problem Statement
Given a set of distinct integers, generate all possible subsets (the power set).

**Example:**
```
Input: nums = [1, 2, 3]
Output: [[], [1], [2], [3], [1,2], [1,3], [2,3], [1,2,3]]
```

## Theory

### What is a Subset?
A subset is any combination of elements from the original set, including:
- The empty set `[]`
- Individual elements `[1], [2], [3]`
- Combinations `[1,2], [1,3], [2,3]`
- The complete set `[1,2,3]`

### Number of Subsets
For a set with `n` elements, there are **2^n** possible subsets.
- For `[1,2,3]`: 2³ = 8 subsets

## Approach 1: Pick / Not Pick Method

### Intuition
At each element, we have two choices:
1. **Pick** the element (include it in current subset)
2. **Not Pick** the element (exclude it from current subset)

This creates a binary decision tree where each path represents a unique subset.

### Algorithm
```cpp
void solve(vector<int> nums, vector<int> ds, int index) {
    // Base case: processed all elements
    if (index >= nums.size()) {
        result.push_back(ds);
        return;
    }
    
    // Choice 1: Pick the element
    ds.push_back(nums[index]);
    solve(nums, ds, index + 1);
    
    // Choice 2: Not pick (backtrack first)
    ds.pop_back();
    solve(nums, ds, index + 1);
}
```

### Recursion Tree for [1, 2, 3]

```
                                solve([], 0)
                                    |
                    +---------------+---------------+
                    |                               |
                  PICK 1                        NOT PICK 1
                    |                               |
              solve([1], 1)                   solve([], 1)
                    |                               |
          +---------+---------+           +---------+---------+
          |                   |           |                   |
        PICK 2            NOT PICK 2    PICK 2            NOT PICK 2
          |                   |           |                   |
    solve([1,2], 2)     solve([1], 2) solve([2], 2)     solve([], 2)
          |                   |           |                   |
     +----+----+         +----+----+  +----+----+        +----+----+
     |         |         |         |  |         |        |         |
   PICK 3  NOT PICK 3  PICK 3  NOT PICK 3  PICK 3  NOT PICK 3  PICK 3  NOT PICK 3
     |         |         |         |  |         |        |         |
  [1,2,3]   [1,2]     [1,3]     [1] [2,3]     [2]      [3]       []
```

### Step-by-Step Execution for [1, 2, 3]

**Call Stack Trace:**

```
1. solve([], 0)
   ├─ Pick 1 → ds = [1]
   │  └─ solve([1], 1)
   │     ├─ Pick 2 → ds = [1,2]
   │     │  └─ solve([1,2], 2)
   │     │     ├─ Pick 3 → ds = [1,2,3]
   │     │     │  └─ solve([1,2,3], 3) → Add [1,2,3] ✓
   │     │     └─ Not Pick 3 → ds = [1,2]
   │     │        └─ solve([1,2], 3) → Add [1,2] ✓
   │     └─ Not Pick 2 → ds = [1]
   │        └─ solve([1], 2)
   │           ├─ Pick 3 → ds = [1,3]
   │           │  └─ solve([1,3], 3) → Add [1,3] ✓
   │           └─ Not Pick 3 → ds = [1]
   │              └─ solve([1], 3) → Add [1] ✓
   └─ Not Pick 1 → ds = []
      └─ solve([], 1)
         ├─ Pick 2 → ds = [2]
         │  └─ solve([2], 2)
         │     ├─ Pick 3 → ds = [2,3]
         │     │  └─ solve([2,3], 3) → Add [2,3] ✓
         │     └─ Not Pick 3 → ds = [2]
         │        └─ solve([2], 3) → Add [2] ✓
         └─ Not Pick 2 → ds = []
            └─ solve([], 2)
               ├─ Pick 3 → ds = [3]
               │  └─ solve([3], 3) → Add [3] ✓
               └─ Not Pick 3 → ds = []
                  └─ solve([], 3) → Add [] ✓
```

**Order of subsets added:**
1. `[1,2,3]`
2. `[1,2]`
3. `[1,3]`
4. `[1]`
5. `[2,3]`
6. `[2]`
7. `[3]`
8. `[]`

### Time & Space Complexity
- **Time Complexity:** O(2^n × n)
  - 2^n subsets
  - Each subset takes O(n) to copy
- **Space Complexity:** O(n)
  - Recursion depth is n
  - Not counting output space

---

## Approach 2: Loop / Iterative Backtracking Method

### Intuition
Instead of binary pick/not-pick, we use a loop at each level to choose which element to include next. This naturally avoids duplicates and generates subsets in a different order.

### Algorithm
```cpp
void solve2(vector<int> nums, vector<int> ds, int index) {
    // Add current subset
    result.push_back(ds);
    
    // Try adding each remaining element
    for (int i = index; i < nums.size(); i++) {
        ds.push_back(nums[i]);      // Include element
        solve2(nums, ds, i + 1);     // Recurse
        ds.pop_back();               // Backtrack
    }
}
```

### Recursion Tree for [1, 2, 3]

```
                           solve2([], 0)
                           Add [] ✓
                                |
              +-----------------+-----------------+
              |                 |                 |
            i=0               i=1               i=2
           Pick 1            Pick 2            Pick 3
              |                 |                 |
       solve2([1], 1)    solve2([2], 2)   solve2([3], 3)
         Add [1] ✓          Add [2] ✓        Add [3] ✓
              |                 |                 |
        +-----+-----+           |              (no more)
        |           |           |
      i=1         i=2         i=2
     Pick 2      Pick 3      Pick 3
        |           |           |
  solve2([1,2],2) solve2([1,3],3) solve2([2,3],3)
   Add [1,2] ✓    Add [1,3] ✓    Add [2,3] ✓
        |             |              |
        |          (no more)      (no more)
      i=2
     Pick 3
        |
  solve2([1,2,3],3)
   Add [1,2,3] ✓
        |
    (no more)
```

### Step-by-Step Execution for [1, 2, 3]

```
solve2([], 0):
  Add [] ✓
  Loop i = 0 to 2:
  
  i=0: Pick 1, ds = [1]
    solve2([1], 1):
      Add [1] ✓
      Loop i = 1 to 2:
      
      i=1: Pick 2, ds = [1,2]
        solve2([1,2], 2):
          Add [1,2] ✓
          Loop i = 2 to 2:
          
          i=2: Pick 3, ds = [1,2,3]
            solve2([1,2,3], 3):
              Add [1,2,3] ✓
              Loop i = 3 to 2: (no iteration)
            Backtrack: ds = [1,2]
        Backtrack: ds = [1]
      
      i=2: Pick 3, ds = [1,3]
        solve2([1,3], 3):
          Add [1,3] ✓
          Loop i = 3 to 2: (no iteration)
        Backtrack: ds = [1]
    Backtrack: ds = []
  
  i=1: Pick 2, ds = [2]
    solve2([2], 2):
      Add [2] ✓
      Loop i = 2 to 2:
      
      i=2: Pick 3, ds = [2,3]
        solve2([2,3], 3):
          Add [2,3] ✓
          Loop i = 3 to 2: (no iteration)
        Backtrack: ds = [2]
    Backtrack: ds = []
  
  i=2: Pick 3, ds = [3]
    solve2([3], 3):
      Add [3] ✓
      Loop i = 3 to 2: (no iteration)
    Backtrack: ds = []
```

**Order of subsets added:**
1. `[]`
2. `[1]`
3. `[1,2]`
4. `[1,2,3]`
5. `[1,3]`
6. `[2]`
7. `[2,3]`
8. `[3]`

### Time & Space Complexity
- **Time Complexity:** O(2^n × n)
  - Still generates 2^n subsets
  - Each subset takes O(n) to copy
- **Space Complexity:** O(n)
  - Recursion depth is n

---

## Comparison of Both Approaches

| Aspect | Pick/Not-Pick | Loop Method |
|--------|---------------|-------------|
| **Recursion Style** | Binary tree (2 choices) | N-ary tree (loop choices) |
| **Base Case** | `index >= n` | Implicit (loop ends) |
| **When to Add** | At base case | At function start |
| **Order** | Lexicographic reverse | Lexicographic forward |
| **Empty Set** | Added last | Added first |
| **Intuition** | Decision at each element | Choose from remaining |

### Visual Comparison for [1, 2]

**Pick/Not-Pick Tree:**
```
         []
        /  \
    Pick   Not
      /      \
    [1]      []
    / \      / \
  [1,2] [1] [2] []
```

**Loop Method Tree:**
```
          []
        /  |
      [1] [2]
      /
    [1,2]
```

---

## Code Implementation

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

// Method 1: Pick - Not Pick
void solve(vector<int> nums, vector<int> ds, int index) {
    if (index >= nums.size()) {
        result.push_back(ds);
        return;
    }
    
    // Pick the element
    ds.push_back(nums[index]);
    solve(nums, ds, index + 1);
    
    // Not pick (backtrack)
    ds.pop_back();
    solve(nums, ds, index + 1);
}

// Method 2: Loop Approach
void solve2(vector<int> nums, vector<int> ds, int index) {
    result.push_back(ds);
    
    for (int i = index; i < nums.size(); i++) {
        ds.push_back(nums[i]);
        solve2(nums, ds, i + 1);
        ds.pop_back();
    }
}

int main() {
    vector<int> arr = {1, 2, 3};
    vector<int> ds;
    
    // Use solve2 for loop approach
    solve2(arr, ds, 0);
    
    for (auto it : result) {
        cout << "{ ";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << "}" << endl;
    }
    
    return 0;
}
```

---

## Key Takeaways

1. **Backtracking Pattern:** Both methods use the classic backtracking pattern:
   - Make a choice
   - Recurse
   - Undo the choice (backtrack)

2. **Choice Representation:**
   - Pick/Not-Pick: Binary choice at each level
   - Loop: Multiple choices (all remaining elements)

3. **Subset Generation:** Both generate all 2^n subsets but in different orders

4. **Pass by Value:** Using `vector<int> ds` (pass by value) naturally handles backtracking as each call has its own copy

5. **When to Use:**
   - Pick/Not-Pick: Better for understanding recursion, similar to coin change
   - Loop: More efficient, cleaner code, preferred in practice

---

