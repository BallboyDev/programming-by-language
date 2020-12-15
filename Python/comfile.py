import sys, os

f = open("test.txt", 'r')
ferr = open("err.txt", 'w')
lines = f.readlines()

for line in lines:
    print(line)
    print(line[:-3])
    line2 = line[:-3] + "_m"
    err = os.system("gcc -o %s %s"%(line2, line))
    if(err != 0):
        f.write(line + "\n")

f.close()