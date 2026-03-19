# Difference Array technique

Imagine we are given a array, and we need to update a range from a start index to a end index.This can be easily visualized by a problem saying update the sum from a start to end index. 
So brute force would be go in each range and perform the operation and then giving the final resultant to finally give  O(n*m) Time complexity.
> The solution is pretty simple , just add the number at start and subtract that number at end -1 , and take a cummilative sum at the end 

## Why this works?
Visualize a bullet coming from start of the array and we have to cancel the bullets effect at end so we fire bullet with same velocity from end+1 index.


