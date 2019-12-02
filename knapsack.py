m = int(input("enter knap size- "))

n = int(input("enter size- "))

p = [None] * n
w = [None] * n
pw = [None] * n
tick = [None] * n

for i in range(0,n):
	p[i],w[i] = input().split(' ', 2)
	pw[i] = int(p[i])/int(w[i])
	
for i in range(1,n):
	for j in range(0,n-i):
		if(pw[j] > pw[j+1]) :
			pw[j],pw[j+1] = pw[j+1],pw[j]
			p[j],p[j+1] = p[j+1],p[i]
			w[j],w[j+1] = w[j+1],w[j]

mm = m

for i in range(0,n):
	if(mm >= 0):
		mm = mm - int(w[i])
		tick[i] = 1
	else:
		break;
		
buff = mm - w[i+1]

print(tick)
print(p)
print(w)
print(pw)
print(m)
		
