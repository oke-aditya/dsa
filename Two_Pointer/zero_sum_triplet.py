from typing import List

def findTripletsBrute(arr: List[int], n: int) -> bool:
    found = False
    for i in range(n-2):
        for j in range(i+1, n-1):
            for k in range(j+1, n):

                if(arr[i] + arr[j] + arr[k] == n):
                    found = True
                    return found
    
    return found


def findTripletHash(arr: List[int], n: int) -> bool:
    found = False
    for i in range(n - 1):
        s = set()
        for j in range(i+1, n):
            x = -(arr[i] + arr[j])
            if x in s:
                found = True
                return found
            else:
                s.add(arr[j])
    
    return found



if __name__ == "__main__":      
    # Driver code 
    arr = [0, -1, 2, -3, 1] 
    n = len(arr) 
    
    findTripletsBrute(arr, n) 