void debug()
{
  Serial.begin(38400);

  while (1)
  {
    //Serial.print((analogRead(FrontLeft_prox_pin) + analogRead(FrontLeft_prox_pin) + analogRead(FrontLeft_prox_pin) )/3);
    //Serial.print((analogRead(mid_prox_pin) + analogRead(mid_prox_pin) + analogRead(mid_prox_pin) )/3);
    //Serial.print("   ");
    //Serial.println(analogRead(A8));
    //Serial.println(sonar());
    //readGyro();
    //seeGyro();
    flip();
    
    //int puhi = 2;
    //if ( ax - ax_thres >= 1100 )ledDisplay(puhi);
    //else ledDisplay(puhi + 1);
    //writeeprom();
    int dis = sonar();
    Serial.println(dis);
    //debug_dis();
    delay(100);
  }
}

void debug_motor()
{
  RUN(255, 255);
  delay(1000);

  RUN(255, -255);
  delay(1000);

  RUN(-255, 255);
  delay(1000);

  RUN(100, 100);
  delay(1000);

  RUN(0, 0);
  delay(1000);
}

void debug_line()
{
  Serial.print(analogRead(left_ir_pin));
  Serial.print(" ");


  Serial.print(analogRead(right_ir_pin));
  Serial.println(" ");
}

void debug_dis()
{
  Serial.print(analogRead(FrontLeft_prox_pin ));
  Serial.print(" ");

  Serial.print(analogRead(mid_prox_pin));
  Serial.print(" ");

  Serial.print(analogRead(FrontRight_prox_pin ));
  Serial.print(" ");

  Serial.print(analogRead(left_prox_pin));
  Serial.print(" ");

  Serial.print(analogRead(right_prox_pin));
  Serial.println(" ");

}

void seeGyro()
{
#ifdef OUTPUT_READABLE_ACCELGYRO
  // display tab-separated accel/gyro x/y/z values
  Serial.print("a/g:\t");
  //Serial.print(ax); Serial.print("\t");
  //Serial.print(ay); Serial.print("\t");
  //Serial.println(az); Serial.print("\t");
  //Serial.print(gx); Serial.print("\t");
  //Serial.print(gy); Serial.print("\t");
  Serial.println(gz);//front
#endif
}

void writeeprom()
{
  int a;
  RUN(255,-255);
  for ( a = 500; a < 1000 ; a++)
  {
    readGyro();
    EEPROM.write(a, ax);
  }

  while(1)
  {
    RUN(0,0);
  }
}

