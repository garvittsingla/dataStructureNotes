# Sort a array using recursion

## Intuition
To sort a array using recursion , we can just make the array shorted and shorter untill we reach the base case and always store the element that we are going to delete everytime.

## Approach
1. Make a function that takes array as input and checks if the array size is empty or not , when found empty the array and also insert the last element at its correct position. 

2. To insert the last element at its correct position make another function that takes the array and the element to be inserted as input and checks if the last element of the array is greater than the element to be inserted , if yes pop the last element and call the function again until we find the correct position to insert the element.

## code 
```c++
#include<bits/stdc++.h>

using namespace std;
vector<int> insert(vector<int> &arr,int temp){
    if(arr.size() == 0 || arr.back() <= temp){
        arr.push_back(temp);
        return arr;
    }

    int value = arr.back();
    arr.pop_back();
    arr = insert(arr,temp);
    arr.push_back(value);
    return arr;
}
vector<int> mysort(vector<int> &arr){
    if(arr.size() == 0){
        return arr;
    }
    int last = arr.back();
    arr.pop_back();
    arr = mysort(arr);
    arr = insert(arr,last);
    return arr;
}
int main(void){
    vector<int> arr = {5,4,3,2,1};
    mysort(arr);
    for(auto x:arr){
        cout<<x<<" ";
    }
    return 0;
}
```

## Recursion tree

Call sequence for arr = [5,4,3,2,1]

```
mysort([5,4,3,2,1])          // last = 1
└─ mysort([5,4,3,2])         // last = 2
    └─ mysort([5,4,3])       // last = 3
        └─ mysort([5,4])      // last = 4
            └─ mysort([5])     // last = 5
                └─ mysort([])   // base -> returns []

Unwind (each unwind calls insert):
mysort([]) returns []
insert([],5)          -> [5]
insert([5],4)         -> [4,5]
insert([4,5],3)       -> [3,4,5]
insert([3,4,5],2)     -> [2,3,4,5]
insert([2,3,4,5],1)   -> [1,2,3,4,5]

Final result returned to top: [1,2,3,4,5]
```

Notes:
- mysort makes n+1 calls (including base).
- insert is called for each popped element and may recurse up to current length -> overall time O(n^2).