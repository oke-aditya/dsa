def reverse(arr, start, end):
    while(start < end):
        arr[start], arr[end] = arr[end], arr[start]
        start += 1
        end -= 1
    return arr

t = int(input())
while(t>0):
    n, d = map(int, input().split())
    arr = list(map(int, input().split()))
    arr = reverse(arr, 0, d-1)
    arr = reverse(arr, d, n-1)
    arr = reverse(arr, 0, n-1)
    for i in range(len(arr)):
        print(arr[i], end=' ')
    print()
    t -= 1
