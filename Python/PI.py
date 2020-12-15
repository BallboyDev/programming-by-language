import random
import turtle as t
'''
def cir():
        t.begin_fill()
        t.circle(2)
        t.end_fill()

t.shape()
t.speed(10)
t.ht()

t.up()
t.goto(200, 0)
t.down()
t.goto(-200, 0)
t.up()
t.goto(0, 200)
t.down()
t.goto(0, -200)
t.up()
t.home()
t.fillcolor('Red')
'''
count = 0

for i in range(10000000):
        x = random.random()
        y = random.random()
        if(x*x+y*y < 1):
                count = count + 1
                #t.goto(100 * x, 100 * y)
                #cir()
	
print(4*float(count)/10000000)
