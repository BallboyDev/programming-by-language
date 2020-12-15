def fun():
	num, s = map(str, input().split())
	for i in range(len(s)):
		for j in range(int(num)):
			print(s[i], end="" )
			
num = int(input())
for i in range(num):
	fun()
	print()