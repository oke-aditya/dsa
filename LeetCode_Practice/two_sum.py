# Given an array of integers nums and and integer target, return the indices of the two numbers such that they add up to target.

# You may assume that each input would have exactly one solution, and you may not use the same element twice.

# You can return the answer in any order.

# Input: nums = [2,7,11,15], target = 9
# Output: [0,1]
# Output: Because nums[0] + nums[1] == 9, we return [0, 1]

# Input: nums = [3,2,4], target = 6
# Output: [1,2]

# Input: nums = [3,3], target = 6
# Output: [0,1]

# Time complexity Expected = O(n)

from typing import List

def solution(nums: List[int], target: int) -> List[int]:
    lookup = {}
    for cnt, num in enumerate(nums):
        if target - num in lookup:
            return lookup[target - num], cnt
        
        lookup[num] = cnt


if __name__ == "__main__":
    nums = [2, 7, 11, 15]
    target = 9
    print(solution(nums, target))
