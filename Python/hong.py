try:
	a=10/0
except:
	print("1.[exception] divided by zero")
	
print("\n")

try:
	a=10/0
	print("value of a: ",a)
except ZeroDivisionError:
	print("2[exception] divided by zero")
	
print("\n")

try:
	a=10
	b="a"
	c=a/b
except (TypeError, ZeroDivisionError):
	print("3.[exception] type error occurred")
else:
	print("4.type is proper")
finally:
	print("5.end of test program")
	print(c)
