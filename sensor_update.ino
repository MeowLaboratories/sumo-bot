void status_update()
{
  int thres = 200;

  //ir prox
  if (((analogRead(FrontLeft_prox_pin) + analogRead(FrontLeft_prox_pin) + analogRead(FrontLeft_prox_pin)) / 3) > thres)
    FL_prox = 1;
  else
    FL_prox = 0;

  if (((analogRead(FrontRight_prox_pin) + analogRead(FrontRight_prox_pin) + analogRead(FrontRight_prox_pin) ) / 3) > thres)
    FR_prox = 1;
  else
    FR_prox = 0;

  if (((analogRead(right_prox_pin) + analogRead(right_prox_pin) + analogRead(right_prox_pin)) / 3) > thres)
    right_prox = 1;
  else
    right_prox = 0;

  if (((analogRead(left_prox_pin) + analogRead(left_prox_pin) + analogRead(left_prox_pin)) / 3) > thres)
    left_prox = 1;
  else
    left_prox = 0;

  if (((analogRead(mid_prox_pin) + analogRead(mid_prox_pin) + analogRead(mid_prox_pin)) / 3) > thres)
    mid_prox = 1;
  else
    mid_prox = 0;


  //line sensor
  if (analogRead(left_ir_pin) > L_thres) left_ir = 1;
  else
    left_ir = 0;
  if (analogRead(right_ir_pin) > R_thres) right_ir = 1;
  else
    right_ir = 0;

  if (analogRead(back_ir_pin1) < B_thres1) back_ir1 = 1;
  else
    back_ir1 = 0;

  if (analogRead(back_ir_pin2) < B_thres2) back_ir2 = 1;
  else
    back_ir2 = 0;


  FRONT = FL_prox * 4 + mid_prox * 2 + FR_prox;

  LINE = left_ir * 2 + right_ir;
}

int read_env()
{
  if (FRONT == 0b000 && prev == 1)
  {
    return 150;
  }

  if (FRONT == 0b000 && prev == -1)
  {
    return -150;
  }

  if (FRONT == 0b001)
  {
    prev = 1;
    return 100;
  }

  if (FRONT == 0b011)
  {
    prev = 1;
    return 50;
  }

  if (FRONT == 0b101 || FRONT == 0b010 || FRONT == 0b111)
  {
    return 0;
  }

  if (FRONT == 0b110)
  {
    prev = -1;
    return -50;
  }

  if (FRONT == 0b100)
  {
    prev = -1;
    return -100;
  }
}

int sonar()
{
  long duration, distance;
  //wall sonar update
  digitalWrite(trig, LOW);  // Added this line
  delayMicroseconds(2); // Added this line
  digitalWrite(trig, HIGH);

  delayMicroseconds(10); // Added this line
  digitalWrite(trig, LOW);
  duration = pulseIn(echo, HIGH);
  distance = (duration / 2) / 29.1;

  return distance;
}

void readGyro()
{
  accelgyro.getMotion6(&ax, &ay, &az, &gx, &gy, &gz);

  // these methods (and a few others) are also available
  //accelgyro.getAcceleration(&ax, &ay, &az);
  //accelgyro.getRotation(&gx, &gy, &gz);

#ifdef OUTPUT_BINARY_ACCELGYRO
  Serial.write((uint8_t)(ax >> 8)); Serial.write((uint8_t)(ax & 0xFF));
  Serial.write((uint8_t)(ay >> 8)); Serial.write((uint8_t)(ay & 0xFF));
  Serial.write((uint8_t)(az >> 8)); Serial.write((uint8_t)(az & 0xFF));
  Serial.write((uint8_t)(gx >> 8)); Serial.write((uint8_t)(gx & 0xFF));
  Serial.write((uint8_t)(gy >> 8)); Serial.write((uint8_t)(gy & 0xFF));
  Serial.write((uint8_t)(gz >> 8)); Serial.write((uint8_t)(gz & 0xFF));
#endif

  // blink LED to indicate activity
  blinkState = !blinkState;
  digitalWrite(LED_PIN, blinkState);
  
}


