# Fibonacci using recursion

## This is based on concept of multiple recursion calls

When the left recursion calls comeplete then only the right function call occurs 

Fibonacci 
## Definition
The Fibonacci sequence is a series of numbers where each number is the sum of the two preceding ones, starting from 0 and 1.

**Formula:** F(n) = F(n-1) + F(n-2)

**Base Cases:**
- F(0) = 0
- F(1) = 1

## Example
```
F(5) = 5
Sequence: 0, 1, 1, 2, 3, 5
```

## Recursive Approach
```cpp
int fibonacci(n):
    if(n <=1) return n;
    int last = fibonacci(n-1);
    int secondlast = fibonacci(n-2);
    return last+secondlast;

```

### Recusion tree
```
                    fib(5)
                   /      \
              fib(4)        fib(3)
             /      \      /      \
        fib(3)    fib(2)  fib(2)  fib(1)
       /    \    /    \  /    \
    fib(2) fib(1) fib(1) fib(0) fib(1) fib(0)
   /    \
fib(1) fib(0)
```
