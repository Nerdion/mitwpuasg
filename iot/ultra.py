import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)

trigPin = 17
echoPin = 18
pin = 22
GPIO.setwarnings(False)
GPIO.setup(trigPin,GPIO.OUT)
GPIO.setup(pin,GPIO.OUT)
GPIO.setup(echoPin,GPIO.IN)

GPIO.output(trigPin,GPIO.LOW)
print("waiting")
time.sleep(2)
GPIO.output(trigPin, GPIO.HIGH)
time.sleep(0.00001)
GPIO.output(trigPin,GPIO.LOW)
start = 0
end = 1
while GPIO.input(echoPin)==0:
    start = time.time()

while GPIO.input(echoPin)==1:
    end = time.time()

if end > 15 :
    GPIO.output(pin, GPIO.HIGH)
    time.sleep(2)
    GPIO.output(pin, GPIO.LOW)


dur = end-start

distance = dur*1715
distance = round(distance,2)

print(distance)