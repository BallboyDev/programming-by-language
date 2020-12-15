import time
print("범위를 입력하세요 : ", end = " ")
k = int(input())
print(2, end = ' ')
a = time.time()
for i in range(3, k):
    for j in range(2, i):
        if i % j == 0:
            break
    if(i - 1 == j):print(i, end = ' ')
b = time.time()
print("\n걸린시간은 : %f 입니다."% (b - a))
