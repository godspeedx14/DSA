```python
'''
Core idea: This function finds the maximum product of any three numbers within a given list. It handles both positive and negative numbers by considering two main scenarios: the product of the three largest numbers, and the product of the two smallest (most negative) numbers with the largest positive number.

Time complexity: O(n log n) due to sorting the input list. If sorting is not counted (e.g., an external sort is assumed or another approach is used), then it would be O(n) for finding min/max elements.
Space complexity: O(n) or O(log n) depending on the sorting algorithm used. Python's `list.sort()` is Timsort, which can take O(n) space in the worst case, or O(log n) for typical cases.
'''
import math

class Solution:
    def maximumProduct(self, nums: list[int]) -> int:
        nums.sort()
        n = len(nums)

        # Case 1: Product of the three largest numbers (all positive or mixed, but overall largest)
        product1 = nums[n-1] * nums[n-2] * nums[n-3]

        # Case 2: Product of the two smallest (most negative) numbers and the largest positive number
        # This handles cases like [-100, -2, -1, 1, 2, 3] where (-100)*(-2)*3 is the max product
        product2 = nums[0] * nums[1] * nums[n-1]

        return max(product1, product2)

```