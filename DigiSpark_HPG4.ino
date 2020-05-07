#include <DigiKeyboard.h>



#define KEY_UP_ARROW        0x52
#define KEY_DOWN_ARROW      0x51
#define KEY_LEFT_ARROW      0x50
#define KEY_RIGHT_ARROW     0x4F

String bios_password = "p3nt1um";
int keyWait = 275;

void setup() {


  //HP Main Screen
  DigiKeyboard.sendKeyStroke(0);
  pressKey(KEY_RIGHT_ARROW, 1);
  pressKey(KEY_ENTER, 1);

  wait(1);

  //BIOS Password Screen
 
   DigiKeyboard.print(bios_password);

  pressKey(KEY_ENTER, 1);
 
  DigiKeyboard.print(bios_password);

  pressKey(KEY_ENTER, 2);

  //Open Boot Options
  pressKey(KEY_RIGHT_ARROW, 1);
  pressKey(KEY_DOWN_ARROW, 4);
  pressKey(KEY_ENTER, 1);

  //Set Network Boot Options
  pressKey(KEY_DOWN_ARROW, 2);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_DOWN_ARROW, 1);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_DOWN_ARROW, 1);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_UP_ARROW, 2);
  pressKey(KEY_ENTER, 1);
  pressKey(KEY_DOWN_ARROW, 6);
  pressKey(KEY_F6, 3);

  //Save BIOS Settings
  pressKey(KEY_F10, 1);
  pressKey(KEY_ENTER, 1);
  

}
void loop() {

}

uint8_t pressKey(uint8_t key, int times) {
  for (int i = 1; i <= times; i++) {
    DigiKeyboard.delay(50);
    DigiKeyboard.sendKeyStroke(key);
    DigiKeyboard.delay(keyWait);
  }
}

int wait(int seconds) {
  for (int i = 0; i < seconds; i++) {
    DigiKeyboard.delay(1000);
  }
}
