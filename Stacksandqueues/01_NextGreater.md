# Next greater element

## Problem Statement

Given an array, find the next greater element (NGE) for every element. The next greater element for an element x is the first greater element on the right side of x in the array.

## Approach
Use a **stack** to solve this problem in O(n) time complexity.

### Algorithm

1. Push the first element to the stack
2. Pick the rest of the elements one by one
3. While stack is not empty and the current element is greater than the top element:
    - Pop the top element and print/store the current element as NGE for the popped element
4. Push the current element to stack
5. After traversal, remaining elements in stack have no NGE (assign -1)

## Time & Space Complexity

| Complexity | Value |
|------------|-------|
| Time       | O(n)  |
| Space      | O(n)  |

## Code Example

```cpp
def next_greater_element(arr):
     stack = []
     result = [-1] * len(arr)
     
     for i in range(len(arr) - 1, -1, -1):
          while stack and stack[-1] <= arr[i]:
                stack.pop()
          
          if stack:
                result[i] = stack[-1]
          
          stack.append(arr[i])
     
     return result
```

## Example

| Input | Output |
|-------|--------|
| [4, 5, 2, 25] | [5, 25, 25, -1] |
| [13, 7, 6, 12] | [-1, 12, 12, -1] |

## Variations

- **Next Smaller Element** - Find first smaller element on the right
- **Previous Greater Element** - Find first greater element on the left
- **Circular Array NGE** - Array is circular, wrap around to find NGE