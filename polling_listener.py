from pynput import keyboard
l = []
def on_press(key):
    if key == keyboard.Key.esc:
        return False  # stop listener
    try:
        k = key.char  # single-char keys
    except:
        k = key.name  # other keys
    if k not in l:
      l.append(k)  
      return False 

while(1): 
    listener = keyboard.Listener(on_press=on_press)
    listener.start()  # start to listen on a separate thread
    listener.join()  # remove if main thread is polling self.keys
    if '.' in l:
        print(l)
        l = []
