# cook your dish here
n = int(input())
while(n > 0):
    s = input()

    if("M" not in s):
        print("NO")
    elif("C" not in s):
        print("NO")
    elif("P" not in s):
        print("NO")
    
    else:
        print("YES")
    
    n -= 1
