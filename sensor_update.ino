void status_update()
{
  int thres = 200;

   //ir prox
   if(((analogRead(FrontLeft_prox_pin)+analogRead(FrontLeft_prox_pin)+analogRead(FrontLeft_prox_pin))/3) > thres)
    FL_prox = 1; 
   else
   FL_prox = 0;

         if(((analogRead(FrontRight_prox_pin) + analogRead(FrontRight_prox_pin) + analogRead(FrontRight_prox_pin) )/3) > thres)
          FR_prox = 1; 
         else
         FR_prox = 0;

               if(((analogRead(right_prox_pin)+analogRead(right_prox_pin)+analogRead(right_prox_pin))/3) > thres)
                right_prox = 1; 
               else
               right_prox = 0;

                       if(((analogRead(left_prox_pin)+analogRead(left_prox_pin)+analogRead(left_prox_pin))/3) > thres)
                        left_prox = 1; 
                       else
                       left_prox = 0;

                                 if(((analogRead(mid_prox_pin)+analogRead(mid_prox_pin)+analogRead(mid_prox_pin))/3) > thres)
                                 mid_prox = 1; 
                                 else
                                 mid_prox = 0;


    //line sensor
   if(analogRead(left_ir_pin) > L_thres) left_ir = 1;
   else
   left_ir = 0;
                     if(analogRead(right_ir_pin) > R_thres) right_ir = 1;
                     else
                     right_ir = 0;


   FRONT = FL_prox*4 + mid_prox*2 + FR_prox;

   LINE = left_ir*2 + right_ir; 
}

int read_env()
{
  if(FRONT == 0b000 && prev == 1)
  {
    return 150;
  }

  if(FRONT == 0b000 && prev == -1)
  {
    return -150;
  }

  if(FRONT == 0b001)
  {
    prev = 1;
    return 100;
  }

   if(FRONT == 0b011)
  {
    prev = 1;
    return 50;
  }

   if(FRONT == 0b101 || FRONT == 0b010 || FRONT == 0b111)
  {
    return 0;
  }

  if(FRONT == 0b110)
  {
    prev = -1;
    return -50;
  }

  if(FRONT == 0b100)
  {
    prev = -1;
    return -100;
  }
}

