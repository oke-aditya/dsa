def printDuplicates(arr, n):
    fg = 0   
    for i in range(n): 
        arr[arr[i] % n] = arr[arr[i] % n] + n
       
    # print("The repeating elements are : "); 
    for i in range(n): 
        if (arr[i] >= n*2):  
            print(i, end=' ')
            fg = 1
    
    if(fg == 0):
        print(-1, end=' ')
