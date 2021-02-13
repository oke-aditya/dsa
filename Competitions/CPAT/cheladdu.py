from typing import List

def find_min(l: List, n, k):
    res = 10_00_00_00
    l.sort()

    for i in range(n - k - 1):
        curr_diff = l[i + k - 1] - l[i]
        res = min(curr_diff, res)

    return res;


t = int(input())
while(t > 0):
    n, k = map(int, input().split())
    l = list(map(int, input().split()))

    if(k == 1):
        print(0)
    else:
        res = find_min(l, n, k)
        print(res)
    
    t -= 1

