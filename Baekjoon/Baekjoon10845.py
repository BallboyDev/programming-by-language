lst = []
for _ in range(int(input())):
    order = input()
    if(order.count("push")):
        num = order.split()[1]
        lst.append(num)

    elif(order.count("pop")):
        if(not len(lst)):
            print(-1)
            continue
        print(lst.pop(0))

    elif(order.count("size")):
        print(len(lst))

    elif(order.count("empty")):
        if(len(lst)): print(0)
        else: print(1)

    elif(order.count("front")):
        if(len(lst)): print(lst[0])
        else: print(-1)

    elif(order.count("back")):
        if(len(lst)): print(lst[len(lst)-1])
        else: print(-1)
