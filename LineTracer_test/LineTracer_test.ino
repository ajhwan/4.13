const int motor_A1 = 5;
const int motor_A2 = 6;
const int motor_B1 = 9;
const int motor_B2 = 10;
const int IR_R = A1;
const int IR_M = A3;
const int IR_L = A5;
int IR_L_data;
int IR_M_data;
int IR_R_data;

int speed_A = 255; // 모터A의 속도
int speed_B = 255; // 모터B의 속도

void setup() {
  pinMode(motor_A1, OUTPUT);
  pinMode(motor_A2, OUTPUT);
  pinMode(motor_B1, OUTPUT);
  pinMode(motor_B2, OUTPUT);
  pinMode(IR_L, INPUT);
  pinMode(IR_M, INPUT);
  pinMode(IR_R, INPUT);
  Serial.begin(9600);
  Serial.print("Start");
}

void loop() {
  IR_L_data = digitalRead(IR_L);
  IR_M_data = digitalRead(IR_M);
  IR_R_data = digitalRead(IR_R);
  // Serial.print(IR_L_data);
  // Serial.print("-");
  // Serial.print(IR_M_data);
  // Serial.print("-");
  // Serial.println(IR_R_data);
  
  if (IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 0) {
    // Serial.println("직진");
    forward(speed_A, speed_B);
  }
  else if (IR_L_data == 1 and IR_M_data == 0 and IR_R_data == 0) {
    // Serial.println("좌회전");
    left(speed_A*0.8, speed_B);
  }
  else if (IR_L_data == 1 and IR_M_data == 1 and IR_R_data == 0) {
    // Serial.println("좌회전");
    left(speed_A*0.8, speed_B);
  }
  else if (IR_L_data == 0 and IR_M_data == 0 and IR_R_data == 1) {
    // Serial.println("우회전");
    right(speed_A, speed_B*0.8);
  }
  else if (IR_L_data == 0 and IR_M_data == 1 and IR_R_data == 1) {
    // Serial.println("우회전");
    right(speed_A, speed_B*0.8);
  }
  else if (IR_L_data == 1  and IR_R_data == 1) {
    Serial.println("정지");
    stop();
  //   unsigned long time = millis();
  //   Serial.print("time : ");
  //   Serial.println(time);
  //   while (time > 1000){
  //     unsigned long time1 = millis();
  //     Serial.print("time1 : ");
  //     Serial.println(time1);
  //     backward(speed_A, speed_B);
  //     if (time1 >= 2000){
  //       millis() = 0;
  //       //time1 = 0; 
  //       break;
  //     }
  //     millis() = 0;
  //     time1 = 0; 
  //   }
  //   millis() = 0;
  //   time = 0;
  //   stop();
  }
}

void right(int speed_A, int speed_B) {
  // 우회전
  analogWrite(motor_A1, speed_A);
  analogWrite(motor_A2, LOW);
  analogWrite(motor_B1, LOW);
  analogWrite(motor_B2, speed_B);
}

void left(int speed_A, int speed_B) {
  // 좌회전
  analogWrite(motor_A1, LOW);
  analogWrite(motor_A2, speed_A);
  analogWrite(motor_B1, speed_B);
  analogWrite(motor_B2, LOW);
}

void forward(int speed_A, int speed_B) {
  // 전진
  analogWrite(motor_A1, speed_A);
  analogWrite(motor_A2, LOW);
  analogWrite(motor_B1, speed_B);
  analogWrite(motor_B2, LOW);
}

void backward(int speed_A, int speed_B) {
  // 후진
  analogWrite(motor_A1, LOW);
  analogWrite(motor_A2, speed_A);
  analogWrite(motor_B1, LOW);
  analogWrite(motor_B2, speed_B);
}

void stop() {
  analogWrite(motor_A1, LOW);
  analogWrite(motor_A2, LOW);
  analogWrite(motor_B1, LOW);
  analogWrite(motor_B2, LOW);
}