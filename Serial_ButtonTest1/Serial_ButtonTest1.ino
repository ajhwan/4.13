int button1 = 7;
int button2 = 8;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  Serial.begin(9600);
}

void loop() {
  int buttonState1 = digitalRead(button1);
  if (buttonState1 == HIGH) {
    Serial.println("테스트 시작");
    while (1) {
      Serial.println("test");
      delay(1000);
      int buttonState2 = digitalRead(button2);
      if (buttonState2 == HIGH) {
        Serial.println("테스트 종료");
        delay(1000);
        break;
      }
    }
  }
}
