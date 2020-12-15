"""============================================
파일이름 : max_of_two.py
함수기능
두 개의 숫자를 받아 큰 수를 반환하는 
#max_of_two 함수를 만들어라.
최종수정 : 2016-11-26
copyright ⓒ 2013 S.W.Yang All Rights Reserved
============================================"""

a, b = map(int, input().split())

if(a > b):
	print(a)
else:
	print(b)