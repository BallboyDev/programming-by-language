def sum(lst):
    result = 0
    for i in range(len(lst)):
        result = lst[i] + result
    return result

def mul(lst):
    result = 1
    for i in range(len(lst)):
        result = lst[i] * result
    return result

n = int(input("리스트 입력 개수\n"))
lst = [int(input()) for _ in range(n)]

print("sum = ", sum(lst), ",mul = ", mul(lst))

