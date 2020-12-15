def Sum(array):
        s = 0
        for i in range(array):
                s = s+i
        return s

def Multiply(array):
        m = 0
        for i in range(array):
                m = m*i
        return m

array = []
num = int(input())
for i in range(num):
        array.append(int(input()))

print(Sum(array))
print(Multiply(array))
