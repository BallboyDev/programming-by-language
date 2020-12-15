def sum(num):
	a = num // 10
	b = num % 10
	if(a + b >= 10):
		a = (a+b)%10
	else:
		a = a+b
	return (10 * b + a)

i, rst = 0, -1
rst = num = int(input())
while(1):
	num = sum(num)
	i+=1
	if(rst == num):
		break

print(i)