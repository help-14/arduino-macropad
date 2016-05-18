/*
 Name:		MacroPad.ino
 Created:	5/18/2016 1:20:33 PM
 Author:	Help-14
*/

#include <Keyboard.h>
#include "Keypad.h"

const byte ROWS = 3; //four rows
const byte COLS = 3; //three columns

const char MACRO_1 = '1';
const char MACRO_2 = '2';
const char MACRO_3 = '3';
const char MACRO_4 = '4';
const char MACRO_5 = '5';
const char MACRO_6 = '6';
const char MACRO_7 = '7';
const char MACRO_8 = '8';
const char MACRO_9 = '9';

char keys[ROWS][COLS] = {
	{ MACRO_1,MACRO_2,MACRO_3 },
	{ MACRO_4,MACRO_5,MACRO_6 },
	{ MACRO_7,MACRO_8,MACRO_9 }
};
byte rowPins[ROWS] = { 14,16,10 }; //connect to the row pinouts of the keypad
byte colPins[COLS] = { 2,3,4 }; //connect to the column pinouts of the keypad

Keypad keypad = Keypad(makeKeymap(keys), rowPins, colPins, ROWS, COLS);

// the setup function runs once when you press reset or power the board
void setup() {
	Serial.begin(9600);
	Keyboard.begin();
}

// the loop function runs over and over again until power down or reset
void loop() {
	char key = keypad.getKey();

	if (key == NO_KEY) 
	{
		Serial.println(key);
		return; 
	}

	if (key == MACRO_1)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_LEFT_GUI);
		Keyboard.press(KEY_LEFT_ARROW);
		delay(10);
		Keyboard.releaseAll();
	}
	if (key == MACRO_2)
	{
		Keyboard.press(KEY_LEFT_GUI);
		Keyboard.press('d');
		delay(10);
		Keyboard.releaseAll();
	}
	else if (key == MACRO_3)
	{
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_LEFT_GUI);
		Keyboard.press(KEY_RIGHT_ARROW);
		delay(10);
		Keyboard.releaseAll();
	}
	else {
		Keyboard.press(KEY_LEFT_CTRL);
		Keyboard.press(KEY_LEFT_ALT);
		Keyboard.press(key);
		delay(10);
		Keyboard.releaseAll();
	}
}
