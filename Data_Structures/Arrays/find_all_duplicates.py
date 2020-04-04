def printDuplicates(arr, n):
    fg = 1
    for i in range(len(arr)):
        ele = abs(arr[i])
        if(arr[ele] >= 0):
            arr[ele] *= -1
        else:
            print(abs(ele), end=' ')
            fg = 0
    
    if(fg == 1):
        print(-1, end=' ')
