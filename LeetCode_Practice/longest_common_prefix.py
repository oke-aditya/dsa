# Write a function to find the longest common prefix string amongst an array of strings.

# If there is no common prefix, return an empty string "".

# Input: ["flower","flow","flight"]
# Output: "fl"

# Input: ["dog","racecar","car"]
# Output: ""
# Explanation: There is no common prefix among the input strings.

from typing import List

if __name__ == "__main__":
    prefix_l = ["flower","flow","flight"]
    prefix = longestCommonPrefix(prefix_l)
    print(prefix)
