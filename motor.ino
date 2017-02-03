void RUN(int l,int r)
{
  if(l < 0)
  {
    l = l * (-1);
    digitalWrite(FL_motorA,LOW);
    digitalWrite(FL_motorB,HIGH);

    analogWrite(FL_pwm_pin,l);

    digitalWrite(BL_motorA,LOW);
    digitalWrite(BL_motorB,HIGH);

    analogWrite(BL_pwm_pin,l);
  }

  else if(l >= 0)
  {
    digitalWrite(FL_motorA,HIGH);
    digitalWrite(FL_motorB,LOW);

    analogWrite(FL_pwm_pin,l);

    digitalWrite(BL_motorA,HIGH);
    digitalWrite(BL_motorB,LOW);

    analogWrite(BL_pwm_pin,l);
  }

  if(r < 0)
  {
    r = r * (-1);
    digitalWrite(FR_motorA,LOW);
    digitalWrite(FR_motorB,HIGH);

    analogWrite(FR_pwm_pin,r);

    digitalWrite(BR_motorA,LOW);
    digitalWrite(BR_motorB,HIGH);

    analogWrite(BR_pwm_pin,r);
  }

  else if(r >= 0)
  {
    digitalWrite(FR_motorA,HIGH);
    digitalWrite(FR_motorB,LOW);

    analogWrite(FR_pwm_pin,r);

    digitalWrite(BR_motorA,HIGH);
    digitalWrite(BR_motorB,LOW);

    analogWrite(BR_pwm_pin,r);
  }
}

