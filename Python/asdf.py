"""===========================================
파일이름 : asdf.py
함수기능 : gcc컴파일러를 사용시 실행파일 이름과 옵션을 넣기 귀찮아서 만듬...
최종수정 : 2017-09-14
copyright ⓒ 2017 S.W.Yang All Rights Reserved
==========================================="""
import sys, os

if(len(sys.argv) is 1):
    print("###--- make by S.W.yang ---###")
    os.system("gcc")

elif(sys.argv[1] == "-v"):
    os.system("gcc -v")

elif(sys.argv[1] == "pp"):
    name = sys.argv[2][:-4]
    os.system("g++ -o %s %s" %(name, sys.argv[2]))

elif(sys.argv[1] == "++"):
    name = sys.argv[2][:-4]
    os.system("c++ -o %s %s" %(name, sys.argv[2]))

else:
    name = sys.argv[1][:-2]
    os.system("gcc -o %s %s" %(name, sys.argv[1]))
