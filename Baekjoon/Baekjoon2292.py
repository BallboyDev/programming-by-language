num = int(input())
i = 1
sum = 0

while True:
	if sum > num:
		print(i)
		break
	elif num == 1:
		print(1)
		break
	else:
		sum = sum + (i * 6)
		i = i + 1