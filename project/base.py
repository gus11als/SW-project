from locale import currency
import os
currentPath = os.getcwd()
import base64
with open(r"/home/pi/lastfinalproject/1.jpeg", 'rb') as img:
    base64_string = base64.b64encode(img.read())

    print(base64_string)