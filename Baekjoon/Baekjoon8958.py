def fun():
	a = input().split('X')
	sum = 0

	for i in range(len(a)):
		for j in range(len(a[i])):
			sum = sum + j + 1
		
	return sum
	
num = int(input())
for i in range(num):
	print(fun())