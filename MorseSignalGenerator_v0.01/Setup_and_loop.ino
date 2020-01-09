void setup() {
  Serial.begin(9600);
  pinMode(SHORT,INPUT_PULLUP);
  pinMode(LONG,INPUT_PULLUP);
  pinMode(SPEAKER,OUTPUT);
}

void loop() {
  unsigned int char_analisys = 0;
  int char_figure_count = 1;
  static int calling_times = 0;
  int read_analisys = READ();
  do{
    if(read_analisys == 1){
      read_analisys = SHORT_SHOT();
      char_analisys += 1 * char_figure_count;
      char_figure_count *= 10;
      calling_times = 0;
    }
    if(read_analisys == 2){
      read_analisys = LONG_SHOT();
      char_analisys += 2 * char_figure_count;
      char_figure_count *= 10;
      calling_times = 0; 
    }
  }while(read_analisys != 0);
  CHAR_ANALISYS(char_analisys);
  BLANK_INSERTION(calling_times);
  calling_times = 1;
}
