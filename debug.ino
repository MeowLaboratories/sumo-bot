void debug()
{
  Serial.begin(9600);

  while(1)
  {
     status_update();
     Serial.println(FRONT);
  }
}

void debug_motor()
{
    RUN(255,255);
    delay(1000);

    RUN(255,-255);
    delay(1000);

    RUN(-255,255);
    delay(1000);

    RUN(100,100);
    delay(1000);

    RUN(0,0);
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

