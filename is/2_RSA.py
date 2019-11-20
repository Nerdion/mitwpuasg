#function for extended eucledian theorem
def euclid(r1,r2):
	t1 = 0
	t2 = 1
	q = r = t = None

	while(r1 != 1) :
		q = int(r1/r2)
		r = r1 % r2

		t = t1 - (q * t2)

		t1 = t2
		t2 = t

		r1 = r2
		r2 = r
		#print('q','r1','r2','t1','t2','t')
		#print(q,r1,r2,r,t1,t2,t)
	return t1,t2


#accepting inputs
p = int(input("p-"))
q = int(input("q-"))
m = int(input("encryption value m-"))
e = int(input("e- public key- "))

n = p * q
theta = (p - 1) * (q - 1)

print("N- ",n)
print("Theta(n)",theta)

enc = None
dec  = None
x = None

enc = (m**e) % n
print("Encrypted C value is - ", enc)

tValue, t2 = euclid(theta,e)

if tValue < 0:
	d = theta - (abs(tValue))
else:
	d = t2 % (abs(tValue))
print("t1-",tValue)


print("D- ", d)

dec = (enc**d) % n
print("Decrypted value is- ", dec)



