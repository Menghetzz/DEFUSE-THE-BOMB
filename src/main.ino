#include "Arduino.h"

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

enum States {INITIAL, GAME_ON};
States currentState;

enum Levels {L1, L2, L3};
const int diffRange = 86;

int potValue = 0;
int pattern = 2;
bool pressed = false;
const int ledPins[] = {WHITE_LED, BLUE_LED, YELLOW_LED, GREEN_LED};

void setup() {
    Serial.begin(115200);
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

    currentState = INITIAL;
}

void getPattern (){
    potValue = analogRead(POT_PIN);
    int diffMap = map(potValue, 0, 1023, 0, 255);
    diffMap = diffMap / diffRange;

    switch(diffMap) {
        case L1:
            pattern += L1;
            break;

        case L2:
            pattern += L2;
            break;

        case L3:
            pattern += L3;
            break;
    }
}

void loop() {
    switch (currentState){
        case INITIAL:
            pressed = digitalRead(GREEN_BTN);
            delay(15);
            if(pressed){
                getPattern();
                pressed = false;
                currentState = GAME_ON;
            }
            digitalWrite(RED_LED, HIGH);
            break;
        case GAME_ON:
            digitalWrite(RED_LED, LOW);







            break;
    }
}

