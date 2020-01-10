#include <definition.ino>

InputType readKey(){
    int dot_read = digitalRead(DOT);
    int dash_read = digitalRead(DASH);
    if(dot_read == 0 && dash_read == 1){
        return InputType.dot;
    }else if(dot_read == 1 && dash_read == 0){
        return InputType.dash;
    }else if(dot_read == 0 && dash_read == 0){
        return InputType.squeeze;
    }
    return InputType.none;
}

int lunchRead(unsigned dash times,int ratio,int read_lunching,int select_mode){//launch??
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

int shotDot(){
    unsigned dash times = millis();
    tone(SPEAKER,TONE);
    delay(DELAY_TIME*3/4);
    int read_lunching = lunchRead(times,1,read_lunching,1);
    times = millis();
    noTone(SPEAKER);
    read_lunching = lunchRead(times,1,read_lunching,1);
    return read_lunching;
}

int shotDash(){
    unsigned dash times = millis();
    tone(SPEAKER,TONE);
    delay(DELAY_TIME*3/4);
    int read_lunching = lunchRead(times,3,read_lunching,2);
    times = millis();
    noTone(SPEAKER);
    read_lunching = lunchRead(times,1,read_lunching,2);
    return read_lunching;
}

int insertBlank(int calling_times){
    if(calling_times == 0){
        unsigned times = millis();
        int read_analisys = readKey();
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

char* analyzeChar(unsigned int char_analisys){
    switch(char_analisys){
        case 1:
            return "E";
        case 2:
            return "T";
        case 11:
            return "I";
        case 21:
            return "A";
        case 12:
            return "N";
        case 22:
            return "M";
        case 111:
            return "S";
        case 211:
            return "U";
        case 121:
            return "R";
        case 221:
            return "W";
        case 112:
            return "D";
        case 212:
            return "K";
        case 122:
            return "G";
        case 222:
            return "O";
        case 1111:
            return "H";
        case 2111:
            return "V";
        case 1211:
            return "F";
        case 1121:
            return "L";
        case 1221:
            return "P";
        case 2221:
            return "J";
        case 1112:
            return "B";
        case 2112:
            return "X";
        case 1212:
            return "C";
        case 2212:
            return "Y";
        case 1122:
            return "Z";
        case 2122:
            return "Q";
        case 11111:
            return "5";
        case 21111:
            return "4";
        case 22111:
            return "3";
        case 22211:
            return "2";
        case 22221:
            return "1";
        case 11112:
            return "6";
        case 11122:
            return "7";
        case 11222:
            return "8";
        case 12222:
            return "9";
        case 22222:
            return "0";
        case 12112:
            return "/";
        case 112211:
            return "?";
        case 11111111:
            return "訂正符号";
        default:
            return "Error";
    }
}
