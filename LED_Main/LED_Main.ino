#define arraySize(x) ( (sizeof (x) ) / ( sizeof ( x[0] )))

int latchPin1 = 51;
int clockPin1 = 49;
int dataPin1 = 53;

int latchPin2 = 50;
int clockPin2 = 48;
int dataPin2 = 52;

int latchPin3 = 36;
int clockPin3 = 38;
int dataPin3 = 40;

int latchPin4 = 32;
int clockPin4 = 30;
int dataPin4 = 34;

int latchPin6 = 39;
int clockPin6 = 37;
int dataPin6 = 41;

int latchPin7 = 33;
int clockPin7 = 31;
int dataPin7 = 35;

int latchPin5 = 27;
int clockPin5 = 25;
int dataPin5 = 29;

int latchPin8 = 26;
int clockPin8 = 24;
int dataPin8 = 28;

int outputPin[] = {
  
  latchPin1,
  clockPin1,
  dataPin1,
  latchPin2,
  clockPin2,
  dataPin2,
  latchPin3,
  clockPin3,
  dataPin3,
  latchPin4,
  clockPin4,
  dataPin4,
  latchPin5,
  clockPin5,
  dataPin5,
  latchPin6,
  clockPin6,
  dataPin6,
  latchPin7,
  clockPin7,
  dataPin7,
  latchPin8,
  clockPin8,
  dataPin8,
  
  
  };

int numOfRegisters = 2;
byte* registerState1;
byte* registerState2;
byte* registerState3;
byte* registerState4;
byte* registerState5;
byte* registerState6;
byte* registerState7;
byte* registerState8;

int bitToSet = 0;
int integerValue = 0;
boolean bitState;
boolean ledState = HIGH;
int index = 0;

unsigned long previousMillis = 0;
unsigned long previousLEDMillis = 0;
unsigned long previousLED = 0;
const long intervalAll = 10000;
const long intervalLED = 50;

void setup() {

  Serial.begin(9600);
  // put your setup code here, to run once:
  registerState1 = new byte[numOfRegisters];
  registerState2 = new byte[numOfRegisters];
  registerState3 = new byte[numOfRegisters];
  registerState4 = new byte[numOfRegisters];
  registerState5 = new byte[numOfRegisters];
  registerState6 = new byte[numOfRegisters];
  registerState7 = new byte[numOfRegisters];
  registerState8 = new byte[numOfRegisters];
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState1[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState2[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState3[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState4[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState5[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState6[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState7[i] = 0;
  }
  for(size_t i = 0; i < numOfRegisters; i++){
    registerState8[i] = 0;
  }

  for(int i = 0; i < (outputPin); i++){
    pinMode(outputPin[i], OUTPUT);
  }

  for(int i = 0; i < 120; i++){
    if(i < 16){
     
      regWrite1(i, LOW);
    }else if((i > 15) && (i < 32)){
   
      regWrite2(i - 16, LOW);
    }else if((i > 31) && (i < 48)){
   
      regWrite3(i - 32, LOW);
    }else if((i > 47) && (i < 64)){
     
      regWrite4(i - 48, LOW);
    }else if((i > 63) && (i < 80)){
   
      regWrite5(i - 64, LOW);
    }else if((i > 79) && (i < 96)){
  
      regWrite6(i - 80, LOW);
    }else if((i > 95) && (i < 112)){
    
      regWrite7(i - 96, LOW);
    }else if((i > 111)){
     
      regWrite8(i - 112, LOW);
    }
  }
}

void loop() {

  unsigned long currentMillis = millis();
  unsigned long currentLEDMillis = millis();

  if(Serial.available() > 0){

    previousMillis = currentMillis;
    index = 0;
    for(int i = 0; i < 120; i++){
    if(i < 16){
     
      regWrite1(i, LOW);
    }else if((i > 15) && (i < 32)){
   
      regWrite2(i - 16, LOW);
    }else if((i > 31) && (i < 48)){
   
      regWrite3(i - 32, LOW);
    }else if((i > 47) && (i < 64)){
     
      regWrite4(i - 48, LOW);
    }else if((i > 63) && (i < 80)){
   
      regWrite5(i - 64, LOW);
    }else if((i > 79) && (i < 96)){
  
      regWrite6(i - 80, LOW);
    }else if((i > 95) && (i < 112)){
    
      regWrite7(i - 96, LOW);
    }else if((i > 111)){
     
      regWrite8(i - 112, LOW);
    }
  }
    bitToSet = 0;
    integerValue = 0;
    integerValue = Serial.read();
    Serial.println(integerValue);

    if(integerValue % 2 == 0){
      bitState = HIGH;
      bitToSet = integerValue/2;
    }else{
      bitState = LOW;
      bitToSet = integerValue - 1;
      bitToSet = bitToSet / 2;
    }

    int i = bitToSet;

    if(i < 16){
      
      regWrite1(i, bitState);
    }else if((i > 15) && (i < 32)){
      
      regWrite2(i - 16, bitState);
    }else if((i > 31) && (i < 48)){
      
      regWrite3(i - 32, bitState);
      regWrite3(i - 32, bitState);
    }else if((i > 47) && (i < 64)){
      
      regWrite4(i - 48, bitState);
    }else if((i > 63) && (i < 80)){
      
      regWrite5(i - 64, bitState);
    }else if((i > 79) && (i < 96)){
      
      regWrite6(i - 80, bitState);
    }else if((i > 95) && (i < 112)){
      
      regWrite7(i - 96, bitState);
    }else if((i > 111)){
     
      regWrite8(i - 112, bitState);
    }
    
  }
    if(currentLEDMillis - previousLEDMillis >= intervalLED){
      Serial.println("lol");
      previousLEDMillis = currentLEDMillis;
      if(currentMillis - previousMillis >= intervalAll){
      Serial.println(index);
      

      if(index > 120){
        index = 0;
        ledState = !ledState;
      }else{
        index++;
      }

      if(index < 16){
      
      regWrite1(index, ledState);
    }else if((index > 15) && (index < 32)){
      
      regWrite2(index - 16, ledState);
    }else if((index > 31) && (index < 48)){
      
      regWrite3(index - 32, ledState);
    }else if((index > 47) && (index < 64)){
      
      regWrite4(index - 48, ledState);
    }else if((index > 63) && (index < 80)){
      
      regWrite5(index - 64, ledState);
    }else if((index > 79) && (index < 96)){
      
      regWrite6(index - 80, ledState);
    }else if((index > 95) && (index < 112)){
      
      regWrite7(index - 96, ledState);
    }else if((index > 111)){
     
      regWrite8(index - 112, ledState);
    }
      }
  }

  

/*
  for(int i = 0; i < 120; i++){
    Serial.print(i);
    Serial.print("\t");
    if(i < 16){
      Serial.println(i);
      regWrite1(i, HIGH);
    }else if((i > 15) && (i < 32)){
      Serial.println(i - 16);
      regWrite2(i - 16, HIGH);
    }else if((i > 31) && (i < 48)){
      Serial.println(i - 32);
      regWrite3(i - 32, HIGH);
    }else if((i > 47) && (i < 64)){
      Serial.println(i - 48);
      regWrite4(i - 48, HIGH);
    }else if((i > 63) && (i < 80)){
      Serial.println(i - 64);
      regWrite5(i - 64, HIGH);
    }else if((i > 79) && (i < 96)){
      Serial.println(i - 80);
      regWrite6(i - 80, HIGH);
    }else if((i > 95) && (i < 112)){
      Serial.println(i - 96);
      regWrite7(i - 96, HIGH);
    }else if((i > 111)){
      Serial.println(i-112);
      regWrite8(i - 112, HIGH);
    }


    delay(500);
    
  }
    */
  
}

void regWrite1(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);

  //Begin session
  digitalWrite(latchPin1, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState1[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin1, clockPin1, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin1, HIGH);
}

void regWrite2(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
 // Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin2, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState2[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin2, clockPin2, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin2, HIGH);
}
void regWrite3(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
 // Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin3, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState3[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin3, clockPin3, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin3, HIGH);
}

void regWrite4(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
 // Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin4, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState4[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin4, clockPin4, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin4, HIGH);
}

void regWrite5(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
 // Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin5, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState5[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin5, clockPin5, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin5, HIGH);
}

void regWrite6(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
 // Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin6, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState6[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin6, clockPin6, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin6, HIGH);
}

void regWrite7(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
  //Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin7, LOW);

  for (int i = 0; i < numOfRegisters; i++){
    //Get actual states for register
    byte* states = &registerState7[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin7, clockPin7, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin7, HIGH);
}

void regWrite8(int pin, bool state){
  //Determines register
  int reg = pin / 8;
  //Determines pin for actual register
  int actualPin = pin - (8 * reg);
  //Serial.println(actualPin);

  //Begin session
  digitalWrite(latchPin8, LOW);

  for (int i = 0; i < 1; i++){
    //Get actual states for register
    byte* states = &registerState8[i];

    //Update state
    if (i == reg){
      bitWrite(*states, actualPin, state);
    }

    //Write
    shiftOut(dataPin8, clockPin8, MSBFIRST, *states);
  }

  //End session
  digitalWrite(latchPin8, HIGH);
}


