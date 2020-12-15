# -*- coding: utf-8 -*-
coffee = 10
while True:
	money = int(raw_input("give me a money : "))
	if money == 300:
		print("take out coffee")
		coffee = coffee - 1
	elif money > 300:
		print("money %d, take out coffee" %(money - 300))
		coffee = coffee -1
	else:
		print("get out of here")
		print("out coffee %d" %coffee)
	if not coffee:
		print("no coffee, sold out")
		break