def Rev(k):
	if(int(k) < 100):
		if(int(k) < 10):
			k = '00' + str(k)
		else:
			k = '0' + str(k)
	return ''.join(reversed(k))

a, b = map(str, input().split())
print(Rev(str(int(Rev(a)) + int(Rev(b)))))