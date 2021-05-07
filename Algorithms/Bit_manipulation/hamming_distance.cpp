// Hamming Distance

// The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

// Given two integers x and y, return the Hamming distance between them.

// Input: x = 1, y = 4
// Output: 2
// Explanation:
// 1   (0 0 0 1)
// 4   (0 1 0 0)
//        ↑   ↑
// The above arrows point to positions where the corresponding bits are different.

// Example 2:

// Input: x = 3, y = 1
// Output: 1

// Solution: -
// The basic idea here is to discuss the usage of xor operator (^) ,and operator(&) and
// right shift operator(>>).When we take xor of two numbers the bits with
// same numbers become zero and with different numbers become 1.
// Then we can right shift all the 1's and use & to find the number of ones .


int hammingDistance(int x, int y)
{
    int z = x ^ y;
    int count = 0;
    while (z)
    {
        if(z & 1)
        {
            count += 1;
        }
        z >> 1;
    }
    
    return count;
}

