from pynput import keyboard

l = []
count = 0
started = False

from threading import Thread
from time import sleep
one = 'b'
two = 'f'
three = 'd'
four = 's'
five = 'a'

key = {1 : ' ', 
4 : 'e', 
8 : 't',
16 : '\b', 
2 : 'o', 
3 : '\n',
6 : 'n',
12 : 'h',
24 : 'a',
17 : 's',
18 : 'r',
10 : 'i',
5: 'l',
20: 'd',
9: 'u',
28 : 'm',
14: 'y',
26 : 'w',
25 : 'c',
13 : 'f',
11 : 'g',
7 : ',',
15 : '.',
23 : 'p',
29 : 'v',
30 : 'b'}

def bitconverter(parameter_list):

    count = 1 if one in parameter_list else 0
    count += 2 if two in parameter_list else 0
    count += 4 if three in parameter_list else 0
    count += 8 if four in parameter_list else 0
    count += 16 if five in parameter_list else 0
    return count
h = []
def threaded_function(arg):
    while(1):
        global started
        global count
        if (started and not count):
            global l
            #print(l)
            print(key.get(bitconverter(l), "Nothing"))
            
            started = False
            l = []

        sleep(0.0002)


def on_press(key):
    try:
        c = key.char
        global count
        if c not in l:
            count = count + 1
            l.append(c)
            global started
            started = True
    except AttributeError:
        
        
        print('special key {0} pressed'.format(
            key))

def on_release(key):
    global count
    if key.char in l:
        count = count - 1
    if key == keyboard.Key.esc:
        # Stop listener
        return False

thread = Thread(target = threaded_function, args = (10, ))
thread.start()
#thread.join()
# Collect events until released
with keyboard.Listener(
        on_press=on_press,
        on_release=on_release) as listener:
    listener.join()

