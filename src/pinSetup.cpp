#include "pinSetup.h"

#define BLUE_LED 5
#define BLUE_BTN 4

#define WHITE_LED 13
#define WHITE_BTN 12

#define YELLOW_LED 10
#define YELLOW_BTN 9

#define GREEN_LED 7
#define GREEN_BTN 6

#define RED_LED 2

#define POT_PIN A0

void pinSetup(){
    pinMode(BLUE_LED, OUTPUT);
    pinMode(BLUE_BTN, INPUT);
    pinMode(WHITE_LED, OUTPUT);
    pinMode(WHITE_BTN, INPUT);
    pinMode(YELLOW_LED, OUTPUT);
    pinMode(YELLOW_BTN, INPUT);
    pinMode(GREEN_LED, OUTPUT);
    pinMode(GREEN_BTN, INPUT);
    pinMode(RED_LED, OUTPUT);
    pinMode(POT_PIN, INPUT);
}