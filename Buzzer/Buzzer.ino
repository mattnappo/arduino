int BUZZER_PIN = 12;

void setup() {
    pinMode(BUZZER_PIN, OUTPUT);
}

void loop() {
    while (1) {
        digitalWritea(BUZZER_PIN, HIGH);
        delay(100);
        digitalWrite(BUZZER_PIN, LOW);
        delay(100);
    }
}