#include <Wire.h>
#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);
unsigned long cuntevent = 0;
int GUIstatus = 0;
int cuntsaver = 10;

// clear screen and draw cunt in random location
void makecunt() {
  if (cuntevent + 1000 < millis()) {
    cuntevent = millis();
    lcd.clear();
    lcd.setCursor(random(17), random(4));
    lcd.print("cunt");
  }
}

// main screen. display statistics.
void showstats() {
  if (cuntevent + 1000 < millis()) {
    cuntevent = millis();
    lcd.clear();
    lcd.setCursor(0, 3);
    lcd.print("Uptime: ");
    lcd.setCursor(8, 3);
    lcd.print(millis() / 1000);
  }
}

void setup() {
  lcd.begin(20, 4);
  lcd.clear();
}

void loop() {
  if (GUIstatus == 0) {
    showstats();
  } else if (GUIstatus == 1) {
    makecunt();
  }
  // switch to cuntsaver after cuntsaver seconds
  if(millis()/1000 > cuntsaver){
    GUIstatus = 1;
  }

}
