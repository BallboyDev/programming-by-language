a = input()
lst = [a.count(str(i)) for i in range(1, 9)]
if(int((a.count('6') + a.count('9') + 0.5)/2) > max(lst)):
    print(int((a.count('6') + a.count('9') + 0.5)/2))
else: print(max(lst))
