for _ in range(int(input())):
    lst = list(input())
    num = 0
    a = []
    for i in range(len(lst)):
        if(lst[i] == "<"):
            if(num > 0):
                num = num - 1

        elif(lst[i] == ">" and num < len(lst)):
            num = num + 1

        elif(lst[i] == "-"):
            del a[num - 1]
            num = num - 1

        else:
            a.insert(num, lst[i])
            num = num + 1

        print(a, num)
