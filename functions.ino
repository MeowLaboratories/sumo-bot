void follow()
{
  int ls,rs;
  
  P = read_env();
  D = P - last_P;

  PID = P*Kp + D*Kd + I*Ki;

  last_P = P;

  ls = 255 + PID;
  rs = 255 - PID;

  if(ls > 255) ls = 255;
  if(ls < -255) ls = -255 ;

  if(rs > 255) rs = 255;
  if(rs < -255) rs = -255 ;

  RUN(ls,rs);
}

void cal()
{
  unsigned long cur_time,end_time;

  cur_time = millis();
  end_time = cur_time + 1000;

   L_thres = 0;
   R_thres = 0;

   int val;

  while(cur_time < end_time)
  {
    cur_time = millis();

    val = analogRead(left_ir_pin) ; 
    if( val > L_thres) L_thres = val;

    val = analogRead(right_ir_pin) ; 
    if( val > R_thres) R_thres = val;
  }

  L_thres += 250;
  R_thres += 250; 
}

