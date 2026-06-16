```c
/*
 * Core Idea: Calculates the sum of all elements in a given integer array.
 *
 * Time Complexity: O(N), where N is the number of elements in the array, as it iterates through each element once.
 *
 * Space Complexity: O(1), as it uses a constant amount of extra space for the sum variable.
 */
int sumArray(int arr[], int n) {
    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    return sum;
}
```