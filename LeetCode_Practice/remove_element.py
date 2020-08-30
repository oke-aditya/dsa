# Remove elements in place from an array

# Given an array nums and a value val, remove all instances of that value in-place and return the new length.


# Given nums = [3,2,2,3], val = 3,

# Your function should return length = 2, with the first two elements of nums being 2.

# It doesn't matter what you leave beyond the returned length.

# Given nums = [0,1,2,2,3,0,4,2], val = 2,

# Your function should return length = 5, with the first five elements of nums containing 0, 1, 3, 0, and 4.

# Note that the order of those five elements can be arbitrary.

# It doesn't matter what values are set beyond the returned length.

from typing import List

def remove_element(nums: List[int], val: int) -> int:
    # Keep a fast pointer and a slow pointer.
    # where i is the slow-runner while j is the fast-runner.
    # When nums[j] equals to the given value,
    # skip this element by incrementing j.
    # If the value is not equal copy it to ith position.
    # Repeat the process until j reaches the end of the array and the new length is i.
    
    i = 0
    for j in range(len(nums)):
        if(nums[j] != val):
            nums[i] = nums[j]
            i += 1
    
    return i, nums

if __name__ == "__main__":
    nums = [3,2,2,3]
    val = 3
    ln, nums = remove_element(nums, val)
    print(ln)
    print(nums[: ln])
