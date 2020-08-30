# Complete the sockMerchant function below.
def sockMerchant(n, arr):
    val_arr = [0] * (max(arr) + 1)
    for x in arr:
        val_arr[x] += 1
    
    # print(val_arr)

    pairs = 0
    for x in val_arr:
        pairs = pairs + (x // 2)

    return pairs