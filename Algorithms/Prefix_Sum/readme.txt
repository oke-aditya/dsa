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

2D Prefix Sum Problems

Sometime we see problems where we have to do some operations on sub-matrix, like finding max/min in range of matrix or sum.
We use prefix in two dimensional way to find them.

There are two operatiosn : compute prefix sum at next cell (r,c) and also get operation(like sum) between (r1 ,c1) & (r2, c2)

Lets see with an example

Compute psum

psum[i][j] = psum[i-1] [j] + psum[i] [j-1]

if you notice that component [i-1][j-1] is added twice, so we will reduce one part.

psum[i][j] = psum[i-1] [j] + psum[i] [j-1] - psum [i-1][j-1]

and finally add current element.

psum[i+1][j+1] = psum[i+1] [j] + psum[i] [j+1] - psum[i][j] + arr[i][j]


