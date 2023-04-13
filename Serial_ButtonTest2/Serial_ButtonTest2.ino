int button1 = 7;
int button2 = 8;
int cds = A1;

void setup() {
  pinMode(button1, INPUT);
  pinMode(button2, INPUT);
  pinMode(cds, INPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  int buttonState1 = digitalRead(button1);
  if (buttonState1 == HIGH) {
    Serial.println("테스트 시작");
    while (1) {
      cds = analogRead(A1);
      Serial.print("CDS_Sensor: ");
      Serial.println(cds);
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
