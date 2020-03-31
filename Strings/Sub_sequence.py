t = int(input())
while(t > 0):
    string1, string2 = map(str, input().split())
    index = 0
    for i in range(len(string2)):
        if(string2[i] == string1[index]):
            index += 1
            if(index == len(string1)):
                print("1")
                break
    else:
        print("0")
    t -= 1
