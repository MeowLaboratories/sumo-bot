
#define FrontLeft_prox_pin A0
#define FrontRight_prox_pin A1
#define right_prox_pin A2
#define left_prox_pin A3
#define mid_prox_pin A4

#define left_ir_pin A6
#define right_ir_pin A9

#define FL_motorA 22
#define FL_motorB 23
#define FR_motorA 25
#define FR_motorB 24
#define BL_motorA 9
#define BL_motorB 8
#define BR_motorA 7
#define BR_motorB 6

#define FL_pwm_pin 2
#define FR_pwm_pin 3
#define BL_pwm_pin 4
#define BR_pwm_pin 5

#define switch1 40
#define switch2 41
#define switch3 42

byte front_sonar,mid_prox,FL_prox,FR_prox,right_prox,left_prox; 
byte left_ir,right_ir;
int FRONT,LEFT,RIGHT,BACK,LINE;

int L_thres,R_thres;

int P,D,I,PID,last_P = 0;
int Kp = 1;
int Kd = 0;
int Ki = 0;
int prev = 1;

void setup() 
{
   //motor pin
   pinMode(FL_motorA,OUTPUT);
   pinMode(FL_motorB,OUTPUT);
   pinMode(FR_motorA,OUTPUT);
   pinMode(FR_motorB,OUTPUT);
   pinMode(BL_motorA,OUTPUT);
   pinMode(BL_motorB,OUTPUT);
   pinMode(BR_motorA,OUTPUT);
   pinMode(BR_motorB,OUTPUT);

   pinMode(FL_pwm_pin,OUTPUT);
   pinMode(FR_pwm_pin,OUTPUT);
   pinMode(BL_pwm_pin,OUTPUT);
   pinMode(BR_pwm_pin,OUTPUT);

   //switch

   pinMode(switch1,INPUT);
   pinMode(switch2,INPUT);
   pinMode(switch3,INPUT);
   
}

void loop() 
{
   //debug();
   
   RUN(255,255);
   cal();

   TORNADO();
    
}
