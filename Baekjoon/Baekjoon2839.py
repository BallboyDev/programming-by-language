a = int(input())
n=0
while(1):
    if(a%5 == 0):
        print((a/5)+n)
        break
    elif(a==1 or a==2):
        print(-1)
        break
    else:
        a=a-3
        n = n + 1
