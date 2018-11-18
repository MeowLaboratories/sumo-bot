void randomRun()
{
  int kiKoro = 0;
  int flag = 1;
  unsigned long curTime, endTime;

  while (1)
  {
    status_update();
    long dis = sonar();

    RUN(255, 255);

    if (LINE)
    {
      RUN(-255, -255);
      delay(300);

      if (LINE == 0b10)
      {
        RUN(255, -255);
        delay(300);
      }
      else
      {
        RUN(-255, 255);
        delay(300);
      }

      RUN(255, 255);
      delay(50);
      continue;
    }

    if (FRONT)
    {
      if (FRONT == 0b111  )
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

      else RUN(255, 255);

      delay(50);
      continue;
    }


    if (left_prox)
    {
      status_update();
      curTime = millis();
      endTime = curTime + 3000;

      while (FRONT == 0)
      {
        RUN(-255, 255);
        status_update();

        curTime = millis();
        if (endTime < curTime) break;

      }
      RUN(255, 255);
      delay(50);
      continue;
    }

    if (right_prox)
    {
      status_update();
      curTime = millis();
      endTime = curTime + 3000;

      while (FRONT == 0)
      {
        RUN(255, -255);
        status_update();

        curTime = millis();
        if (endTime < curTime) break;

      }
      RUN(255, 255);
      delay(50);
      continue;
    }

    if ( dis <= 50 )
    {
      flip();
      RUN(255, 255);
      delay(50);
      continue;
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

    RUN(255, 255);
    delay(50);
    continue;
  }
}


