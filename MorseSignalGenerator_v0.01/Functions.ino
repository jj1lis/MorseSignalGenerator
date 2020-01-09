int READ(){
  int return_reading = 0;
  int short_read = digitalRead(SHORT);
  int long_read = digitalRead(LONG);
  if(short_read == 0 && long_read == 1){
    return_reading = 1;
  }else if(short_read == 1 && long_read == 0){
    return_reading = 2;
  }else if(short_read == 0 && long_read == 0){
    return_reading = 3;
  }
  return return_reading;
}

int READ_LUNCHING(unsigned long times,int ratio,int read_lunching,int select_mode){
  while(millis() < times + DELAY_TIME * ratio){
    if(select_mode == 1){
      if(read_lunching == 0 || read_lunching == 1){
        read_lunching = READ();
      }else if(read_lunching == 2 || read_lunching == 3){
        read_lunching = 2;
      }
    }else if(select_mode == 2){
      if(read_lunching == 0 || read_lunching == 2){
        read_lunching = READ();
      }else if(read_lunching == 1 || read_lunching == 3){
        read_lunching = 1;
      }
    }
  }
  return read_lunching;
}

int SHORT_SHOT(){
  unsigned long times = millis();
  tone(SPEAKER,TONE);
  delay(DELAY_TIME*3/4);
  int read_lunching = READ_LUNCHING(times,1,read_lunching,1);
  times = millis();
  noTone(SPEAKER);
  read_lunching = READ_LUNCHING(times,1,read_lunching,1);
  return read_lunching;
}

int LONG_SHOT(){
  unsigned long times = millis();
  tone(SPEAKER,TONE);
  delay(DELAY_TIME*3/4);
  int read_lunching = READ_LUNCHING(times,3,read_lunching,2);
  times = millis();
  noTone(SPEAKER);
  read_lunching = READ_LUNCHING(times,1,read_lunching,2);
  return read_lunching;
}

int BLANK_INSERTION(int calling_times){
  if(calling_times == 0){
    unsigned long times = millis();
    int read_analisys = READ();
    while(millis() < times + DELAY_TIME * 3){
      if(read_analisys != 0){
        break;
      }
      read_analisys = READ();
    }
    if(read_analisys == 0){
      Serial.print(" ");
    }
  }
}
