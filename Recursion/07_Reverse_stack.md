# Reverse a stack

## Intuition
To reverse a stack using recursion , we can just make the stack shorted and shorter untill we reach the base case and always store the element that we are going to delete everytime.

## Approach
1. Make a function that takes stack as input and checks if the stack size is empty or not , when found empty the stack and also insert the last element at its correct position.

2. To insert the last element at its correct position make another function that takes the stack and the element to be inserted as input and checks if the stack is empty , if yes push the element to be inserted , else pop the last element and call the function again until we find the correct position to insert the element.



## code 
```c++
#include <bits/stdc++.h>

using namespace std;

template <class T>
struct IterableStack : public stack<T> {
    using stack<T>::c; 
};
IterableStack<int> insertatbottom(IterableStack<int> st,int value){
    if(st.empty()) {
        st.push(value);
        return st;
    };
    int temp = st.top();
    st.pop();
    insertatbottom(st,value);
    st.push(temp);
    return st;
}
IterableStack<int> reverse(IterableStack<int> st){
    if(st.empty()) return st;
    int value = st.top();
    st.pop();
    st = insertatbottom(st,value);
    return st;

};

int main(void){
    IterableStack<int> st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    //5321
   for (int x : st.c) {
        cout << x << " ";
    }
    cout << "After ";
    st = reverse(st);
    for (int x : st.c) {
        cout << x << " ";
    }

    
}
```

## Recursion tree

Initial stack: [1,2,3,4,5] (5 at top)

```
reverse([1,2,3,4,5])              // pop 5, store it
└─ reverse([1,2,3,4])             // pop 4, store it
    └─ reverse([1,2,3])           // pop 3, store it
        └─ reverse([1,2])         // pop 2, store it
            └─ reverse([1])       // pop 1, store it
                └─ reverse([])    // base case -> returns []

Unwind phase (each unwind calls insertatbottom):
reverse([]) returns []
insertatbottom([], 1):
    └─ base case: push(1) -> [1]

insertatbottom([1], 2):
    pop 1, store temp=1
    └─ insertatbottom([], 2)
        └─ base case: push(2) -> [2]
    push(1) back -> [2,1]

insertatbottom([2,1], 3):
    pop 1, store temp=1
    └─ insertatbottom([2], 3)
        pop 2, store temp=2
        └─ insertatbottom([], 3)
            └─ base case: push(3) -> [3]
        push(2) back -> [3,2]
    push(1) back -> [3,2,1]

insertatbottom([3,2,1], 4):
    pop 1, store temp=1
    └─ insertatbottom([3,2], 4)
        pop 2, store temp=2
        └─ insertatbottom([3], 4)
            pop 3, store temp=3
            └─ insertatbottom([], 4)
                └─ base case: push(4) -> [4]
            push(3) back -> [4,3]
        push(2) back -> [4,3,2]
    push(1) back -> [4,3,2,1]

insertatbottom([4,3,2,1], 5):
    pop 1, store temp=1
    └─ insertatbottom([4,3,2], 5)
        pop 2, store temp=2
        └─ insertatbottom([4,3], 5)
            pop 3, store temp=3
            └─ insertatbottom([4], 5)
                pop 4, store temp=4
                └─ insertatbottom([], 5)
                    └─ base case: push(5) -> [5]
                push(4) back -> [5,4]
            push(3) back -> [5,4,3]
        push(2) back -> [5,4,3,2]
    push(1) back -> [5,4,3,2,1]

Final result: [5,4,3,2,1] (1 at top)
```

Notes:
- `reverse()` makes n+1 calls to pop all elements.
- `insertatbottom()` is called n times, each with increasing stack size.
- Each `insertatbottom(stack, value)` call recurses to the bottom of the stack.
- Overall time complexity: O(n²) due to nested recursion.