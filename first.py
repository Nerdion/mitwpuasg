import RPi.GPIO as GPIO
import time
import Adafruit_DHT

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

ledPin = 27
gpioPin = 4

GPIO.setup(ledPin, GPIO.OUT)

sensor = Adafruit_DHT.DHT11

h,c = Adafruit_DHT.read_retry(sensor,gpioPin)

print(h,c)

GPIO.output(ledPin,GPIO.HIGH)
time.sleep(1)
GPIO.output(ledPin,GPIO.LOW)

while True:
    time.sleep(4)
    hnew,cnew = Adafruit_DHT.read_retry(sensor,gpioPin)
    if(hnew != h):
        print("h changed")
        print(hnew,cnew)
        GPIO.output(ledPin,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(ledPin,GPIO.LOW)
        time.sleep(2)
        h = hnew
        c = cnew
        
    if(cnew != c):
        print("c changed")
        print(hnew,cnew)
        GPIO.output(ledPin,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(ledPin,GPIO.LOW)
        time.sleep(1)
        GPIO.output(ledPin,GPIO.HIGH)
        time.sleep(1)
        GPIO.output(ledPin,GPIO.LOW)
        time.sleep(2)
        h = hnew
        c = cnew