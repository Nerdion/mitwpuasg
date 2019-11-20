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
e = int(input("e- public key- "))


n = p * q
theta = (p - 1) * (q - 1)

print("N- ",n)
print("Theta(n)",theta)

string = input('Enter the string')

encList = []
decList = []

for i in string:
	num = ord(i)
	if i.isupper():
		m = num-65
	else:
		m = num-97
	print('m=',m)

	enc = (m**e) % n
	encList.append(enc)

	tValue, t2 = euclid(theta,e)

	if tValue < 0:
		d = theta - (abs(tValue))
	else:
		d = t2 % (abs(tValue))

	dec = (enc**d) % n
	decList.append(dec)

print('original string- ',string)
print('encrypted string- ',encList)
print('decrypted string- ',decList)

charDecList = []
for i in decList:
	m = i+97
	char = chr(m)
	charDecList.append(char)

print('Char list-',charDecList)