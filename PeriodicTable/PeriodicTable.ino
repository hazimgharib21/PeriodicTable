
#define arraySize(x) ((sizeof(x))/(sizeof(x[0])))

#define debugMode false
#define serialMode false
#define baudrate 9600
#define pullUp true

uint8_t inputPin[] = {
  
};

uint8_t outputPin[] = {
  
};

void setup(){
  initSerial();
  initInput();
  initOutput();
}

void loop(){
  
}

void initSerial(){

  if ( debugMode || serialMode ){
    Serial.begin(baudrate);
    while(!Serial){}
    if ( serialMode ) Serial.print(F("<Arduino ready>\n"));
    if ( debugMode ) Serial.print(F("<DebugMode begin>\n"));
  }
}

void initInput(){

  for(uint8_t i = 0; i < arraySize(inputPin); i++){

    pinMode(inputPin[i], INPUT);
    digitalWrite(inputPin[i], pullUp);
  }
}

void initOutput(){

  for(uint8_t i = 0; i < arraySize(outputPin); i++){

    pinMode(outputPin[i], OUTPUT);
    digitalWrite(outputPin[i], LOW);
  }
}

