Given an integer array of size n. Elements of the array is >= 0. Starting from arr[startInd], follow each element to the index it points to. Find a cycle and return its length. No cycle is found -> -1.

```
int lengthOfCycle(int[] arr, int startIndex) {
	// todo
}
```

Examples:
lengthOfCycle([1, 0], 0); // 2
lengthOfCycle([1, 2, 0], 0); // 3
lengthOfCycle([1, 2, 3, 1], 0); // 3