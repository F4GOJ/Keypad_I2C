# Arduino Keypad I2C interface library #
F4GOJ Christophe f4goj@free.fr September 2014

MM74C922N datasheet at http://www.ti.com/lit/ds/symlink/mm54c923.pdf<br>
PCF8574 datasheet at http://www.nxp.com/documents/data_sheet/PCF8574.pdf

Use this library freely.

![keypad_i2c](https://raw.githubusercontent.com/F4GOJ/Keypad_I2C/master/images/keypad_i2c_sch.png)

## Hardware connections ##
##### Keypad to Arduino :

- J1-1 -> D2 or D3
- J1-2 -> +5V
- J1-3 -> A4
- J1-4 -> A5
- J1-5 -> Ground

##### Expansion I2C port :

- J2-1 -> Ground
- J2-2 -> SCL
- J2-3 -> SDA
- J2-4 -> +5V
<br><br>

## Installation ##
To use the **Keypad_I2C** library:  
- Go to https://github.com/F4GOJ/Keypad_I2C, click the [Download ZIP](https://github.com/F4GOJ/Keypad_I2C/archive/master.zip) button and save the ZIP file to a convenient location on your PC.
- Uncompress the downloaded file.  This will result in a folder containing all the files for the library, that has a name that includes the branch name, usually **Keypad_I2C-master**.
- Rename the folder to  **Keypad_I2C**.
- Copy the renamed folder to the Arduino sketchbook\libraries folder.

## Usage notes ##
You have to instantiate a **my_keypad_name** object.

Keypad_I2C my_keypad_name(int i2c_addr, int int_pin);

##### Parameters
**i2c_addr :** I2C address of the interface *(int)*<br>
**int_pin :** Input pin 2 or 3 to attach the interrupt *(int)*

```c++
#include <Keypad_I2c.h>    //http://github.com/F4GOJ/Keypad_I2C

Keypad_I2C KPD(0x26, 2);
```
<br><br>
## Functions : ##
### begin()
##### Description
Initialize and attach interrupt to the input pin, begins the wire connection.
##### Syntax
`KPD.begin();`
##### Parameters
None.
##### Returns
None.
##### Example
```c++
void setup(){
 KPD.begin();
}
```

### getKey()
##### Description
Get key pressed.
##### Syntax
`KPD.getKey();`
##### Parameters
None.
##### Returns
The code of the key pressed or 0 if no new key has been pressed. *(char)*
##### Example
```c++
ch = KPD.getKey();
if(ch != 0){
 Serial.print(ch);
}
```

### getKeyNum()
##### Description
Get only numerical key pressed.
##### Syntax
`KPD.getKeyNum();`
##### Parameters
None.
##### Returns
The code of the numerical key pressed or 0 if no new key has been pressed. *(char)*
##### Example
```c++
ch = KPD.getKeyNum();
if(ch != 0){
 Serial.print(ch);
}
```
