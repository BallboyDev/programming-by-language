for _ in range(int(input())):
    vps = input()
    while True:
        vps = vps.replace("()", "")
        if(not len(vps)):
            print("YES")
            break
            
        elif(vps == vps.replace("()", "")):
            print("NO")
            break
