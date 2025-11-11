#include "Arduino.h"

#define BLUE_LED_PIN 5
#define BLUE_LED_BTN 4

#define WHITE_LED_PIN 13
#define WHITE_LED_BTN 12

#define YELLOW_LED_PIN 10
#define YELLOW_LED_BTN 9

#define GREEN_LED_PIN 7
#define GREEN_LED_BTN 6

#define RED_LED_PIN 2

#define POT_PIN A0

enum States {INITIAL, GAME_ON};
enum Levels {L1, L2, L3};

int potValue = 0;
int pattern = 2;
bool pressed = false;

void setup() {
    Serial.begin(115200);
    pinMode(BLUE_LED_PIN, OUTPUT);
    pinMode(BLUE_LED_BTN, INPUT);
    pinMode(WHITE_LED_PIN, OUTPUT);
    pinMode(WHITE_LED_BTN, INPUT);
    pinMode(YELLOW_LED_PIN, OUTPUT);
    pinMode(YELLOW_LED_BTN, INPUT);
    pinMode(GREEN_LED_PIN, OUTPUT);
    pinMode(GREEN_LED_BTN, INPUT);
    pinMode(RED_LED_PIN, OUTPUT);
    pinMode(POT_PIN, INPUT);
}

void loop() {
    potValue = analogRead(POT_PIN);
    int diffMap = map(potValue, 0, 1023, 0, 255);
    diffMap = diffMap;
    Serial.print(diffMap);
    Serial.print("\n");
    delay(500);
}

