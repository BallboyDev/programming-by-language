"""============================================
파일이름 : stack_bin.py
함수기능 : 스택을 활용한 10진수를 2진수로 변환 프로그램
최종수정 : 2016-11-29
copyright ⓒ 2016 S.W.Yang All Rights Reserved
============================================"""
def push(a):
	stack.append(a)

stack = []	
a = int(input())
while(a != 0):
    push(a%2)
    a = a // 2
stack.reverse()
for i in stack:
        print(i, end = '')
