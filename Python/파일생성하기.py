#writedata.py
f = open("D:\문서자료\프로그래밍\python\새파일.txt", 'w')
for i in range(1, 100):
	data = "%d번째 줄입니다. \n" %i
	f.write(data)
f.close()