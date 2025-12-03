# Subsets II - With Duplicates

## Problem Statement
Given a collection of integers that **might contain duplicates**, return all possible subsets (the power set) without duplicate subsets.

**Example:**
```
Input: nums = [1, 2, 2]
Output: [[], [1], [1,2], [1,2,2], [2], [2,2]]
```

**Key Difference from Subsets I:**
- Input may contain **duplicate elements**
- Output must contain **unique subsets only**
- Order of subsets doesn't matter, but no subset should appear twice

---

## Theory

### Why is This Different?

With duplicates like `[1, 2, 2]`, naive approaches would generate:
```
[1, 2, 2], [1, 2], [1, 2], [1], [2, 2], [2], [2], []
                    ^^^^^              ^^^^
                  Duplicates!        Duplicates!
```

### The Solution
**Sort the array first**, then skip over duplicate elements intelligently during recursion.

**Core Idea:**
- When we choose NOT to pick an element, we should also skip all its duplicates
- This prevents generating duplicate subsets

---

## Approach 1: Modified Pick/Not-Pick Method

### Key Modification
After deciding NOT to pick an element, skip all duplicate values:

```cpp
// After not picking nums[index]
int i = index + 1;
while (i < nums.size() && nums[i] == nums[i-1]) {
    i++;
}
// Continue recursion from i (skipping duplicates)
```

### Algorithm

```cpp
void picknotpick(vector<int> nums, int index, vector<int> ds) {
    // Base case
    if (index >= nums.size()) {
        result.push_back(ds);
        return;
    }
    
    // PICK: Include current element
    ds.push_back(nums[index]);
    picknotpick(nums, index + 1, ds);
    ds.pop_back();
    
    // NOT PICK: Skip current element AND all duplicates
    int i = index + 1;
    while (i < nums.size() && nums[i] == nums[i-1]) {
        i++;
    }
    picknotpick(nums, i, ds);
}
```

### Recursion Tree for [1, 2, 2]

```
                              solve([], 0)
                                   |
                 +-----------------+-----------------+
                 |                                   |
             PICK 1                              NOT PICK 1
                 |                                   |
           solve([1], 1)                       solve([], 1)
                 |                                   |
       +---------+---------+              +----------+----------+
       |                   |              |                     |
    PICK 2            NOT PICK 2       PICK 2              NOT PICK 2
       |                   |              |                     |
  solve([1,2], 2)    solve([1], 3)  solve([2], 2)         solve([], 3)
       |                   |              |                     |
   +---+---+               |          +---+---+                 |
   |       |               |          |       |                 |
 PICK 2  NOT PICK 2        |       PICK 2  NOT PICK 2           |
   |        |              |          |        |                |
 [1,2,2]  [1,2]          [1]       [2,2]     [2]              []
   ✓        ✓              ✓         ✓        ✓                ✓
```

**Key Observation:**
- When NOT picking the first `2` at index 1, we jump to index 3 (skipping duplicate `2` at index 2)
- This prevents generating duplicate subsets like `[1]` twice

### Detailed Execution Trace for [1, 2, 2]

```
Call 1: solve([], 0)
├─ PICK 1 → ds = [1]
│  │
│  Call 2: solve([1], 1)
│  ├─ PICK 2 (index 1) → ds = [1, 2]
│  │  │
│  │  Call 3: solve([1, 2], 2)
│  │  ├─ PICK 2 (index 2) → ds = [1, 2, 2]
│  │  │  │
│  │  │  Call 4: solve([1, 2, 2], 3)
│  │  │  └─ index >= size → Add [1, 2, 2] ✓
│  │  │
│  │  └─ NOT PICK 2 (index 2) → ds = [1, 2]
│  │     Skip duplicates: i = 2+1 = 3
│  │     │
│  │     Call 5: solve([1, 2], 3)
│  │     └─ index >= size → Add [1, 2] ✓
│  │
│  └─ NOT PICK 2 (index 1) → ds = [1]
│     Skip duplicates: i = 1+1 = 2
│     Check: nums[2] == nums[1]? → 2 == 2? YES
│     Increment: i = 3
│     │
│     Call 6: solve([1], 3)
│     └─ index >= size → Add [1] ✓
│
└─ NOT PICK 1 → ds = []
   No duplicates to skip (1 is unique)
   │
   Call 7: solve([], 1)
   ├─ PICK 2 (index 1) → ds = [2]
   │  │
   │  Call 8: solve([2], 2)
   │  ├─ PICK 2 (index 2) → ds = [2, 2]
   │  │  │
   │  │  Call 9: solve([2, 2], 3)
   │  │  └─ index >= size → Add [2, 2] ✓
   │  │
   │  └─ NOT PICK 2 (index 2) → ds = [2]
   │     Skip duplicates: i = 2+1 = 3
   │     │
   │     Call 10: solve([2], 3)
   │     └─ index >= size → Add [2] ✓
   │
   └─ NOT PICK 2 (index 1) → ds = []
      Skip duplicates: i = 1+1 = 2
      Check: nums[2] == nums[1]? → 2 == 2? YES
      Increment: i = 3
      │
      Call 11: solve([], 3)
      └─ index >= size → Add [] ✓
```

**Order of subsets added:**
1. `[1, 2, 2]`
2. `[1, 2]`
3. `[1]`
4. `[2, 2]`
5. `[2]`
6. `[]`

---

## Approach 2: Loop Method with Duplicate Skipping

### Key Modification
During the loop, skip duplicate elements using:
```cpp
if (i > index && nums[i] == nums[i-1]) continue;
```

**Why `i > index`?**
- `i == index`: First element in this recursion level (must process)
- `i > index`: Subsequent iterations (skip if duplicate)

### Algorithm

```cpp
void loopmethod(vector<int> nums, int index, vector<int> ds) {
    // Add current subset first
    result.push_back(ds);
    
    // Try adding each remaining element
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates (but not the first occurrence)
        if (i > index && nums[i] == nums[i-1]) {
            continue;
        }
        
        ds.push_back(nums[i]);      // Include element
        loopmethod(nums, i + 1, ds); // Recurse
        ds.pop_back();               // Backtrack
    }
}
```

### Recursion Tree for [1, 2, 2]

```
                           solve([], 0)
                           Add [] ✓
                                |
              +-----------------+-----------------+
              |                 |                 |
            i=0               i=1               i=2 (SKIP!)
           Pick 1            Pick 2         nums[2]==nums[1]
              |                 |
       solve([1], 1)      solve([2], 2)
         Add [1] ✓          Add [2] ✓
              |                 |
        +-----+-----+           |
        |           |           |
      i=1         i=2         i=2 (END)
     Pick 2   Pick 2 (SKIP)  Pick 2
        |      nums[2]==nums[1]  |
  solve([1,2],2)              solve([2,2],3)
   Add [1,2] ✓                Add [2,2] ✓
        |                         |
        |                      (no more)
      i=2 (END)
     Pick 2
        |
  solve([1,2,2],3)
   Add [1,2,2] ✓
        |
    (no more)
```

### Detailed Execution Trace for [1, 2, 2]

```
Call 1: solve([], 0)
  Add [] ✓
  Loop from i = 0 to 2:
  
  i=0: nums[0] = 1
    Check: i > index? NO (0 > 0 is false) → Process
    Pick 1, ds = [1]
    │
    Call 2: solve([1], 1)
      Add [1] ✓
      Loop from i = 1 to 2:
      
      i=1: nums[1] = 2
        Check: i > index? NO (1 > 1 is false) → Process
        Pick 2, ds = [1, 2]
        │
        Call 3: solve([1, 2], 2)
          Add [1, 2] ✓
          Loop from i = 2 to 2:
          
          i=2: nums[2] = 2
            Check: i > index? NO (2 > 2 is false) → Process
            Pick 2, ds = [1, 2, 2]
            │
            Call 4: solve([1, 2, 2], 3)
              Add [1, 2, 2] ✓
              Loop from i = 3 to 2: (no iteration)
            Backtrack: ds = [1, 2]
        Backtrack: ds = [1]
      
      i=2: nums[2] = 2
        Check: i > index? YES (2 > 1)
        Check: nums[2] == nums[1]? YES (2 == 2)
        → SKIP (continue)
    Backtrack: ds = []
  
  i=1: nums[1] = 2
    Check: i > index? YES (1 > 0)
    Check: nums[1] == nums[0]? NO (2 ≠ 1) → Process
    Pick 2, ds = [2]
    │
    Call 5: solve([2], 2)
      Add [2] ✓
      Loop from i = 2 to 2:
      
      i=2: nums[2] = 2
        Check: i > index? NO (2 > 2 is false) → Process
        Pick 2, ds = [2, 2]
        │
        Call 6: solve([2, 2], 3)
          Add [2, 2] ✓
          Loop from i = 3 to 2: (no iteration)
        Backtrack: ds = [2]
    Backtrack: ds = []
  
  i=2: nums[2] = 2
    Check: i > index? YES (2 > 0)
    Check: nums[2] == nums[1]? YES (2 == 2)
    → SKIP (continue)
```

**Order of subsets added:**
1. `[]`
2. `[1]`
3. `[1, 2]`
4. `[1, 2, 2]`
5. `[2]`
6. `[2, 2]`

---

## Why Sorting is Essential

### Without Sorting: [2, 1, 2]
```
Duplicates are not adjacent
↓
Cannot detect duplicates by comparing nums[i] with nums[i-1]
↓
Will generate duplicate subsets
```

### With Sorting: [1, 2, 2]
```
Duplicates are adjacent
↓
Can easily detect: nums[i] == nums[i-1]
↓
Skip duplicates and avoid duplicate subsets
```

---

## Comparison of Both Approaches

| Aspect | Pick/Not-Pick | Loop Method |
|--------|---------------|-------------|
| **Duplicate Handling** | Skip after NOT picking | Skip in loop |
| **Skip Logic** | `while` loop to find next different element | `if (i > index && nums[i] == nums[i-1])` |
| **Complexity** | Slightly more complex | Simpler and cleaner |
| **When to Add** | At base case | At function start |
| **Order** | Similar to Subsets I | Similar to Subsets I |
| **Preferred** | Educational | Practical |

---

## Visual Example: How Duplicates are Skipped

### For Array [1, 2, 2]:

**Pick/Not-Pick Method:**
```
At index 1 (first 2):
  - Pick it → explore [1, 2, ...]
  - Not pick it → skip to index 3 (bypass second 2)
  
This prevents: [1] appearing twice (once with each 2)
```

**Loop Method:**
```
At any level, when iterating:
  i=1: First 2 → Process it
  i=2: Second 2 → Skip (duplicate of previous)
  
This prevents: Adding [2] twice from different positions
```

---

## Complexity Analysis

### Time Complexity: O(2^n × n)
- In worst case (all unique elements): 2^n subsets
- Each subset takes O(n) time to copy
- With duplicates, fewer subsets generated but still O(2^n)

### Space Complexity: O(n)
- Recursion depth: O(n)
- Data structure `ds` size: O(n)
- Not counting output space O(2^n × n)

---

## Complete Code

```cpp
#include <bits/stdc++.h>
using namespace std;

vector<vector<int>> result;

// Method 1: Pick/Not-Pick with duplicate skipping
void picknotpick(vector<int> nums, int index, vector<int> ds) {
    if (index >= nums.size()) {
        result.push_back(ds);
        return;
    }
    
    // PICK the element
    ds.push_back(nums[index]);
    picknotpick(nums, index + 1, ds);
    
    // NOT PICK - skip all duplicates
    ds.pop_back();
    int i = index + 1;
    while (i < nums.size() && nums[i] == nums[i-1]) {
        i++;
    }
    picknotpick(nums, i, ds);
}

// Method 2: Loop method with duplicate skipping
void loopmethod(vector<int> nums, int index, vector<int> ds) {
    result.push_back(ds);
    
    for (int i = index; i < nums.size(); i++) {
        // Skip duplicates (but not first occurrence)
        if (i > index && nums[i] == nums[i-1]) {
            continue;
        }
        ds.push_back(nums[i]);
        loopmethod(nums, i + 1, ds);
        ds.pop_back();
    }
}

int main() {
    vector<int> nums = {1, 2, 2};
    
    // IMPORTANT: Sort the array first!
    sort(nums.begin(), nums.end());
    
    vector<int> ds;
    
    // Choose one method:
    // picknotpick(nums, 0, ds);
    loopmethod(nums, 0, ds);
    
    // Print results
    for (auto it : result) {
        cout << " { ";
        for (auto ele : it) {
            cout << ele << " ";
        }
        cout << " } " << endl;
    }
    
    return 0;
}
```

---

## Key Insights for Interview

### 1. Always Sort First
```cpp
sort(nums.begin(), nums.end());
```
This is **mandatory** for duplicate detection.

### 2. Duplicate Skipping Patterns

**Pick/Not-Pick:**
```cpp
// After not picking
int i = index + 1;
while (i < nums.size() && nums[i] == nums[i-1]) i++;
picknotpick(nums, i, ds);
```

**Loop Method:**
```cpp
// Inside loop
if (i > index && nums[i] == nums[i-1]) continue;
```

### 3. Why `i > index`?
- First element at this level must be processed
- Only skip subsequent duplicates in the same level

### 4. Test Cases
```cpp
// Test Case 1: All unique
Input: [1, 2, 3]
Output: 8 subsets (same as Subsets I)

// Test Case 2: All duplicates
Input: [1, 1, 1]
Output: 4 subsets: [], [1], [1,1], [1,1,1]

// Test Case 3: Mixed
Input: [1, 2, 2]
Output: 6 subsets

// Test Case 4: Empty
Input: []
Output: 1 subset: []
```

---

## Common Mistakes to Avoid

### ❌ Mistake 1: Forgetting to Sort
```cpp
vector<int> nums = {2, 1, 2};
// Calling function without sorting → WRONG!
```

### ❌ Mistake 2: Wrong Skip Condition
```cpp
// WRONG: Missing i > index check
if (nums[i] == nums[i-1]) continue;  // Skips even first occurrence!
```

### ❌ Mistake 3: Using Set for Deduplication
```cpp
set<vector<int>> result;  // Works but inefficient O(n log n) per insert
```

---

## Step-by-Step Problem Solving Guide

### When you see this problem:

1. **Recognize:** "Subsets with duplicates"
2. **Sort:** Always sort the array first
3. **Choose Method:**
   - Loop method (preferred for simplicity)
   - Pick/Not-Pick (if asked specifically)
4. **Add Skip Logic:**
   - Loop: `if (i > index && nums[i] == nums[i-1])`
   - Pick/Not-Pick: `while` loop after not picking
5. **Test:** Run with [1, 2, 2] mentally

---

## Practice Problems

1. **Combination Sum II** (Similar duplicate handling)
2. **Permutations II** (Duplicates in permutations)
3. **Subsets** (Without duplicates - easier version)
4. **Palindrome Partitioning** (Backtracking pattern)

---

## Summary

| Concept | Key Point |
|---------|-----------|
| **Main Challenge** | Avoid duplicate subsets when input has duplicates |
| **Solution** | Sort + Skip duplicates intelligently |
| **Pick/Not-Pick** | Skip duplicates after NOT picking |
| **Loop Method** | Skip duplicates in loop: `i > index && nums[i] == nums[i-1]` |
| **Time** | O(2^n × n) |
| **Space** | O(n) recursion depth |
| **Must Remember** | ALWAYS sort first! |

---
