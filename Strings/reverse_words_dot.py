t = int(input())
while(t>0):
    s = input()
    revstring = ''
    l1 = s.split('.')
    for i in l1:
        revstring += i[::-1] + "."
    print(revstring[:-1])
    t -= 1
