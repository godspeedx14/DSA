```python
# Core idea: Finds two numbers in a list that sum to a target using a hash map
#            to store previously seen numbers and their indices for efficient lookup.
# Time complexity: O(N) where N is the number of elements in 'nums', as each element
#                  is processed once with O(1) average time hash map operations.
# Space complexity: O(N) where N is the number of elements in 'nums', as in the worst case,
#                   the hash map stores all elements.
def two_sum(nums: list[int], target: int) -> list[int]:
    num_map = {}
    for i, num in enumerate(nums):
        complement = target - num
        if complement in num_map:
            return [num_map[complement], i]
        num_map[num] = i
    return []
```