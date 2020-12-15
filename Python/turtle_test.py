import turtle as t

t.shape("turtle")

angle = 57
t.bgcolor("black")
t.color("green")
t.speed(10)
x = 0
for i in range(400):
#while True:
    t.forward(x)
    t.left(angle)
    x = x + 1

t.hideturtle()
