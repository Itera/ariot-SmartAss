from microbit import *
from radio import *
from random import*

#turn radio on and 
on()
config(group=6, length=251)

# 0=stein, 1=saks, 2=papir
def win(me, he):
    if(me == 0 and he == 1):
        return true
    elif(me == 0 and he == 2):
        return false
    elif(me == 1 and he == 0):
        return false
    elif(me == 1 and he == 2):
        return true
    elif(me == 2 and he == 0):
        return true
    elif(me == 2 and he == 1):
        return false
    else:
        return false
        

def game():
    attack = random.randint(0, 2)
    send(str(attack))
    counter = receive()
    victory = win(attack, counter)
    
    if(victory):
        display.scroll("win")
    else:
        display.scroll("lose")
    display.clear()
    
while True:
    if button_a.was_pressed():
        #send the images
        send("A")
     
    if accelerometer.was_gesture('shake'):
        game()
     
    #receive data    
    data = receive()
    
    #check that we have received any data
    if data != None:
        
        #split the data into different pictures by the marker
        display.scroll(data)

        #clear the screen
        display.clear()