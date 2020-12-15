word = input()
for i in range(len(word)):
	if(word[i] == 'A' or word[i] == 'B' or word[i] == 'C'):
		print(chr(ord(word[i]) + 23), end = '')
	else:
		print(chr(ord(word[i]) - 3), end = '')