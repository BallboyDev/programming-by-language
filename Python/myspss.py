"""===========================================
파일이름 : myspss.py
함수기능 : 간단한 설문조사 통계 프로그램
최초개발 : 2016/11/23
최종수정 : 2017/12/10
개 발 자 : Franciscus S.W.Yang
Copyleft ○ 2018 All Wrongs Reserved
==========================================="""

from tkinter import *

def manual():
    print("Make by S.W.Yang")
    print("Copyleft ○ 2018 All Wrongs Reserved\n")
    print("### 사용방법 ###")
    print("1. 설문지의 문항수와 각 문항중 최대 선택지를 입력한다.")
    print("2. 문항 체크칸에 설문지와 동일하게 체크한다.")
    print("3. 설문지를 더 입력할려면 Next버튼을 누른다.")
    print("4. 설문지 입력을 종료할려면 Finish버튼을 누른다.")
    print("5. 최종적으로 출력되는 설문지 종합 내용을 확인한다.\n")
    print("※ 기타 건의사항은 제작자에게 건의하지마세요")
    print("   프로그램 수정하기 귀찮습니다.(불편하면 직접 만들어 쓰던가.....)\n")
    print("1차 개발 - 2016/11/23 -")
    print("개발 언어 : C")
    print("DOS창을 이용한 텍스트 기반 설문조사 통계프로그램\n")
    print("2차 수정 - 2017/12/10 -")
    print("개발 언어 : Python3")
    print("Tkinter라이브러리를 이용한 GUI 개선\n")
    print("이 프로그램을 조교선생님께 바칩니다.")

def test():
    global state
    state= 0
    root.destroy()  

def retry():
    print("retry")


manual()

s = input("\n프로그램을 실행 하시겠습니까?(y/n) : ")

if(s == "n"):
    quit()
root = Tk()
root.geometry("200x200+600+100")
root.title("설문조사 통계 프로그램 ver.2")
'''
F = Frame(root)
F.config(width = 400, height = 300)
F.pack()
'''
Label(root, text = "문항 수").pack()
question = IntVar()
Entry(root, textvariable = question).pack()

Label(root, text = "최대 선택지 수").pack()
select = IntVar()
Entry(root, textvariable = select).pack()

Button(root, text = "OK", width = 15, command = root.destroy).pack()
root.mainloop()

# ======================== #

btn = [[0] * select.get() for i in range(question.get())]




state = 1
num = 0

while(state):
    root = Tk()
    root.title("설문조사 통계 프로그램 ver.2")
    num = num + 1
    ch = [[0] * select.get() for i in range(question.get())]
    
    for i in range(question.get()):
        Label(root, text = "%d 문항" %(i + 1)).grid(row = i + 2, column = 0)
        for j in range(select.get()):
            ch[i][j] = IntVar()
            Checkbutton(root, text = j+1, width = 7, variable = ch[i][j], onvalue = 1, offvalue = 0).grid(row = i + 2, column = j + 1)
    Button(root, text = "Finish", width = 7, bg = "red", command = test).grid(row = i + 3, column = 0)
    Label(root).grid(row = 1)
    Label(root, text = "설문지 %d 장 입력중입니다." %num).place(x = 0)
    Button(root, text = "Next", width = 7, bg = "green", command = root.destroy).grid(row = i + 3, column = j+1)
    
    root.mainloop()
    
    for i in range(question.get()):
        for j in range(select.get()):
            btn[i][j] = btn[i][j] + ch[i][j].get()

root = Tk()
root.title("설문조사 통계 프로그램 ver.2")

for i in range(question.get()):
    Label(root, text = "%d 문항" %(i + 1)).grid(row = i + 1, column = 0)
    for j in range(select.get()):
        Label(root, text = btn[i][j], width = 7).grid(row = i + 1, column = j + 1)
Label(root, text = "총 입력된 설문지 : %d" %num).grid(row = i + 2, column = 0)
root.mainloop()
