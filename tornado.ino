void TORNADO()
{
  int flag = 1;
  long kiKoro = 0;
  int safetyFlag = 0;
  unsigned long curTimeSafe, endTimeSafe;

  while (1)
  {
    status_update();

    if (LINE)
    {
      RUN(-255, -255);
      delay(200);
    }

    if (FRONT == 0b000 && flag == 1)
    {
      RUN(255, -255);
    }

    else if (FRONT == 0b000 && flag == -1)
    {
      RUN(-255, 255);
    }

    else if (FRONT == 0b111  )
    {
      RUN(255, 255);
      kiKoro = 0;

      checkGyro();
    }

    else if (FRONT == 0b110  )
    {
      if (kiKoro < 40)
        RUN(150, 255);
      else if (kiKoro < 80 && kiKoro >= 40)
        RUN( 255, 255);
      else
        RUN(-255, 255);

      flag = -1;
      kiKoro++;

      checkGyro();
    }

    else if ( FRONT == 0b100  )
    {
      if (kiKoro < 40)
        RUN(100, 255);
      else if (kiKoro < 80 && kiKoro >= 40)
        RUN( 255, 255);
      else
        RUN(-255, 255);

      //RUN(100,255);
      flag = -1;
      kiKoro++;

      checkGyro();
    }

    else if (FRONT == 0b011)
    {
      if (kiKoro < 40)
        RUN(255, 150);
      else if (kiKoro < 80 && kiKoro >= 40)
        RUN(255, 255);
      else
        RUN(255, -255);
      //RUN(255,150);
      flag = 1;
      kiKoro++;

      checkGyro();
    }

    else if (FRONT == 0b001)
    {
      if (kiKoro < 40)
        RUN(255, 100);
      else if (kiKoro < 80 && kiKoro >= 40)
        RUN( 255, 255);
      else
        RUN(255, -255);

      //RUN(255,100);
      flag = 1;
      kiKoro++;

      checkGyro();
    }


    else
    {
      if (flag == 1) RUN(255, -255);
      else RUN(-255, 255);
    }

    if ((back_ir1 + back_ir2) > 0)
    {
      if (back_ir1 == 1)
      {
        status_update();
        while (FRONT)
        {
          RUN(240, 255);
          status_update();
        }
      }
      else
      {
        status_update();
        while (FRONT)
        {
          RUN(255, 240);
          status_update();
        }
      }
    }


    delay(50);
  }
}


void checkGyro()
{
  return;
  
  if( ((analogRead(mid_prox_pin) + analogRead(mid_prox_pin) + analogRead(mid_prox_pin) ) / 3 )  > 550 )
  {
    readGyro();
    //clear, going
    //disturbed
    //else ledDisplay(5); //back
    while(gz > -4000)
    {
      readGyro();
      RUN(255,255);
    }

    RUN(0,0);
    delay(1000000);
    
   }


  //  if (equFlag == 0)
  //  {
  //    if (gz < 3000)checkGyroTime++;
  //    else
  //    {
  //      checkGyroTime--;
  //      if (checkGyroTime <= 0) checkGyroTime = 0;
  //    }
  //
  //    if (checkGyroTime > 30)
  //    {
  //      RUN(+150, -255);
  //      delay(500);
  //      RUN(-255, -255);
  //      delay(300);
  //      RUN(255, 255);
  //      delay(50);
  //
  //      equFlag = 1;
  //    }
  //  }
}

//
//    readGyro();
//    if (ax - ax_thres >= 3000)
//    {
//      while (ax - ax_thres >= 1000)
//      {
//        readGyro();
//        RUN(-255, -255);
//
//        status_update();
//        if ((back_ir1 + back_ir2) > 0)
//        {
//            status_update();
//            while (FRONT)
//            {
//              RUN(255, 255);
//              status_update();
//            }
//        }
//      }
//    }



//
//    readGyro();
//    if (ax - ax_thres >= 3000)
//    {
//      while (ax - ax_thres >= 1000)
//      {
//        readGyro();
//        RUN(-255, -255);
//
//        status_update();
//        if ((back_ir1 + back_ir2) > 0)
//        {
//            status_update();
//            while (FRONT)
//            {
//              RUN(255, 255);
//              status_update();
//            }
//        }
//      }
//    }
