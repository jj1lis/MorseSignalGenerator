#include <definition.ino>
#include <function.ino>

void setup() {
    Serial.begin(9600);
    pinMode(DOT,INPUT_PULLUP);
    pinMode(DASH,INPUT_PULLUP);
    pinMode(SPEAKER,OUTPUT);
}

void loop() {
    unsigned int char_analisys = 0;
    int char_figure_count = 1;
    static int calling_times = 0;
    InputType read_analisys = readKey();
    do{
        if(read_analisys == InputType.dot){
            read_analisys = shotDot();
            char_analisys += char_figure_count;
            char_figure_count *= 10;
            calling_times = 0;
        }
        if(read_analisys == InputType.dash){
            read_analisys = shotDash();
            char_analisys += 2 * char_figure_count;
            char_figure_count *= 10;
            calling_times = 0; 
        }
    }while(read_analisys != InputType.none);
    Serial.print(analyzeChar(char_analisys));
    insertBlank(calling_times);
    calling_times = 1;
}
