'''
import RPi.GPIO as GPIO
import time
GPIO.setmode(GPIO.BCM)
GPIO.setup(24, GPIO.IN)
'''
count = 0
while True:
	value.sensor = GPIO.input(24)
	
	if value == True:
		count = count + 1
		print(count)
		time.sleep(1)
		
		print("camera")
		time.sleep(0.5)
		
		print("sms sand")
		time.sleep(0.5)
	
	if value.button.on == True:
		print("open")
		time.sleep(1)
	
	if value.button.off == True:
		print("close")
		time.sleep(1)
