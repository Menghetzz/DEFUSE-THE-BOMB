#define BLUE_LED_PIN 12
#define BLUE_LED_BTN 13

#define WHITE_LED_PIN 10
#define WHITE_LED_BTN 11

#define YELLOW_LED_PIN 8
#define YELLOW_LED_BTN 9

#define GREEN_LED_PIN 7
#define GREEN_LED_BTN 6

#define RED_LED_PIN 2

#define POT_PIN A0

void setup() {
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
    Serial.begin(115200);

}

void loop() {

}
