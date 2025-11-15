#include "Arduino.h"
#include "Timer.h"

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

Timer* timer;

enum States {INITIAL, CREATE_PATTERN, GAME_ON};
States currentState;

enum Levels {L1, L2, L3};
const int DIFFRANGE = 86;
const int MAX_PATTERN = 100;

int potValue;
int pattern;
bool pressed = false;
const int LEDPINS[] = {WHITE_LED, BLUE_LED, YELLOW_LED, GREEN_LED};
int gamePattern[MAX_PATTERN];
int userPattern[MAX_PATTERN];

int indexUser;

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

    timer = new Timer();
}

void getPattern (){
    potValue = analogRead(POT_PIN);
    int diffMap = map(potValue, 0, 1023, 0, 255);
    diffMap = diffMap / DIFFRANGE;

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

bool checkPattern(){
    for(int i = 0; i < pattern; i++) {
        if(gamePattern[i] != userPattern[i]) {
            return false;
        }
    }
    
    return true;
}

void loop() {
    randomSeed(millis());
    switch (currentState){
        case INITIAL:
            potValue = 0;
            pattern = 2;
            pressed = digitalRead(GREEN_BTN);
            delay(15);
            if(pressed){
                getPattern();
                pressed = false;
                currentState = CREATE_PATTERN;
            }
            digitalWrite(RED_LED, HIGH);
            break;
        case CREATE_PATTERN:
            digitalWrite(RED_LED, LOW);
            delay(1000);

            indexUser = 0;

            for(int i = 0; i < pattern; i++){
                gamePattern[i] = LEDPINS[random(4)];
                delay(1000);
                digitalWrite(gamePattern[i], HIGH);
                delay(1000);
                digitalWrite(gamePattern[i], LOW);
            }

            timer->setupPeriod(6500);
            timerFlag = false;
            
            currentState = GAME_ON;
            break;
        case GAME_ON:
            while(indexUser < pattern && !timerFlag) {
                if(digitalRead(BLUE_BTN)) {
                    userPattern[indexUser] = BLUE_LED;
                    Serial.print("blue p");
                    indexUser++;
                    delay(150);
                }
                if(digitalRead(WHITE_BTN)) {
                    userPattern[indexUser] = WHITE_LED;
                    Serial.print("white p");
                    indexUser++;
                    delay(150);
                }
                if(digitalRead(GREEN_BTN)) {
                    userPattern[indexUser] = GREEN_LED;
                    Serial.print("green p");
                    indexUser++;
                    delay(150);
                }
                if(digitalRead(YELLOW_BTN)) {
                    userPattern[indexUser] = YELLOW_LED;
                    Serial.print("yellow p");
                    indexUser++;
                    delay(150);
                }
            }
            
            if(checkPattern()) {
                pattern++;
                Serial.write("Going to the next level!!! ");
                currentState = CREATE_PATTERN;
            } else {
                Serial.write("You lost!!! ");
                currentState = INITIAL;
            }

            timerFlag = false;
            break;
        }
    }
