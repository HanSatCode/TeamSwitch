import serial
import pyautogui

Arduino_Serial = serial.Serial('com3',9600)

while 1:
    incoming_data = str (Arduino_Serial.readline())
    print(incoming_data)

    if '1' in incoming_data:
        pyautogui.typewrite('1')                            

    if '2' in incoming_data:
        pyautogui.typewrite('2')

    if '3' in incoming_data:
        pyautogui.typewrite('3')

    if '4' in incoming_data:
        pyautogui.typewrite('4')

    if '5' in incoming_data:
        pyautogui.typewrite('5')

    if '6' in incoming_data:
        pyautogui.typewrite('6')

    if '7' in incoming_data:
        pyautogui.typewrite('7')

    if '8' in incoming_data:
        pyautogui.typewrite('8')

    if '9' in incoming_data:
        pyautogui.typewrite('9')

    if '0' in incoming_data:
        pyautogui.typewrite('0')

    if 'Delete' in incoming_data:
        pyautogui.keyDown('ctrlleft')
        pyautogui.keyDown('a')
        pyautogui.keyDown('delete')

        pyautogui.keyUp('ctrlleft')
        pyautogui.keyUp('a')
        pyautogui.keyUp('delete')

    incoming_data = "";
