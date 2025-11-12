# Generate All Subsequences (Power Set) Using Recursion

Write a recursive function that prints **all subsequences** of a given string.

Example:

```cpp
Input  : "abc"
Output :
abc
ab
ac
a
bc
b
c
```

---

## Approach / Intuition

At every step, recursion decides **two choices** regarding the current character:

| Option  | Meaning                                                   | Result                      |
| ------- | --------------------------------------------------------- | --------------------------- |
| include | Add the current character to the output (`p + character`) | character is part of subset |
| exclude | Skip the current character (`p`)                          | character not included      |

This naturally builds a **binary recursion tree**, exploring all subset possibilities.

---

###  Base Case

If the `up` (unprocessed string) is empty → print `p` (processed string).

```cpp
if (up.length() == 0) {
    cout << p << endl;
    return;
}
```

---

##  Recursive Case

Let:

* `p` = processed part (what we have included so far)
* `up` = unprocessed part (characters still remaining)

We pick the first character and then:

1. Include it → `p + character`
2. Exclude it → `p`

---

##  C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

void sub(string p, string up) {
    if (up.length() == 0) {
        cout << p << endl;
        return;
    }

    char character = up[0];

    // Option 1: Include the character
    sub(p + character, up.substr(1, up.length()));

    // Option 2: Exclude the character
    sub(p, up.substr(1, up.length()));
}

int main(void) {
    sub("", "abc");
}
```

---

## 🌳 Recursion Tree (for input: `"abc"`)

```
                       sub("", "abc")
                         /          \
                        /            \
                  include 'a'     exclude 'a'
                    /                  \
         sub("a", "bc")             sub("", "bc")
             /     \                   /      \
 include 'b'       exclude 'b'  include 'b'   exclude 'b'
     |                |            |           |
sub("ab","c")   sub("a","c") sub("b","c")  sub("","c")
      / \           / \          / \          / \
   c     _       c     _       c     _      c    _   <-- reverse tree building
```

Each leaf (end state) prints a subsequence.

---

## 🧠 Time & Space Complexity

| Metric | Complexity                                                 |
| ------ | ---------------------------------------------------------- |
| Time   | **O(2ⁿ)** — each character has 2 choices (include/exclude) |
| Space  | **O(n)** — recursion depth                                 |
