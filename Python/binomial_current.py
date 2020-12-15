def binomial_current(n,k):
    if k == 0 or k == n:
        return 1
    else:
        tmp1 = 1
        tmp2 = 1
        for i in range(1, n - k+1):
            tmp1 *= (i + k)
            tmp2 *= i
            tmp = tmp1/tmp2
            #print(tmp, end = '\n')
        return tmp

n, k = map(int, input().split(" "))
tmp = int(binomial_current(n, k))
print (tmp)
