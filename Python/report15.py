def sum2(n):
    if n == 1:
        return 1
    else:
        return 1/n + sum2(n-1)


n = int(input())
result = sum2(n)
print(result)
