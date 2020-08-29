# Say you have an array for which the ith element is the price of a given stock on day i.

# If you were only permitted to complete at most one transaction (i.e., buy one and sell one share of the stock), 
# design an algorithm to find the maximum profit.

# Note that you cannot sell a stock before you buy one.

# Example 1:

# Input: [7,1,5,3,6,4]
# Output: 5
# Explanation: Buy on day 2 (price = 1) and sell on day 5 (price = 6), profit = 6-1 = 5.
#              Not 7-1 = 6, as selling price needs to be larger than buying price.


# Example 2:

# Input: [7,6,4,3,1]
# Output: 0
# Explanation: In this case, no transaction is done, i.e. max profit = 0.

from typing import List

def maxProfit_nv(prices: List[int]) -> int:
    max_diff = -1
    n = len(prices)

    for i in range(n-1):
        for j in range(i+1, n):
            diff = prices[j] - prices[i]
            max_diff =  max(max_diff, diff)
    
    if(max_diff < 0):
        return 0
    
    else:
        return max_diff

def maxProfit_opt(prices: List[int]) -> int:
    # Check if the length of prices is 0
    if len(prices) == 0: 
        return 0
    
    # Check if the length is less than 2 (So, it would have at least 2 ints in the list)
    if len(prices) < 2: 
        return max(prices) - min(prices)
    
    # Setting the minimum value to the initial value in the list and the max_profit to 0
    min_value, max_profit = prices[0], 0
    
    # Iterating over the list
    for price in prices:

        # If the price is less than the min_value we want to replace the min_value
        if price < min_value:
            min_value = price
        
        # Check if the price - min_value is greater than the max_profit
        elif (price - min_value) > max_profit:
            max_profit = (price - min_value)
    
    return max_profit
    
if __name__ == "__main__":
    prices = [7,1,5,3,6,4]
    prices = [7,6,4,3,1]
    # prices = [1,2]

    print(maxProfit_nv(prices))
    
