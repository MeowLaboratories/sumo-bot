void TORNADO()
{
  int flag = 1;
  while(1)
  {
    status_update();

    if(LINE)
    {
      RUN(-255,-255);
      delay(200);
    }
    
    if(FRONT == 0b000 && flag == 1)
    {
      RUN(255,-255);
    }

    else if(FRONT == 0b000 && flag == -1)
    {
      RUN(-255,255);
    }

    else if(FRONT == 0b111  )
    {
      RUN(255,255);
    }

    else if(FRONT == 0b110  )
    {
      RUN(150,255);
      flag = -1;
    }

    else if( FRONT == 0b100  )
    {
      RUN(100,255);
      flag = -1;
    }

    else if(FRONT == 0b011)
    {
      RUN(255,150);
      flag = 1;
    }

    else if(FRONT == 0b001)
    {
      RUN(255,100);
      flag = 1;
    }

    else 
    {
      if(flag == 1) RUN(255,-255);
      else RUN(-255,255);
    }
    delay(50);
  }
}



