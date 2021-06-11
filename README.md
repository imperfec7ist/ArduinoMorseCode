# ArduinoMorseCode
Arduino program that translates Morse Code (light flashes or tapping) into characters.

Contents: -> morsecode_translator.c C code for basic logic of translating Morse code to words (letters, digits).

->morsecode_gen_v1.ino Arduino code for light flash morse code translator: translates photoresitor input to morse code. *Presently using IR Proximity Sensor for testing

->morecode_gen_control.ino Arduino code with function similar to "blink code" to test working of photoresistor input; measures time between inputs

COMING UP: -> morsecode_translator.ino To translate sensor input > morse code > words.
