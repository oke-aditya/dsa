t = int(input())
while(t>0):
    n = int(input())
    l = list(map(int, input().split()))
    dp = [1]
    
    for i in range(1, len(l)):
        if(l[i] >= l[i-1]):
            dp.append(dp[i-1] + 1)
        else:
            dp.append(1)
    
    print(sum(dp))
    t -= 1
