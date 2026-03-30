# Heaps
Heap is a complete binary tree based data structure
> Nodes always are aligned/added from the left

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
Taking a node to its correct index is the work of this algo
