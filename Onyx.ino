#include "Adafruit_GFX.h"
#include "./src/MCUFRIEND_kbv/MCUFRIEND_kbv.h"

#define LCD_RST 32  //brown
#define LCD_CS 33   //red
#define LCD_RS 15   //white
#define LCD_WR 4    //yellow
#define LCD_RD 2    //purple

#define LCD_D0 12  //purple
#define LCD_D1 13  //orange
#define LCD_D2 26  //yellow
#define LCD_D3 25  //orange
#define LCD_D4 17  //grey
#define LCD_D5 16  //blue
#define LCD_D6 27  //green
#define LCD_D7 14  //blue


MCUFRIEND_kbv tft;

// Assign human-readable names to some common 16-bit color values:
#define BLACK 0x0000
#define BLUE 0x001F
#define RED 0xF800
#define GREEN 0x07E0
#define CYAN 0x07FF
#define MAGENTA 0xF81F
#define YELLOW 0xFFE0
#define WHITE 0xFFFF

void setup() {
  Serial.begin(115200);

  uint16_t ID = tft.readID();
  Serial.print("ID = 0x");
  Serial.println(ID, HEX);
  tft.begin(0x9327);

  tft.fillScreen(BLACK);
  tft.setCursor(0, 0);
  tft.setTextColor(GREEN);
  tft.setTextSize(1);
  tft.println("> Hello World!");
}

void loop() {}