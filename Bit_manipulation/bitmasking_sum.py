# cook your dish here
t = int(input())
while(t > 0):
    fg = 0
    l = list(map(int, input().split()))
    for i in range(1, 16):
        binary_mask = bin(i)[2:].zfill(4)
        sum_= 0
        for nu, ms in zip(l, binary_mask):
            if(ms == '1'):
                sum_ += nu

        if(sum_ == 0):
            fg = 1
            break

    if(fg == 1):
        print("Yes")
    else:
        print("No")
    t -= 1
