void follow()
{
  int ls, rs;

  P = read_env();
  D = P - last_P;

  PID = P * Kp + D * Kd + I * Ki;

  last_P = P;

  ls = 255 + PID;
  rs = 255 - PID;

  if (ls > 255) ls = 255;
  if (ls < -255) ls = -255 ;

  if (rs > 255) rs = 255;
  if (rs < -255) rs = -255 ;

  RUN(ls, rs);
}

void cal(int tim)
{
  unsigned long cur_time, end_time;

  cur_time = millis();
  end_time = cur_time + tim;

  L_thres = 0;
  R_thres = 0;
  B_thres1 = 1024;
  B_thres2 = 1024;

  int val;

  while (cur_time < end_time)
  {
    cur_time = millis();

    val = analogRead(left_ir_pin) ;
    if ( val > L_thres) L_thres = val;

    val = analogRead(right_ir_pin) ;
    if ( val > R_thres) R_thres = val;

    val = analogRead(back_ir_pin1) ;
    if ( val < B_thres1) B_thres1 = val;

    val = analogRead(back_ir_pin2) ;
    if ( val < B_thres2) B_thres2 = val;
  }

  L_thres += 250;
  R_thres += 250;
  B_thres1 -= 250;
  B_thres2 -= 250;
}

void cal_gyro(int tim)
{
  unsigned long cur_time, end_time;

  cur_time = millis();
  end_time = cur_time + tim;

  ax_thres = 0;
//  gz_thres = 0;

  readGyro();
  int ax_min = ax;
  int ax_max = ax; 

  int val;

  while (cur_time < end_time)
  {
    cur_time = millis();
    readGyro();
    
    val = ax ;
    if ( val > ax_max) ax_max = val;
    if ( val < ax_min) ax_min = val;
  }

  ax_thres = ax_max;
}

///eikhane accelarator hoilo gyro ar gyro hoilo accelarator
