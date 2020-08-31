from typing import List

# Input: nums = [1,2,3,4,5,6,7], k = 3
# Output: [5,6,7,1,2,3,4]
# Explanation:
# rotate 1 steps to the right: [7,1,2,3,4,5,6]
# rotate 2 steps to the right: [6,7,1,2,3,4,5]
# rotate 3 steps to the right: [5,6,7,1,2,3,4]

# Input: nums = [-1,-100,3,99], k = 2
# Output: [3,99,-1,-100]
# Explanation: 
# rotate 1 steps to the right: [99,-1,-100,3]
# rotate 2 steps to the right: [3,99,-1,-100]

def reverse_arr(nums: List[int], start: int, end: int):
    """
    Reverse only from start to end elements of array
    """
    while(start < end):
        nums[start], nums[end] = nums[end], nums[start]
        start += 1
        end -= 1

    return nums

def rotate(nums : List[int], k : int) -> None:
    """
    Modify inplace
    """
    n = len(nums)
    k %= n

    nums = reverse_arr(nums, 0, n-1)
    nums = reverse_arr(nums, 0, k-1)
    nums = reverse_arr(nums, k, n-1)
    print(nums)

def rotate_append(nums : List[int], k : int) -> None:
    '''
    Creates new array and pushes to it.
    '''
    temp = []
    for i in range(k+1, len(nums)):
        temp.append(nums[i])
    
    for i in range(0, k+1):
        temp.append(nums[i])
    
    print(temp)
    # return temp


if __name__ == "__main__":
    nums = [1,2,3,4,5,6,7]
    k = 3
    # rotate(nums, k)
    rotate_append(nums, k)
    
