def strReverse(a):
    lst = [a[i] for i in range(len(a))]
    lst.reverse()
    return "".join(lst)
