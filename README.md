# ArduinoMorseCode
Arduino program that translates Morse Code (light flashes or tapping) into characters.

### Contents:
->**morsecode_translator.c** C code for basic logic of Morse code translation to words (letters, digits).

->morsecode_gen_v1.ino Arduino code for light flash morse code translator: translates photoresitor input to morse code. *Presently using IR Proximity Sensor for testing

->morecode_gen_control.ino Arduino code with to test working of photoresistor input; measures time between inputs

#### **morsecode_gen_v3.2.3.ino Arduino code that actually translates - it WORKS! (Barely Working since some fixes are required).**

>->_morsecode_gen_v3.2.3_button.ino The same barely working code but with inverted input to support Normally Open sensors and switches - test this on tinkercad circuits using pushbutton._

COMING UP: -> morsecode_translator.ino To translate sensor input > morse code > words.
