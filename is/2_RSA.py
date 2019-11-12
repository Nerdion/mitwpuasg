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

		#print(q,r1,r2,r,t1,t2,t)
	return t1


#accepting inputs
p = int(input("p-"))
q = int(input("q-"))
m = int(input("encryption value m-"))
e = int(input("e- public key- "))
n = p * q

enc = None
dec  = None
x = None

while True:
	x = input("What you want to do? 1.Encryption 2.Decryption 3.Close")

	if x == '1' :
		enc = (m**e) % n
		print("N- ",n)
		print("Encrypted C value is - ", enc)

	elif x == '2' :
		theta = (p - 1) * (q - 1)
		print("N- ",n)
		print("Theta(n)",theta)

		tValue = euclid(theta,e)
		print("t1-",tValue)

		d = theta - (abs(tValue))
		print("D- ", d)

		dec = (enc**d) % n
		print("Decrypted value is- ", dec)

	elif x == '3':
		print("End")
		break
	else:
		print("Wrong choice")





