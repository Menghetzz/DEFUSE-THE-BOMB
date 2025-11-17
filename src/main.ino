#include "Arduino.h"
#include "Timer.h"
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

Timer* timer;

enum States {INITIAL, CREATE_PATTERN, GAME_ON};
States currentState;

enum Levels {L1 = 1, L2 = 2, L3 = 3};
const int DIFFRANGE = 86;
const int MAX_PATTERN = 100;

int potValue;
int pattern;
int score;
bool pressed = false;
int diffMap;
const int LEDPINS[] = {WHITE_LED, BLUE_LED, YELLOW_LED, GREEN_LED};
int gamePattern[MAX_PATTERN];
int userPattern[MAX_PATTERN];

int indexUser;
int count = 0;

void setup() {
    Serial.begin(115200);
    pinSetup();

    currentState = INITIAL;
    
    randomSeed(millis());

    timer = new Timer();
}

// Function to determine the starting pattern based on the difficulty chosen@
void getPattern (){
    potValue = analogRead(POT_PIN);
    diffMap = map(potValue, 0, 1023, 0, 255);
    diffMap = (diffMap / DIFFRANGE) + 1;

    switch(diffMap) {
        case L1:
            pattern += L1;
            Serial.println("You chose EASY MODE");
            break;

        case L2:
            pattern += L2;
            Serial.println("You chose MEDIUM MODE");
            break;

        case L3:
            pattern += L3;
            Serial.println("You chose HARD MODE");
            break;
    }
}

// Function that checks if the user pattern corresponds to the game pattern
bool checkPattern(){
    for(int i = 0; i < pattern; i++) {
        if(gamePattern[i] != userPattern[i]) {
            return false;
        }
    }
    
    return true;
}

void loop() {
    switch (currentState){
        case INITIAL:
            potValue = 0;
            pattern = 1;
            score = 0;
            pressed = digitalRead(GREEN_BTN);
            if(count == 0) {
                Serial.println("== GAME STARTED ==");
                Serial.println("---- Rotate left for EASY MODE ---- ");
                Serial.println("---- Rotate in center for MEDIUM MODE ----");
                Serial.println("---- Rotate right for HARD MODE ----");
                Serial.println("");
                Serial.println("== Press the green button for start ==");
                count++;
            }
            delay(15);

            // Pressing the green button determines state change
            if(pressed){ 
                getPattern();
                pressed = false;
                currentState = CREATE_PATTERN;
                Serial.println("BOMB ACTIVATED. Watch out to the pattern.");
            }
            digitalWrite(RED_LED, HIGH);
            break;
        case CREATE_PATTERN: 
            digitalWrite(RED_LED, LOW);
            delay(1000);

            indexUser = 0;

            // Here the pattern gets created, saved and shown
            for(int i = 0; i < pattern; i++){
                gamePattern[i] = LEDPINS[random(4)];
                delay(1000);
                digitalWrite(gamePattern[i], HIGH);
                delay(1000);
                digitalWrite(gamePattern[i], LOW);
            }

            // Timer starts here
            timer->setupPeriod(6500);
            timerFlag = false;
            
            currentState = GAME_ON;
            Serial.println("You now have to recreate the pattern. Be aware of time!");
            break;
        case GAME_ON:
            // Loop-parser for user input; all inputs get then saved in an array
            while(indexUser < pattern && !timerFlag) {
                if(digitalRead(BLUE_BTN)) {
                    userPattern[indexUser] = BLUE_LED;
                    Serial.println("blue button pressed");
                    indexUser++;
                    delay(150);
                }
                if(digitalRead(WHITE_BTN)) {
                    userPattern[indexUser] = WHITE_LED;
                    Serial.println("white button pressed");
                    indexUser++;
                    delay(150);
                }
                if(digitalRead(GREEN_BTN)) {
                    userPattern[indexUser] = GREEN_LED;
                    Serial.println("green button pressed");
                    indexUser++;
                    delay(150);
                }
                if(digitalRead(YELLOW_BTN)) {
                    userPattern[indexUser] = YELLOW_LED;
                    Serial.println("yellow button pressed");
                    indexUser++;
                    delay(150);
                }
            }
            
            // Last state guard
            // Inputing the correct pattern increases score and pattern difficulty
            
            if(checkPattern()) {
                pattern++;
                score++;
                Serial.println("Correct, moving to the next pattern, increased by one.");
                currentState = CREATE_PATTERN;
            } else {
                Serial.print("BOOM! You failed! Score: ");
                Serial.println(score * diffMap);
                Serial.println("---------------------------------");
                count = 0;
                currentState = INITIAL;
                digitalWrite(RED_LED, HIGH);
                delay(3000);
                digitalWrite(RED_LED, LOW);
            }

            timerFlag = false;
            break;
        }
    }