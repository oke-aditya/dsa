// https://leetcode.com/problems/maximum-swap/description/

// You are given an integer num. You can swap two digits at most once to get the maximum valued number.
// Return the maximum valued number you can get.

// Example 1:

// Input: num = 2736
// Output: 7236
// Explanation: Swap the number 2 and the number 7.

// Example 2:

// Input: num = 9973
// Output: 9973
// Explanation: No swap.

// Here is the general logic towards finding the best swap:
// We want to take a digit on the left, and swap it out with a digit on the right side of that digit that is greater than the digit on the left. 
// Because by definition we'll be replacing the digit on the right side with a digit that is smaller than it, 
// we want the digit on the right to be as far to the right as possible. In other words for something like "1818", 
// we could swap index 0 and index 1, giving us 8118. 
// However there is another 8 further to the right than the 8 at index 1, 
// so in actuality we should pick that one to minimize the effect that replacing the 8 with a 1 will have. 
// The best option is swap index 0 and index 3 for "8811".

// The more specific implementation of how to achieve that:

// Convert the digit to a string - iterate a variable 'i' from 0 to numString.Length.
// This 'i' variable will point to the current digit that we're considering swapping for something larger.
// Then iterate a variable 'j' from numString.Length - 1 to i, and ask two things:
// A. Is the character located at index j greater in value than the character located at index i?
// B. Is the character located at index j greater in value than the current largest character we've found to replace the char at index i?
// If both are true, we can save the index of that max character, 
// and have some boolean that will indicate that we've found a valid swap for char at index 'i

#include <string>
using namespace std;


class Solution {
public:
    int maximumSwap(int num) {
        string numstr = to_string(num);

        int max_idx = -1, max_digit = -1, left_idx = -1, right_idx = -1;

        // find the largest digit from back;
        for(int i=numstr.size() - 1; i>=0; i--) {
            if(numstr[i] > max_digit) {
                max_digit = numstr[i];
                max_idx = i;
            }

            // if it is smaller, then it is best candidate for swap
            if(numstr[i] < max_digit) {
                left_idx = i;
                right_idx = max_idx;
            }
        }

        if(left_idx == -1)
            return num;

        
        swap(numstr[left_idx], numstr[right_idx]);
        return stoi(numstr);

    }
};
