#-*- coding: utf-8 -*-
"""============================================
파일이름 : alpha.py
함수기능 : 알파벳 캐릭터 하나를 인자로 받아 모음이면 True, 자음이면 False를 반환하는 함수를 만들어라
최종수정 : 2016-11-28
copyright ⓒ 2016 S.W.Yang All Rights Reserved
============================================"""

import sys
a = input()

array = {'a', 'e', 'i', 'o', 'u'}

for i in array:
	if i == a:
		print(True)
		sys.exit()

print(False)
