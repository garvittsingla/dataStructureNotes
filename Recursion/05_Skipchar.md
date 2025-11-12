# Recursive Function to Skip a Character From a String
Write a recursive function that removes all occurrences of a given character from a string.

### Example

```
Input  : "abbbbbaaabbbasdbabdasdasdadas"
Output : "aaaaasdadasdasdadas"   # Skipped all b
```

---

##  Approach / Intuition

Recursion works by solving smaller parts of a big problem. In this case:

1. Look at the **first character** of the string.
2. If it's the character we want to skip, ignore it and recursively process the remaining string.
3. If it's not the character to skip, **include it** and continue recursively.

### Base Case

If string becomes empty → return `""`.

### Recursive Case

* Extract `currentChar = str[0]`
* If `currentChar == ch` → skip it and call recursion on remaining string.
* Else → keep it and append to recursive result.

---

##  C++ Code

```cpp
#include <bits/stdc++.h>
using namespace std;

string skipchar(string str, char ch) {
    if (str.size() == 0) {
        return "";
    }

    char currentchar = str[0];

    if (currentchar == ch) {
        return skipchar(str.substr(1, str.size()), ch);
    }

    return currentchar + skipchar(str.substr(1, str.size()), ch);
}

int main() {
    string str = "helloworld";
    cout << skipchar(str, 'l');
}
```

---

## Recursion Tree (Example: `skipchar("helloworld", 'l')`)

```
skipchar("helloworld", 'l')
| current = 'h' (keep)
| → "h" + skipchar("elloworld", 'l')

    skipchar("elloworld", 'l')
    | current = 'e' (keep)
    | → "e" + skipchar("lloworld", 'l")

        skipchar("lloworld", 'l')
        | current = 'l' (skip)
        | → skipchar("loworld", 'l")

            skipchar("loworld", 'l")
            | current = 'l' (skip)
            | → skipchar("oworld", 'l")

                skipchar("oworld", 'l")
                | current = 'o' (keep)
                | → "o" + skipchar("world", 'l")

                    skipchar("world", 'l")
                    | current = 'w' (keep)
                    | → "w" + skipchar("orld", 'l")

                        skipchar("orld", 'l")
                        | current = 'o' (keep)
                        | → "o" + skipchar("rld", 'l")

                            skipchar("rld", 'l")
                            | current = 'r' (keep)
                            | → "r" + skipchar("ld", 'l")

                                skipchar("ld", 'l")
                                | current = 'l' (skip)
                                | → skipchar("d", 'l")

                                    skipchar("d", 'l")
                                    | current = 'd' (keep)
                                    | → "d" + skipchar("", 'l")

                                        skipchar("", 'l")
                                        → ""
```

### Final Result Builds Up Like:

```
"" → "d" → "rd" → "ord" → "word" → "oword" → ... → "heloworld"
```

Final Output:

```
heloworld
```

---

## Time & Space Complexity

| Metric           | Value                                        |
| ---------------- | -------------------------------------------- |
| Time Complexity  | **O(n)** — every character is processed once |
| Space Complexity | **O(n)** — due to recursive call stack       |

---

