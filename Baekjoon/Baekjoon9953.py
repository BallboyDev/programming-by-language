a = input()
b = input()
while(a.count(b) != 0):
        a = a.replace(b, "")

if len(a) != 0:
    print(a)
else:
    print('FRULA')
