mycar = [[0,1,0],
         [1,1,1],
         [0,1,0],
         [1,0,1]]

car = [[0,0,0], # 0
       [0,0,0], # 1
       [0,0,0], # 2
       [0,0,0], # 3
       [0,1,0], # 4
       [1,1,1], # 5
       [0,1,0], # 6
       [1,1,1], # 7
       [0,0,0], # 8
       [0,0,0]] # 9

field = [[0,0,0,0,0,0,0,0,0], # 0
         [0,0,0,0,0,0,0,0,0], # 1
         [0,0,0,0,0,0,0,0,0], # 2
         [0,0,0,0,0,0,0,0,0], # 3
         [0,0,0,0,0,0,0,0,0], # 4
         [0,0,0,0,0,0,0,0,0], # 5
         [0,0,0,0,0,0,0,0,0], # 6
         [0,0,0,0,0,0,0,0,0], # 7
         [0,0,0,0,0,0,0,0,0], # 8
         [0,0,0,0,0,0,0,0,0], # 9
         [0,0,0,0,0,0,0,0,0], # 10
         [0,0,0,0,0,0,0,0,0], # 11
         [0,0,0,0,0,0,0,0,0], # 12
         [0,0,0,0,0,0,0,0,0], # 13
         [0,0,0,0,0,0,0,0,0], # 14
         [0,0,0,0,0,0,0,0,0]] # 15

import random, copy, time, os, threading

def map_print():
    block = '□'
    for i in range(16):
        for j in range(9):
            if(field[i][j] == 0):
                block = '□'
            else:
                block = '■'
            print(block, end = '')
        print(i, end = '')
        print()
    print(time.asctime(time.localtime(time.time())))
    #time.sleep(0.05)
    os.system('cls')

#=================== start =====================#

line = 9

while True:
    map_print()
    if(line == 9):
        pos = random.randint(0, 2)
    for i in range(14, -1, -1):
        field[i + 1] = copy.deepcopy(field[i])
        
    field[0][pos*3] = car[line][0]
    field[0][pos*3+1] = car[line][1]
    field[0][pos*3+2] = car[line][2]
        
    if(line == 0):
        line = 10
        
    line = line - 1
