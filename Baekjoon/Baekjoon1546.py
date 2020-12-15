num = float(input())
score = list(map(int, input().split()))
print(round((sum(score)*100)/(num*max(score)),2))
