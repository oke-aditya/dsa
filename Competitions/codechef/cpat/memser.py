t = int(input())
while(t > 0):
    n = int(input())

    commands = list(map(str, input().split()))
    status = 0
    flag = 0

    for comm in commands:
        if(comm == "start"):
            if(status == 0):
                status = 1
            else:
                print("404")
                flag = 1
                break

        elif(comm == "restart"):
            if(status == 0):
                status = 1

        elif(comm == "stop"):
            if(status == 0):
                print("404")
                flag = 1
                break
            else:
                status = 0
    
    if(flag == 0):
        print("200")

    t -= 1

