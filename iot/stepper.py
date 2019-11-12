import RPi.GPIO as GPIO
import time

pins = [17,27,23,24]

c = [
        [1,0,0,0],
        [1,1,0,0],
        [0,1,0,0],
        [0,1,1,0],
        [0,0,1,0],
        [0,0,1,1],
        [0,0,0,1],
        [1,0,0,1]
    ]

GPIO.setmode(GPIO.BCM)
GPIO.setwarnings(False)

for i in pins :
    print(i)
    GPIO.setup(i,GPIO.OUT)
        
for i in range(8):
    for j in range(4):
        print(pins[j],c[i][j])
        GPIO.output(pins[j],c[i][j])
    time.sleep(2) 


