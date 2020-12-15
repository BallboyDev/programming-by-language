def trisum(lst, n, m):
    if(n == 0 and m == 0): return lst[0][0] #루트 노드
    elif(m == n): return lst[n][n] + lst[n-1][n-1]  # 최 우측 노드
    elif(m == 0): return lst[n][0] + lst[n-1][0]    # 최 좌측 노드
    else: return lst[n][m] + (lst[n-1][m-1] if lst[n-1][m-1] > lst[n-1][m] else lst[n-1][m])
        # 나머지 노드
        
lst = [input().split() for _ in range(int(input()))]

for n in range(len(lst)):
    for m in range(n+1):
        lst[n][m] = int(lst[n][m])
        lst[n][m] = trisum(lst, n, m)
print(max(lst[len(lst)-1]))
