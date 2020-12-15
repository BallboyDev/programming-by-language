strg = list(input().upper())
max = 0
state = ""
for i in set(strg):
    if(max < strg.count(i)):
        max = strg.count(i)
        state = "%s" % i
    elif(max == strg.count(i)):
        state = "?"

print(state)
