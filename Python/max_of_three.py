"""============================================
파일이름 : max_of_three.py
함수기능
세 개의 숫자를 받아 큰 수를 반환하는 
max_of_three 함수를 만들어라.
(if문만 이용해 만들어볼 것)
최종수정 : 2016-11-26
copyright ⓒ 2013 S.W.Yang All Rights Reserved
============================================"""

a, b, c = map(int, input().split())

if(a > b):
	if(b > c):
		print(a)
	elif(a < c):
		print(c)
	else:
		print(a)
else:
	if(a > c):
		print(b)
	elif(b < c):
		print(c)
	else:
		print(b)