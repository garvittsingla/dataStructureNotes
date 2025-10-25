# Factorial using recursion

### Factorial of a number is multiplication of that number till 1 

example:-> 4! = 14
5! = 120

Recursive idea:
- Base case :  if n==1 return 1

c++ implementation
```cpp
int factorial(int n){
    if (n==1) return 1;
    return n*factorial(n-1);
}
```

### Notes
- Time complexity: O(n). Space complexity: O(n) due to recursion depth.
- Results overflow standard integer types for modest n (e.g., 21! overflows 64-bit). Use big-integer libraries for large values.

#### Recursion tree (example: factorial(4))

```
factorial(4)
└─ 4 * factorial(3)
    └─ 3 * factorial(2)
        └─ 2 * factorial(1)
            └─ 1   (base case, returns 1)
```

Evaluation (bottom-up):
- factorial(1) = 1  
- factorial(2) = 2 * 1 = 2  
- factorial(3) = 3 * 2 = 6  
- factorial(4) = 4 * 6 = 24

#### Call stack (state at deepest point, top = most recent call)

```
┌─────────────────────────────┐  <-- top
│ frame: factorial(1)         │
│ n = 1                      │
│ state: base case, will return 1
└─────────────────────────────┘
┌─────────────────────────────┐
│ frame: factorial(2)         │
│ n = 2                      │
│ state: waiting for factorial(1)
└─────────────────────────────┘
┌─────────────────────────────┐
│ frame: factorial(3)         │
│ n = 3                      │
│ state: waiting for factorial(2)
└─────────────────────────────┘
┌─────────────────────────────┐  <-- bottom (initial call)
│ frame: factorial(4)         │
│ n = 4                      │
│ state: waiting for factorial(3)
└─────────────────────────────┘
```

Unwinding example (frames updated as returns propagate):
- After factorial(1) returns 1, factorial(2) computes 2*1 and returns 2, then factorial(3) computes 3*2, etc.

Notes:
- Each frame holds the parameter n and the return address; intermediate multiplication result is computed when the callee returns.
- Stack depth equals n (for this implementation with base case n==1).