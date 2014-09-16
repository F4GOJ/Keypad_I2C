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
 
#ifndef Keypad_I2C_H
#define Keypad_I2C_H
#include "Arduino.h"

class Keypad_I2C
{
    public:
        Keypad_I2C(int i2c_addr, int int_pin);
        void begin();
		static void keyread();
		char getKey();
        char getKeyNum();
        
	private:
		static char keymap[17];
		int I2C_ADDR;
		int INT_PIN;
		int keycode;
        void begin_priv();
};

#endif
