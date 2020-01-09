int CHAR_ANALISYS(unsigned int char_analisys){
  switch(char_analisys){
    case 1:
      Serial.print("E");
      break;
    case 2:
      Serial.print("T");
      break;
    case 11:
      Serial.print("I");
      break;
    case 21:
      Serial.print("A");
      break;
    case 12:
      Serial.print("N");
      break;
    case 22:
      Serial.print("M");
      break;
    case 111:
      Serial.print("S");
      break;
    case 211:
      Serial.print("U");
      break;
    case 121:
      Serial.print("R");
      break;
    case 221:
      Serial.print("W");
      break;
    case 112:
      Serial.print("D");
      break;
    case 212:
      Serial.print("K");
      break;
    case 122:
      Serial.print("G");
      break;
    case 222:
      Serial.print("O");
      break;
    case 1111:
      Serial.print("H");
      break;
    case 2111:
      Serial.print("V");
      break;
    case 1211:
      Serial.print("F");
      break;
    case 1121:
      Serial.print("L");
      break;
    case 1221:
      Serial.print("P");
      break;
    case 2221:
      Serial.print("J");
      break;
    case 1112:
      Serial.print("B");
      break;
    case 2112:
      Serial.print("X");
      break;
    case 1212:
      Serial.print("C");
      break;
    case 2212:
      Serial.print("Y");
      break;
    case 1122:
      Serial.print("Z");
      break;
    case 2122:
      Serial.print("Q");
      break;
    case 11111:
      Serial.print("5");
      break;
    case 21111:
      Serial.print("4");
      break;
    case 22111:
      Serial.print("3");
      break;
    case 22211:
      Serial.print("2");
      break;
    case 22221:
      Serial.print("1");
      break;
    case 11112:
      Serial.print("6");
      break;
    case 11122:
      Serial.print("7");
      break;
    case 11222:
      Serial.print("8");
      break;
    case 12222:
      Serial.print("9");
      break;
    case 22222:
      Serial.print("0");
      break;
    case 12112:
      Serial.print("/");
      break;
    case 112211:
      Serial.print("?");
      break;
    case 11111111:
      Serial.print("訂正符号");
      break;
    default:
      break;
  }
}
