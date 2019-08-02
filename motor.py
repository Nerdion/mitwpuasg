import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)
#Pin no 11
pin1=17
#Pin no 13
pin2=27

GPIO.setup(pin1,GPIO.OUT)
GPIO.setup(pin2,GPIO.OUT)

while True:
    x = int(input('Clockwise or anti-clockwise? 1 or 2 or 3 to stop'))

    if x == 1 :
        GPIO.output(pin1,GPIO.LOW)
        GPIO.output(pin2,GPIO.HIGH)
    elif x == 2 :
        GPIO.output(pin1,GPIO.HIGH)
        GPIO.output(pin2,GPIO.LOW)
    else :
        GPIO.output(pin1,GPIO.LOW)
        GPIO.output(pin2,GPIO.LOW)
    


