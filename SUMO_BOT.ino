#include "I2Cdev.h"
#include "MPU6050.h"
#include <EEPROM.h>
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
#include "Wire.h"
#endif

MPU6050 accelgyro(0x69); // <-- use for AD0 high

int16_t ax, ay, az;
int16_t gx, gy, gz;
int16_t ax_thres;

#define OUTPUT_READABLE_ACCELGYRO

#define LED_PIN 13
bool blinkState = false;
//gyro
//
#define FrontLeft_prox_pin A6
#define FrontRight_prox_pin A4
#define right_prox_pin A3
#define left_prox_pin A7
#define mid_prox_pin A5
#define back_prox_pin A8

#define trig 40
#define echo 41

#define left_ir_pin A9
#define right_ir_pin A10
#define back_ir_pin1 A2
#define back_ir_pin2 A1

#define FL_motorA 27
#define FL_motorB 26
#define FR_motorA 29
#define FR_motorB 28
#define BL_motorA 8
#define BL_motorB 9
#define BR_motorA 11
#define BR_motorB 10 //was 6

#define FL_pwm_pin 6 //was 2
#define FR_pwm_pin 7
#define BL_pwm_pin 5
#define BR_pwm_pin 12

///in d 29 fr ri for
//in c 28 fr righ bac
//inb 26 fr lef bac
//ina 27 fr lef for
//enb 7 for right pwm
//ena 6 fr left pwm

//in a 8 bac lef for
//in b 9 bac lef back
//in c 11 bac righ for
//in d 10 bac righ bac
//en b 12 bac rig pwm
//en a 5 bac lef pwm

#define switch1 53
#define switch2 52
#define switch3 51
#define switch4 50

int front_sonar, mid_prox, FL_prox, FR_prox, right_prox, left_prox, back_prox;
int left_ir, right_ir, back_ir1, back_ir2;
int FRONT, LEFT, RIGHT, BACK, LINE;

int L_thres, R_thres, B_thres1, B_thres2;

int P, D, I, PID, last_P = 0;
int Kp = 2;
int Kd = 0;
int Ki = 0;
int prev = 1;

int equFlag = 0;
int checkGyroTime = 0;

void setup()
{
  //gyroSetup();

  //motor pin
  pinMode(FL_motorA, OUTPUT);
  pinMode(FL_motorB, OUTPUT);
  pinMode(FR_motorA, OUTPUT);
  pinMode(FR_motorB, OUTPUT);
  pinMode(BL_motorA, OUTPUT);
  pinMode(BL_motorB, OUTPUT);
  pinMode(BR_motorA, OUTPUT);
  pinMode(BR_motorB, OUTPUT);

  pinMode(FL_pwm_pin, OUTPUT);
  pinMode(FR_pwm_pin, OUTPUT);
  pinMode(BL_pwm_pin, OUTPUT);
  pinMode(BR_pwm_pin, OUTPUT);

  //switch

  pinMode(switch1, INPUT);
  pinMode(switch2, INPUT);
  pinMode(switch3, INPUT);
  pinMode(switch4, INPUT);

  //sonar
  pinMode(trig, OUTPUT);
  pinMode(echo, INPUT);

  //ardu led
  pinMode(LED_PIN, OUTPUT);
  DDRL = 0xFF;
  PORTL = 0xFF;

}

void loop()
{
  //1,a,b,c,d,4,h
  //readGyro();
  //debug();

  //cal_gyro();
  //debug();

  if(digitalRead(switch2) == LOW && digitalRead(switch3) == LOW && digitalRead(switch4) == LOW) ledDisplay(1); //tornado dan
  if(digitalRead(switch2) == HIGH && digitalRead(switch3) == LOW && digitalRead(switch4) == LOW) ledDisplay(2);//tornado left
  if(digitalRead(switch2) == LOW && digitalRead(switch3) == HIGH && digitalRead(switch4) == LOW) ledDisplay(3);//tornado dan jagay
  if(digitalRead(switch2) == HIGH && digitalRead(switch3) == HIGH && digitalRead(switch4) == LOW) ledDisplay(4); //tornado bam jaygay 
  if(digitalRead(switch4) == HIGH) ledDisplay(5); //random


  
  if (digitalRead(switch1) == HIGH)
  {
    //ledDisplay(1);
    RUN(0, 0);
    //cal_gyro(1000);
  }
  else
  {
    RUN(0, 0);
    //ledDisplay(2);
    //cal_gyro(4200);
    delay(4200);
  }

  if (digitalRead(switch2) == HIGH && digitalRead(switch4) == LOW)
  {
    //ledDisplay(2);
    RUN(-255, 255);
    delay(350);
    //cal_gyro(350);
  }
  else if (digitalRead(switch2) == LOW && digitalRead(switch4) == LOW)
  {
    //ledDisplay(4);
    RUN(255, -255);
    delay(350);
    //cal_gyro(350);
  }

  if(digitalRead(switch3) == HIGH)
  {
    if(digitalRead(switch2) == HIGH) RUN(-255,255);
    else RUN(255,-255);
  }

  else RUN(255,255);
  
  

  //follow();
  if(digitalRead(switch4) == LOW)
    {
      cal(500);
      TORNADO();
    }
  else
  {
   RUN(255, -255);
   cal(300);
   randomRun();
  }
}

void ledDisplay(int n)
{
  int digit[10] = {0b11111001, 0b10000011, 0b10100111, 0b10100001, 0b10011001, 0b10001001, 0b11111111};

  PORTL = digit[n - 1];
  //int word[5]={0x88,0x83,0xC6,0xA1,0x86};
}

void gyroSetup()
{
  //gyyro
#if I2CDEV_IMPLEMENTATION == I2CDEV_ARDUINO_WIRE
  Wire.begin();
#elif I2CDEV_IMPLEMENTATION == I2CDEV_BUILTIN_FASTWIRE
  Fastwire::setup(400, true);
#endif

  //Serial.begin(38400);

  // initialize device
  Serial.println("Initializing I2C devices...");
  accelgyro.initialize();

  // verify connection
  Serial.println("Testing device connections...");
  Serial.println(accelgyro.testConnection() ? "MPU6050 connection successful" : "MPU6050 connection failed");

}


