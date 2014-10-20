/********************************************************************************************
 * Arduino library for matrix keypad using key encoder and I2C
 * Created 07/09/2014
 * Christophe Caiveau f4goj@free.fr 
 *
 * Use this library freely
 *
 * Instance :
 * Keypad_I2C kpd(int i2c_addr, int int_pin); // i2c_addr I2C address of the keypad adapter
 *                                            // int_pin interrupt input pin D2 or D3
 *
 * Functions :
 * kpd.begin();
 * kpd.getKey(); 
 * kpd.getKeyNum();
 *
 * MM74C922N datasheet at http://www.ti.com/lit/ds/symlink/mm54c923.pdf
 * PCF8574 datasheet at http://www.nxp.com/documents/data_sheet/PCF8574.pdf
 *
 *******************************************************************************************/
 
#include <Keypad_I2C.h>
#include <Wire.h>

volatile int newkey;

char Keypad_I2C::keymap[17] = {'1', '2', '3', 'A', 
                               '4', '5', '6', 'B',
                               '7', '8', '9', 'C',
                               '*', '0', '#', 'D'};

 Keypad_I2C::Keypad_I2C(int i2c_addr, int int_pin) {
	I2C_ADDR = i2c_addr;
	INT_PIN = int_pin;
}

void Keypad_I2C::begin() {
    begin_priv();
}

void Keypad_I2C::begin_priv() {
	pinMode(INT_PIN, INPUT);
	Wire.begin();
	attachInterrupt(1, keyread, FALLING);
}

void Keypad_I2C::keyread(){
 newkey = 1;
}

char Keypad_I2C::getKey (){
   if(newkey == 1){
    Wire.requestFrom(I2C_ADDR, 1);
    keycode = Wire.read() & 0x0f;
    newkey = 0;
   return keymap[keycode];
  }
 return 0;
}

char Keypad_I2C::getKeyNum (){
 if(newkey == 1){
  Wire.requestFrom(I2C_ADDR, 1);
  keycode = Wire.read() & 0x0f;
  newkey = 0;
  int tempkey = keymap[keycode] - '0';
  if( tempkey >= 0 && tempkey <= 9){
   return keymap[keycode];
  }
 }
 return 0;
}
