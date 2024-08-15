#include <AFMotor.h> // นำเข้าไลบรารีสำหรับควบคุมมอเตอร์ DC

// นิยามมอเตอร์ 4 ตัว โดยกำหนดหมายเลขมอเตอร์และความถี่ในการควบคุม PWM
AF_DCMotor motor1(1, MOTOR12_1KHZ); // มอเตอร์ซ้ายหน้า
AF_DCMotor motor2(2, MOTOR12_1KHZ); // มอเตอร์ขวาหน้า
AF_DCMotor motor3(3, MOTOR34_1KHZ); // มอเตอร์ซ้ายหลัง
AF_DCMotor motor4(4, MOTOR34_1KHZ); // มอเตอร์ขวาหลัง

int speed = 255; // กำหนดความเร็วเริ่มต้นของมอเตอร์ที่ 255 (สูงสุด)

void setup() {
  Serial.begin(9600); // เริ่มการสื่อสาร Serial ที่ความเร็ว 9600 baud สำหรับการดีบัก
}

void loop() {
  // เรียกใช้ฟังก์ชันควบคุมการเคลื่อนไหวต่าง ๆ โดยมีการหน่วงเวลาหลังจากการเคลื่อนไหวแต่ละครั้ง
  forward();
  delay(3000); // หน่วงเวลา 3 วินาที
  backward();
  delay(3000);
  left();
  delay(3000);
  right();
  delay(3000);
  forward_right();
  delay(3000);
  forward_left();
  delay(3000);
  backward_right();
  delay(3000);
  backward_left();
  delay(3000);
  turning_right();
  delay(3000);
  turning_left();
  delay(3000);
  stop();
  delay(3000);
}

// ฟังก์ชันเดินหน้าทั้ง 4 มอเตอร์
void forward() {
  motor1.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(FORWARD);    // หมุนมอเตอร์ไปข้างหน้า
  motor2.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(FORWARD);    // หมุนมอเตอร์ไปข้างหน้า
  motor3.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(FORWARD);    // หมุนมอเตอร์ไปข้างหน้า
  motor4.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(FORWARD);    // หมุนมอเตอร์ไปข้างหน้า
}

// ฟังก์ชันถอยหลังทั้ง 4 มอเตอร์
void backward() {
  motor1.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(BACKWARD);   // หมุนมอเตอร์ถอยหลัง
  motor2.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(BACKWARD);   // หมุนมอเตอร์ถอยหลัง
  motor3.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(BACKWARD);   // หมุนมอเตอร์ถอยหลัง
  motor4.setSpeed(speed); // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(BACKWARD);   // หมุนมอเตอร์ถอยหลัง
}

// ฟังก์ชันเลี้ยวขวา
void right() {
  motor1.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor2.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor3.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor4.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
}

// ฟังก์ชันเลี้ยวซ้าย
void left() {
  motor1.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor2.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor3.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor4.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
}

// ฟังก์ชันเดินหน้าและเลี้ยวขวาเล็กน้อย
void forward_right() {
  motor1.setSpeed(0);      // หยุดมอเตอร์ซ้ายหน้า
  motor1.run(RELEASE);     // ปล่อยมอเตอร์ซ้ายหน้า
  motor2.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor3.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor4.setSpeed(0);      // หยุดมอเตอร์ขวาหลัง
  motor4.run(RELEASE);     // ปล่อยมอเตอร์ขวาหลัง
}

// ฟังก์ชันเดินหน้าและเลี้ยวซ้ายเล็กน้อย
void forward_left() {
  motor1.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor2.setSpeed(0);      // หยุดมอเตอร์ขวาหน้า
  motor2.run(RELEASE);     // ปล่อยมอเตอร์ขวาหน้า
  motor3.setSpeed(0);      // หยุดมอเตอร์ซ้ายหลัง
  motor3.run(RELEASE);     // ปล่อยมอเตอร์ซ้ายหลัง
  motor4.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
}

// ฟังก์ชันถอยหลังและเลี้ยวขวาเล็กน้อย
void backward_right() {
  motor1.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor2.setSpeed(0);      // หยุดมอเตอร์ขวาหน้า
  motor2.run(RELEASE);     // ปล่อยมอเตอร์ขวาหน้า
  motor3.setSpeed(0);      // หยุดมอเตอร์ซ้ายหลัง
  motor3.run(RELEASE);     // ปล่อยมอเตอร์ซ้ายหลัง
  motor4.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
}

// ฟังก์ชันถอยหลังและเลี้ยวซ้ายเล็กน้อย
void backward_left() {
  motor1.setSpeed(0);      // หยุดมอเตอร์ซ้ายหน้า
  motor1.run(RELEASE);     // ปล่อยมอเตอร์ซ้ายหน้า
  motor2.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor3.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor4.setSpeed(0);      // หยุดมอเตอร์ขวาหลัง
  motor4.run(RELEASE);     // ปล่อยมอเตอร์ขวาหลัง
}

// ฟังก์ชันหมุนรอบตัวไปทางขวา
void turning_right() {
  motor1.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor2.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor3.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor4.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
}

// ฟังก์ชันหมุนรอบตัวไปทางซ้าย
void turning_left() {
  motor1.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหน้า
  motor1.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor2.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหน้า
  motor2.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
  motor3.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ซ้ายหลัง
  motor3.run(BACKWARD);    // หมุนมอเตอร์ถอยหลัง
  motor4.setSpeed(speed);  // กำหนดความเร็วของมอเตอร์ขวาหลัง
  motor4.run(FORWARD);     // หมุนมอเตอร์ไปข้างหน้า
}

// ฟังก์ชันหยุดมอเตอร์ทุกตัว
void stop() {
  motor1.setSpeed(0); // หยุดมอเตอร์ซ้ายหน้า
  motor1.run(RELEASE); // ปล่อยมอเตอร์ซ้ายหน้า
  motor2.setSpeed(0); // หยุดมอเตอร์ขวาหน้า
  motor2.run(RELEASE); // ปล่อยมอเตอร์ขวาหน้า
  motor3.setSpeed(0); // หยุดมอเตอร์ซ้ายหลัง
  motor3.run(RELEASE); // ปล่อยมอเตอร์ซ้ายหลัง
  motor4.setSpeed(0); // หยุดมอเตอร์ขวาหลัง
  motor4.run(RELEASE); // ปล่อยมอเตอร์ขวาหลัง
}
