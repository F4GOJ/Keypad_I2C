kpd_i2c
=======

# Arduino Keypad I2C interface library #
F4GOJ Christophe f4goj@free.fr

September 2014

74C922 datasheet at http://www.analog.com/static/imported-files/data_sheets/AD9850.pdf<br>
PCF8574 datasheet at 

Use this library freely.

## Installation ##
To use the **Keypad_I2C** library:  
- Go to https://github.com/F4GOJ/Keypad_I2C, click the [Download ZIP](https://github.com/F4GOJ/Keypad_I2C/archive/master.zip) button and save the ZIP file to a convenient location on your PC.
- Uncompress the downloaded file.  This will result in a folder containing all the files for the library, that has a name that includes the branch name, usually **Keypad_I2C-master**.
- Rename the folder to  **Keypad_I2C**.
- Copy the renamed folder to the Arduino sketchbook\libraries folder.


## Usage notes ##

Instantiate a **my_keypad_name** object.

Keypad_I2C my_keypad_name;

```c++
#include <Keypad_I2c.h>    //http://github.com/F4GOJ/Keypad_I2C

Keypad_I2C KPD;
```
## Hardware connections : ##

![keypad_i2c](h datasheet at )

- Vcc -> 5V
- SDA -> A4
- SCL -> A5
- GND -> Ground

## Functions : ##

###begin(int i2c_addr)
#####Description
Initialize the output pins and master reset the AD9850
#####Syntax
`KPD.begin(i2c_addr);`
#####Parameters
**i2c_addr :** I2C address of tge interface *(int)*<br>
#####Returns
None.
#####Example
```c++
void setup(){
 KPD.begin(0x26);
}
```
