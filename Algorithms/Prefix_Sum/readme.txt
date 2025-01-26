Prefix Sum

The trick here is to pre compute sum of all numbers left to right.
We will use this to answer repeated queries easily and not recompute.

Refer Errichto's lecture

https://www.youtube.com/watch?v=PhgtNY_-CiY&list=PLl0KD3g-oDOEbtmoKT5UWZ-0_JbyLnHPZ&index=19


Think of this as running total.

arr = [1, 2, 3, 4, 5]

sum = [0, 1, 3, 6, 10, 15]

we fill prefix sum with 0 to simplify a bit, prefix sum of 0th = 0

Hence we can fill remaining as 

sum[i] = arr[i-1] + sum[i-1];


How do we answer a range query now? 

Say we want sum between index 1, index 3. Sum between 2-4 == 9
L = 1, R = 3

We can easily do prefix: prefix[R + 1] - prefix[L]


Refer

https://leetcode.com/discuss/study-guide/5119937/prefix-sum-problems

