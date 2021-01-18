// arduino-oled-slot-machine v1.0

#include <Wire.h>
#include <Adafruit_SSD1306.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define SPIN_BUTTON A2
#define SPEAKER_PIN 9

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

const unsigned char PROGMEM moon0 [] = {0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x63, 0x1F, 
0x02, 0x04, 0x18, 0xE0, 0x0C, 0x1C, 0x28, 0x48, 0x44, 0x84, 0x84, 0x82, 0x82, 0x81, 0x40, 0x40, 0x20, 0x30, 0x0C, 0x03};
const unsigned char PROGMEM bar1 [] = {0xF8, 0xFC, 0x1C, 0x5C, 0x1C, 0xFC, 0x3C, 0x9C, 0x3C, 0xFC, 0x1C, 0xDC, 
0x1C, 0xFC, 0xFC, 0xF8, 0x1F, 0x3F, 0x38, 0x3B, 0x38, 0x3F, 0x38, 0x3D, 0x38, 0x3F, 0x38, 0x3C, 0x3C, 0x39, 0x3F, 0x1F};
const unsigned char PROGMEM bell2 [] = {0x00, 0x00, 0x00, 0xE0, 0x10, 0x08, 0x04, 0x07, 0x07, 0x04, 0x08, 0x10, 
0xE0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x38, 0x27, 0x24, 0x24, 0x64, 0xA4, 0xA4, 0x64, 0x24, 0x24, 0x27, 0x38, 0x00, 0x00};
const unsigned char PROGMEM cherry3 [] = {0x30, 0x4C, 0x42, 0x41, 0x21, 0x21, 0x1B, 0x0E, 0xF4, 0x08, 0x90, 0x60, 
0x40, 0x40, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x3C, 0x42, 0x81, 0x81, 0x81, 0x5E, 0x21, 0x20, 0x20, 0x10, 0x0F};
const unsigned char PROGMEM clover4 [] = {0x00, 0xE0, 0x90, 0x10, 0x1E, 0x11, 0x01, 0x01, 0x02, 0x01, 0x01, 0x11, 
0x1E, 0x10, 0x90, 0xE0, 0x60, 0x27, 0x38, 0x10, 0x78, 0x88, 0x80, 0x80, 0x40, 0x80, 0x80, 0x88, 0x78, 0x08, 0x08, 0x07};
const unsigned char PROGMEM diamond5 [] = {0x1C, 0x72, 0x91, 0x11, 0x3D, 0xD3, 0x11, 0x11, 0x11, 0x11, 0x93, 0x7D, 
0x11, 0x91, 0x72, 0x1C, 0x00, 0x00, 0x01, 0x02, 0x04, 0x19, 0x3E, 0xE0, 0xE0, 0x3E, 0x19, 0x04, 0x02, 0x01, 0x00, 0x00};
const unsigned char PROGMEM seven6 [] = {0xFE, 0x81, 0x62, 0x21, 0x31, 0x31, 0x21, 0xA1, 0x61, 0x21, 0x02, 0x02, 
0x82, 0x72, 0x19, 0x06, 0x00, 0x00, 0x00, 0x00, 0xFC, 0x82, 0x81, 0x80, 0x80, 0x80, 0x80, 0xFE, 0x01, 0x00, 0x00, 0x00};
const unsigned char PROGMEM heart7 [] = {0xFC, 0x02, 0x61, 0xC1, 0x01, 0x01, 0x02, 0x0C, 0x0C, 0x02, 0x01, 0x01, 
0x01, 0x01, 0x02, 0xFC, 0x00, 0x03, 0x04, 0x09, 0x13, 0x20, 0x40, 0x80, 0x80, 0x40, 0x20, 0x10, 0x08, 0x04, 0x03, 0x00};
const unsigned char PROGMEM horseshoe8 [] = {0xF8, 0x04, 0x02, 0x81, 0x61, 0x21, 0x11, 0x11, 0x11, 0x11, 0x21, 0x61, 
0x81, 0x02, 0x04, 0xF8, 0x01, 0xC6, 0xB8, 0x83, 0xBC, 0x40, 0x00, 0x00, 0x00, 0x00, 0x40, 0xBC, 0x83, 0xB8, 0xC6, 0x01};
const unsigned char PROGMEM lemon9 [] = {0x00, 0xC0, 0x30, 0x08, 0x04, 0x04, 0x02, 0x02, 0x02, 0x02, 0x02, 0x02, 
0x01, 0x01, 0xF1, 0x0E, 0x70, 0x8F, 0x80, 0x80, 0x40, 0x40, 0x40, 0x40, 0x40, 0x41, 0x24, 0x21, 0x10, 0x0C, 0x03, 0x00};
const unsigned char PROGMEM coin10 [] = {0xE0, 0x18, 0xEC, 0x36, 0x0A, 0x0D, 0xE5, 0xB5, 0xB5, 0x65, 0x0D, 0x0A, 
0x36, 0xEC, 0x18, 0xE0, 0x07, 0x18, 0x37, 0x6C, 0x50, 0xB0, 0xA6, 0xAD, 0xAD, 0xA7, 0xB0, 0x50, 0x6C, 0x37, 0x18, 0x07};
const unsigned char PROGMEM orange11 [] = {0xC0, 0x20, 0x12, 0x0D, 0x09, 0x11, 0x12, 0x3C, 0x5C, 0x8B, 0x28, 0x48, 
0x10, 0x30, 0xC0, 0x00, 0x1F, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x21, 0x19, 0x06, 0x01, 0x01, 0x00};
const unsigned char PROGMEM plum12 [] = {0x08, 0x0C, 0x12, 0x11, 0x11, 0xC9, 0x3E, 0x0A, 0x0E, 0x18, 0x08, 0x08, 
0x10, 0x20, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x07, 0x18, 0x20, 0x40, 0x80, 0x80, 0x80, 0x80, 0x80, 0x40, 0x3F};
const unsigned char PROGMEM star13 [] = {0x40, 0xC0, 0xC0, 0x40, 0x60, 0x20, 0x38, 0x0E, 0x0E, 0x38, 0x20, 0x60, 
0x40, 0xC0, 0xC0, 0x40, 0x00, 0x00, 0x81, 0xE3, 0x7E, 0x20, 0x30, 0x10, 0x10, 0x30, 0x20, 0x7E, 0xE3, 0x81, 0x00, 0x00};
const unsigned char PROGMEM melon14 [] = {0xE0, 0x18, 0x84, 0x92, 0x92, 0x91, 0x11, 0xC1, 0x39, 0x07, 0xA1, 0x01, 
0x09, 0xA2, 0x04, 0xF8,0x07, 0x18, 0x20, 0x44, 0x44, 0x84, 0x80, 0x83, 0x9C, 0xE0, 0x82, 0x90, 0x80, 0x4A, 0x20, 0x1F};

constexpr uint8_t iHeight = 16;
constexpr uint8_t iWidth  = 16;
constexpr uint8_t iMargin = 4;
constexpr uint8_t numReels = 3;
constexpr uint8_t numSlots = 15;
constexpr uint8_t startingCredits = 100;
constexpr uint8_t startingBet = 5; // 1 credit per line
constexpr uint8_t reelSpeed = 5; // must divide into 20 evenly 1,2,4,5,10,20

struct SlotInfo
{
  uint8_t icon;
  int16_t posX;
  int16_t posY;
};

SlotInfo slotInfo[numReels][numSlots] = { 0, 0 };
static uint8_t *sBuffer;
uint8_t frameCounter = 0;

int16_t reelSteps[numReels] = { 0 };
uint8_t reelIndex[numReels] = { 0 };
uint8_t prevReelIndex[numReels] = { 0 };
long plays = 0;
long wins = 0;
uint16_t games = 0;
long credits = startingCredits;
uint8_t betAmount = startingBet;
bool spinning = false;
bool buttonPress = false;

bool autoPlay = true;   // automatic spin (no button needed)
bool keepPlaying = true; // play forever with automatic spin


void setup() {
  pinMode(SPIN_BUTTON, INPUT_PULLUP);
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);
  delay(1000);
  sBuffer = display.getBuffer();
  randomSeed(analogRead(A0));
  displayLogo();
  delay(1000);
  newGame();
}

void newGame() {
  display.clearDisplay();
  credits = startingCredits;
  betAmount = startingBet;
  games++;
  initReelData();
  initReelPosition();
  drawBorder();
  displayReels();
  displayStats(0);
  delay(1000);
}

void loop() {
  if (!autoPlay && !buttonPress) {
    waitOnButtonPress();
  }
  if (credits == 0 && !spinning) {
    gameOver();
    return;
  }
  if ((autoPlay || buttonPress) && !spinning) {
    bet(betAmount);
    plays++;
    spinReels();
    for (uint8_t i = 0; i < numReels; i++) {
      reelSteps[i] = (numSlots - prevReelIndex[i] + reelIndex[i]) * (iHeight + iMargin);
    }
    spinning = true;
    displayStats(0);
  }

  if (reelSteps[0] > 0 || reelSteps[1] > 0 || reelSteps[2] > 0) {
    if (frameCounter % 2) {
      tone(SPEAKER_PIN, 2093, 50); // C7
    }
    frameCounter++;
    updateReels();
    for (uint8_t i = 0; i < numReels; i++) {
      if (reelSteps[i] > 0) reelSteps[i] -= reelSpeed;
    }
    noTone(SPEAKER_PIN);
    if (reelSteps[0] == 0 && reelSteps[1] == 0 && reelSteps[2] == 0) {
      spinning = false;
      buttonPress = false;
      delay(500);
      int amountWon = checkLine();
      displayStats(amountWon);
      delay(250);
    }
  }
}

void gameOver() {
  displayEnd();
  if (keepPlaying && autoPlay) {
    delay(2000);
    newGame();
  }
  else {
    waitOnButtonPress();
    newGame();
  }
}

int spinReels() {
  for (uint8_t i = 0; i < numReels; i++) {
    prevReelIndex[i] = reelIndex[i];
    uint8_t ptr = (random() % 9);
    uint8_t spins = (random() % 9) + numSlots;
    for (uint8_t j = 0; j < spins; j++) {
      ptr++;
      if (ptr > numSlots - 1) {
        ptr = 0;
      }
    }
    reelIndex[i] = ptr;
  }
}

void initReelData() {
  uint8_t p[numSlots];
  for (uint8_t i = 0; i < numSlots; i++) {
    p[i] = i;
  }
  for (uint8_t i = 0; i < numReels; i++) {
    reelIndex[i] = 1;
    for (uint8_t j = numSlots - 1; j > 0; --j) {
      uint8_t r = random() % j;
      uint8_t temp = p[j];
      p[j] = p[r];
      p[r] = temp;
    }
    for (uint8_t k = 0; k < numSlots; k++) {
      slotInfo[i][k].icon = p[k];
    }
  }
}

void initReelPosition() {
  uint8_t k;
  for (uint8_t r = 0; r < numReels ; r++) {
    k = 0;
    for (uint8_t s = 0; s < numSlots ; s++) {
      uint8_t icon = slotInfo[r][s].icon;
      slotInfo[r][icon].posX = (SCREEN_WIDTH / 2) + (iMargin * r) + (iWidth * r) + iMargin;
      if ( s < 3 ) {
        slotInfo[r][icon].posY = (SCREEN_HEIGHT - iHeight - iMargin) - ((iHeight * s) + (iMargin * s)) ;
      }
      else {
        slotInfo[r][icon].posY = -iHeight + (-iHeight * k) + (-iMargin * k);
        k++;
      }
    }
  }
}

void updateReels() {
  for (int r = 0; r < numReels ; r++) {
    for (int s = 0; s < numSlots; s++) {
      if (reelSteps[r] > 0) {
        slotInfo[r][s].posY += reelSpeed;
      }
      if (slotInfo[r][s].posY >= SCREEN_HEIGHT) {
        slotInfo[r][s].posY = (-iHeight * (numSlots - 3)) + (-iMargin * (numSlots - 3)) + iMargin;
      }
    }
  }
  clearRightScreen();
  displayReels();
  display.display();
}

// drawBitmap borrowed from arduboy ~2x faster than Adafruit_GFX drawBitmap
void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap, uint8_t w, uint8_t h, uint8_t color) {
  // no need to draw at all if we're offscreen
  if (x + w <= 0 || x > SCREEN_WIDTH - 1 || y + h <= 0 || y > SCREEN_HEIGHT - 1)
    return;

  int yOffset = abs(y) % 8;
  int sRow = y / 8;
  if (y < 0) {
    sRow--;
    yOffset = 8 - yOffset;
  }
  int rows = h / 8;
  if (h % 8 != 0) rows++;
  for (int a = 0; a < rows; a++) {
    int bRow = sRow + a;
    if (bRow > (SCREEN_HEIGHT / 8) - 1) break;
    if (bRow > -2) {
      for (int iCol = 0; iCol < w; iCol++) {
        if (iCol + x > (SCREEN_WIDTH - 1)) break;
        if (iCol + x >= 0) {
          if (bRow >= 0) {
            if (color == WHITE)
              sBuffer[(bRow * SCREEN_WIDTH) + x + iCol] |= pgm_read_byte(bitmap + (a * w) + iCol) << yOffset;
            else if (color == BLACK)
              sBuffer[(bRow * SCREEN_WIDTH) + x + iCol] &= ~(pgm_read_byte(bitmap + (a * w) + iCol) << yOffset);
            else
              sBuffer[(bRow * SCREEN_WIDTH) + x + iCol] ^= pgm_read_byte(bitmap + (a * w) + iCol) << yOffset;
          }
          if (yOffset && bRow < (SCREEN_HEIGHT / 8) - 1 && bRow > -2) {
            if (color == WHITE)
              sBuffer[((bRow + 1)*SCREEN_WIDTH) + x + iCol] |= pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset);
            else if (color == BLACK)
              sBuffer[((bRow + 1)*SCREEN_WIDTH) + x + iCol] &= ~(pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset));
            else
              sBuffer[((bRow + 1)*SCREEN_WIDTH) + x + iCol] ^= pgm_read_byte(bitmap + (a * w) + iCol) >> (8 - yOffset);
          }
        }
      }
    }
  }
}

void displayReels() {
  for (uint8_t r = 0; r < numReels ; r++) {
    for (uint8_t s = 0; s < numSlots ; s++) {
      if (s == 0) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, moon0, iWidth, iHeight, WHITE);
        }
      }
      if (s == 1) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, bar1, iWidth, iHeight, WHITE);
        }
      }
      if (s == 2) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, bell2, iWidth, iHeight, WHITE);
        }
      }
      if (s == 3) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, cherry3, iWidth, iHeight, WHITE);
        }
      }
      if (s == 4) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, clover4, iWidth, iHeight, WHITE);
        }
      }
      if (s == 5) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, diamond5, iWidth, iHeight, WHITE);
        }
      }
      if (s == 6) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, seven6, iWidth, iHeight, WHITE);
        }
      }
      if (s == 7) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, heart7, iWidth, iHeight, WHITE);
        }
      }
      if (s == 8) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, horseshoe8, iWidth, iHeight, WHITE);
        }
      }
      if (s == 9) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, lemon9, iWidth, iHeight, WHITE);
        }
      }
      if (s == 10) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, coin10, iWidth, iHeight, WHITE);
        }
      }
      if (s == 11) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, orange11, iWidth, iHeight, WHITE);
        }
      }
      if (s == 12) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, plum12, iWidth, iHeight, WHITE);
        }
      }
      if (s == 13) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, star13, iWidth, iHeight, WHITE);
        }
      }
      if (s == 14) {
        if (slotInfo[r][s].posY < SCREEN_HEIGHT && slotInfo[r][s].posY > -iHeight) {
          drawBitmap(slotInfo[r][s].posX, slotInfo[r][s].posY, melon14, iWidth, iHeight, WHITE);
        }
      }
    }
  }
}

void drawBorder() {
  display.drawRect(0, 0, 128, 64, WHITE);
  display.drawFastVLine(64, 0, 64, WHITE);
}

void clearLeftScreen() {
  display.fillRect(1, 1, 62, 62, BLACK);
}
void clearRightScreen() {
  display.fillRect(65, 1, 62, 62, BLACK);
}

void bet(uint8_t amount) {
  if ((credits - amount) < 0) {
    betAmount = credits;
    displayStats(0);
  }
  credits -= betAmount;
}

enum Icon : uint8_t
{
  moon = 0,
  bar = 1,
  bell = 2,
  cherry = 3,
  clover = 4,
  diamond = 5,
  seven = 6,
  heart = 7,
  horseshoe = 8,
  lemon = 9,
  coin = 10,
  orange = 11,
  plum = 12,
  star = 13,
  melon = 14
};

int checkWinLines(uint8_t line[]) { // 3375 combinations (2610 + 630) / 3375 = 96% return
  if (line[0] == moon && line[1] == moon && line[2] == moon) {
    return 75;
  }
  if (line[0] == bar && line[1] == bar && line[2] == bar) {
    return 700;
  }
  if (line[0] == bell && line[1] == bell && line[2] == bell) {
    return 175;
  }
  if (line[0] == cherry && line[1] == cherry && line[2] == cherry) {
    return 100;
  }
  if (line[0] == clover && line[1] == clover && line[2] == clover) {
    return 25;
  }
  if (line[0] == diamond && line[1] == diamond && line[2] == diamond) {
    return 200;
  }
  if (line[0] == seven && line[1] == seven && line[2] == seven) {
    return 350;
  }
  if (line[0] == heart && line[1] == heart && line[2] == heart) {
    return 150;
  }
  if (line[0] == horseshoe && line[1] == horseshoe && line[2] == horseshoe) {
    return 200;
  }
  if (line[0] == lemon && line[1] == lemon && line[2] == lemon) {
    return 10;
  }
  if (line[0] == coin && line[1] == coin && line[2] == coin) {
    return 300;
  }
  if (line[0] == orange && line[1] == orange && line[2] == orange) {
    return 50;
  }
  if (line[0] == plum && line[1] == plum && line[2] == plum) {
    return 50;
  }
  if (line[0] == star && line[1] == star && line[2] == star) {
    return 200;
  }
  if (line[0] == melon && line[1] == melon && line[2] == melon) {
    return 25;  // 2610 total
  }
  if (line[0] == line[1] || line[0] == line[2] || line[1] == line[2]) {
    return 1;  // any pair 630 total
  }
  return 0;
}

uint8_t previous(uint8_t index) {
  char prev = reelIndex[index] - 1;
  if (prev < 0) {
    prev = numSlots - 1;
  }
  return slotInfo[index][prev].icon;
}

uint8_t next(uint8_t index) {
  char next = reelIndex[index] + 1;
  if (next > numSlots - 1) {
    next = 0;
  }
  return slotInfo[index][next].icon;
}

int checkLine() {
  uint8_t lineValues[3];
  int winnings = 0;
  int total = 0;
  // Check middle line
  if (betAmount >= 1) {
    for (uint8_t i = 0; i < 3; i++) {
      lineValues[i] = slotInfo[i][reelIndex[i]].icon;
    }
    winnings = checkWinLines(lineValues);
    if (winnings > 0 ) {
      display.fillRect(64, 31, 64, 2, WHITE);
    }
    total += winnings;
    winnings = 0;
  }
  // Check top line
  if (betAmount >= 2) {
    for (uint8_t i = 0; i < 3; i++) {
      lineValues[i] = next(i);
    }
    winnings += checkWinLines(lineValues);
    if (winnings > 0 ) {
      display.fillRect(64, 11, 64, 2, WHITE);
    }
    total += winnings;
    winnings = 0;
  }
  // Check bottom line
  if (betAmount >= 3) {
    for (uint8_t i = 0; i < 3; i++) {
      lineValues[i] = previous(i);
    }
    winnings += checkWinLines(lineValues);
    if (winnings > 0 ) {
      display.fillRect(64, 51, 64, 2, WHITE);
    }
    total += winnings;
    winnings = 0;
  }
  // Check top left to bottom right diagonal
  if (betAmount >= 4) {
    lineValues[0] = next(0);
    lineValues[1] = slotInfo[1][reelIndex[1]].icon;
    lineValues[2] = previous(2);
    winnings += checkWinLines(lineValues);
    if (winnings > 0 ) {
      display.drawLine(64, 0, 128, 63, WHITE);
      display.drawLine(64, 1, 128, 64, WHITE);
    }
    total += winnings;
    winnings = 0;
  }
  // Check bottom left to top right diagonal
  if (betAmount == 5) {
    lineValues[0] = previous(0);
    lineValues[1] = slotInfo[1][reelIndex[1]].icon;
    lineValues[2] = next(2);
    winnings += checkWinLines(lineValues);
    if (winnings > 0 ) {
      display.drawLine(64, 63, 128, 0, WHITE);
      display.drawLine(64, 64, 128, 1, WHITE);
    }
    total += winnings;
  }
  credits += total;
  display.display();
  return total;
}

void displayEnd() {
  clearRightScreen();
  display.setCursor(72, 4);
  display.setTextSize(2);
  display.print(F("GAME"));
  display.setCursor(72, 24);
  display.print(F("OVER"));
  display.display();
}

void displayStats(int won) {
  if (won > 0) {
    wins++;
    clearLeftScreen();
    display.setCursor(16, 4);
    display.setTextSize(2);
    display.print(F("YOU"));
    display.setCursor(12, 24);
    display.print(F("WON!"));
    display.setCursor(12, 44);
    display.print(won);
    display.display();
    playWin();
    delay(1000);
  }
  clearLeftScreen();
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(4, 3);
  display.print(F("Credits"));
  if (autoPlay) {
    display.setCursor(49, 3);
    display.print(F("\x12"));
  }
  if (keepPlaying) {
    display.setCursor(56, 3);
    display.print(F("\xEC"));
  }
  display.setCursor(4, 13);
  display.print(credits);
  display.setCursor(4, 23);
  display.print(F("Bet Wins"));
  display.setCursor(4, 33);
  display.print(betAmount);
  display.setCursor(28, 33);
  display.print(wins);
  display.setCursor(4, 43);
  display.print(F("Spin"));
  display.setCursor(4, 53);
  display.print(plays);
  display.setCursor(38, 43);
  display.print(F("Game"));
  display.setCursor(44, 53);
  display.print(games);
  display.display();
}

void displayLogo() {
  char fy = -48;
  char sy = -28;
  for (uint8_t i = 0; i < SCREEN_HEIGHT; i++) {
    display.clearDisplay();
    display.setTextColor(WHITE);
    display.setCursor(28, fy);
    display.setTextSize(2);
    display.print(F("FIDGET"));
    display.setCursor(34, sy);
    display.print(F("SLOTS"));
    display.display();
    fy += 1;
    sy += 1;
  }
}

void waitOnButtonPress(){
  bool released = false;
  while (!released){
    while (digitalRead(SPIN_BUTTON) == HIGH){
      yield();
      delay(10);
    }
    delay(10);
    if (digitalRead(SPIN_BUTTON) == LOW){
      while (digitalRead(SPIN_BUTTON) == LOW){
        yield();
        delay(10);
      }
      released = true;
    }
  }
  buttonPress = true;
}

void playWin() {
  int note[] = { 2637, 2349, 2637}; // E7 D7 E7
  for (uint8_t i = 0; i < 3; i++) {
    tone(SPEAKER_PIN, note[i], 125);
    delay(125);
    noTone(SPEAKER_PIN);
  }
}
