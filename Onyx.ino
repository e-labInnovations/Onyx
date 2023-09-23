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

#define CHAR_WIDTH 6

// Define the ASCII art numbers
const char* asciiNumbers[] = {
  "_______   \n\\   _  \\  \n/  /_\\  \\ \n\\  \\_/   \\ \n \\_____  / \n       \\/  \n",
  " ____     \n/_   |    \n |   |    \n |   |    \n |___|    \n",
  "________   \n\\_____  \\  \n /  ____/  \n/       \\  \n\\_______ \\ \n        \\/ \n",
  "________   \n\\_____  \\  \n  _(__  <  \n /       \\ \n/______  / \n       \\/  \n",
  "   _____   \n  /  |  |  \n /   |  |_ \n/    ^   / \n\\____   |  \n     |__|  \n",
  " .________ \n |   ____/ \n |____  \\  \n /       \\ \n/______  / \n       \\/  \n",
  "  ________ \n /  _____/ \n/   __  \\  \n\\  |__\\  \\ \n \\_____  / \n       \\/  \n",
  "_________  \n\\______  \\ \n    /    / \n   /    /  \n  /____/   \n",
  "           \n  ______   \n /  __  \\  \n >      <  \n/   --   \\ \n\\______  / \n       \\/  \n",
  " ________  \n/   __   \\ \n\\____    / \n   /    /  \n  /____/   \n          \n"
};

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
  // tft.println("> Hello World!");
  typeTextWithCursor("> Hello, World!", 0, 0, 100);

  delay(1000);
}

void loop() {
  // Display numbers from 0 to 9
  for (int i = 0; i < 10; i++) {
    tft.fillScreen(BLACK);
    tft.setCursor(0, 0);
    tft.setTextColor(GREEN);
    tft.setTextSize(1);
    tft.println("> Hello World!");
    displayAsciiNumber(i, 20, 20);
    delay(1000);
  }
}

void displayAsciiNumber(int number, int x, int y) {
  // Split the ASCII art into lines and print each line
  char* asciiArt = strdup(asciiNumbers[number]);
  char* line = strtok(asciiArt, "\n");
  while (line != NULL) {
    tft.setCursor(x, y);        // Set the cursor position
    tft.println(line);          // Print the line
    line = strtok(NULL, "\n");  // Move to the next line
    y = tft.getCursorY();       // Adjust the y coordinate for the next line
  }
  free(asciiArt);  // Free the dynamically allocated memory
}

void typeTextWithCursor(const char* text, int x, int y, int delayMs) {
  for (int i = 0; text[i] != '\0'; i++) {
    tft.print(text[i]);
    delay(delayMs);
    x += CHAR_WIDTH;      // Move the cursor by an estimated character width
    tft.setCursor(x, y);  // Set the cursor position for the next character
  }
}