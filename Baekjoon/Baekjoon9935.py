a = input()
b = input()

while True:
    a = a.replace(b, "")
    if(not len(a)):
        print("FRULA")
        break

    elif(a == a.replace(b, "")):
        print(a)
        break
