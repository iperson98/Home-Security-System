import RPi.GPIO as GPIO            # import RPi.GPIO module
from time import sleep             # lets us have a delay
GPIO.setmode(GPIO.BCM)             # choose BCM or BOARD
GPIO.setup(24, GPIO.OUT)           # set GPIO24 as an output

try:
    while True:
        with open('MyFile.txt') as file:
            contents = file.read()
            search_word = "yes"
            if search_word in contents:
                GPIO.output(24, 1)
                sleep(0.5)
            else:
                GPIO.output(24, 0)         # set GPIO24 to 0/GPIO.LOW/False
                sleep(0.5)                 # wait half a second

except KeyboardInterrupt:          # trap a CTRL+C keyboard interrupt
    GPIO.cleanup()                 # resets all GPIO ports used by this progr
