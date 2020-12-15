f = open("새파일.txt", 'r')
lines = f.readlines()
for line in lines:
	print(line)
f.close()
num = input()