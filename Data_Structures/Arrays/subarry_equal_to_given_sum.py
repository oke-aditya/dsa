def solve(l, n, s):
    i = 1
    curr_sum = l[0]
    start = 0
    while(i<=n):
        while(curr_sum > s and start<i-1):
            curr_sum = curr_sum - l[start]
            start += 1
        
        if(curr_sum == s):
            print("%d %d" %(start+1, i))
            return
        
        if i<n:
            curr_sum += l[i]
        
        i += 1
        
    print("-1")
    return

t = int(input())
while(t>0):
    n, s = map(int, input().split())
    l = list(map(int, input().split()))
    
    solve(l, n, s)
    
    t -= 1
