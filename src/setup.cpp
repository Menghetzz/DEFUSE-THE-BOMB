#include "setup.h"
#include "Arduino.h"

void setupH(){
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