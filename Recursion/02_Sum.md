# Sum of first N numbers (recursion)

Problem
> Given a non‑negative integer n, compute the sum of the first n natural numbers: 1 + 2 + ... + n.

Examples
- n = 5 → 15
- n = 0 → 0
- n = 1 → 1

Recursive idea
- Base case: if n == 0 return 0 
- Recursive step: sum(n) = n + sum(n - 1).

c++ implementation
```cpp
int sum(int n){
    if (n==0) return 0;
    return n+sum(n-1);
}
```

Notes
- Time complexity: O(n)
- Space complexity: O(n) due to recursion depth (use iterative approach to get O(1) space).

### Recursion tree (example: sum(5))

```
sum(5)
└─ 5 + sum(4)
    └─ 4 + sum(3)
        └─ 3 + sum(2)
            └─ 2 + sum(1)
                └─ 1 + sum(0)
                    └─ 0   (base case)
```

Evaluation (bottom-up):
```
sum(0) = 0
sum(1) = 1 + 0 = 1
sum(2) = 2 + 1 = 3
sum(3) = 3 + 3 = 6
sum(4) = 4 + 6 = 10
sum(5) = 5 + 10 = 15
```

### Call stack frames (moment at deepest recursion, just before sum(0) returns)

Top (current frame)
```
Frame: sum(0)
- n = 0
- state: base case, will return 0
```

Below top
```
Frame: sum(1)
- n = 1
- waiting for return of sum(0)
- pending: return 1 + <result of sum(0)>
```

```
Frame: sum(2)
- n = 2
- waiting for return of sum(1)
- pending: return 2 + <result of sum(1)>
```

```
Frame: sum(3)
- n = 3
- waiting for return of sum(2)
- pending: return 3 + <result of sum(2)>
```

```
Frame: sum(4)
- n = 4
- waiting for return of sum(3)
- pending: return 4 + <result of sum(3)>
```

Bottom (initial call)
```
Frame: sum(5)
- n = 5
- waiting for return of sum(4)
- pending: return 5 + <result of sum(4)>
```

Unwinding sequence: sum(0) returns → sum(1) completes → sum(2) completes → ... → sum(5) returns 15.