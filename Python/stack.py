num = int(input())
stack = []
for i in range(num):
	order = input()
	if(order.count("push")):
			num = order.split()[1]
			stack.append(num)
            
	elif(order.count("pop")):
			if(not len(stack)):
				print(-1)
				continue
			print(stack.pop())
            
	elif(order.count("size")):
			print(len(stack))
            
	elif(order.count("empty")):
			if(len(stack)): print(0)
			else: print(1)
            
	elif(order.count("top")):
			if(len(stack) == 0):
				print(-1)
			else:
				print(stack[len(stack)-1])