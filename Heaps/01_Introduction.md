# Heaps
Heap is a complete binary tree based data structure
> Nodes always are aligned/added from the left


## Time complexity
It gives the smallest or the largest element in O(1) time
We want the root to be max, but the remaining array can be unsorted as well
To add a element , the worst time will be O(logN)
To make a heap it and every element in a array , TC is O(logN)
<!-- TODO: what is heapify? --> O(N)

## Types of heap
1. Max heap -> Child always smaller than parent
2. Min heap -> Child always greater than parent

## Insertion in heap
> If we use array to depict the data structure
Some important points:
1. Node -> ith index
2. left child -> 2*ith index
3. right child -> 2*ith index + 1 
4. Parent -> i/2th index

### Insertion in max heap
- find the parent of the node, check if it is smaller , if yes just swap it
### Deletion in max heap
- Swap the last node with the first one, then heapify

## Heapify algorithm
Taking a node to its correct index is the work of this algo on a existing array
