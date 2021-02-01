
# Program and an example of dp to Fibonacci

# We know that f(n) = f(n - 1) + f(n - 2)

# Given a number n, print n-th Fibonacci Number.

import math

def fib(n : int): 
    phi = 1 + math.sqrt(5) / 2
    return round(math.pow(phi, n) / sqrt(5))

def fib_rec(n : int):
    if(n <= 1):
        return n
    else:
        return fib_mem(n - 1) + fib_mem(n - 2)

def fib_itr(n : int):
    fib_arr = [-1] * (n + 2)
    fib_arr[0] = 0
    fib_arr[1] = 1

    for i in range(2, n+1):
        fib_arr[i] = fib_arr[i - 1] + fib_arr[i - 2]

    return fib_arr[n]

if __name__ == "__main__":
    n = 9
    # print(fib_mem(n))
    print(fib_itr(n))

