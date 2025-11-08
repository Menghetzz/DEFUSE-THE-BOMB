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

enum STATES {INITIAL, GAME_ON};
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
    pressed = digitalRead(WHITE_LED_BTN);
    delay(15);

    if (pressed) {
        digitalWrite(WHITE_LED_PIN, HIGH);
    }
}

