#adddata.py
f = open("새파일.txt",'a')
for i in range(11, 20):
	data = "%d번째 줄입니다.\n"%id
	f.write(data)
f.close()
num = input()