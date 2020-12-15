h, m, s = map(int, input().split())
time = int(input())

temp = time // 3600
h += temp
temp = (time % 3600) // 60
m += temp
temp = ((time % 3600) % 60)
s += temp
if(s >= 60):
	m += s // 60
	s = s % 60
if(m >= 60):
	h += m // 60
	m = m % 60
if(h >= 24):
	h = h % 24
	
print(h, m, s)