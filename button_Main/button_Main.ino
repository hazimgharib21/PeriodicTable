//**************************************************************//
//  Name    : Button_Main.ino                              //
//  Author  : HazimGharib                                       //                                           //
//  Notes   : Code for using a CD4021B Shift Register       //
//****************************************************************

//**************************************************************
//Define Constant
//**************************************************************

#define arraySize(x) ( (sizeof (x) ) / ( sizeof ( x[0] )))

#define debugMode false
#define serialMode true
#define baudrate 9600
#define pinEachRegister 8

//**************************************************************
//Define Pin
//**************************************************************

// Shift Register Pin

uint8_t latchPin1 = 52; //r
uint8_t dataPin1 = 50; // g
uint8_t clockPin1 = 48; //b
uint8_t latchPin2 = 53; //r
uint8_t dataPin2 = 51; // g
uint8_t clockPin2 = 49; //b
uint8_t latchPin3 = 46; //r
uint8_t dataPin3 = 44; // g
uint8_t clockPin3 = 42; //b
uint8_t latchPin4 = 47; //r
uint8_t dataPin4 = 45; // g
uint8_t clockPin4 = 43; //b
uint8_t latchPin5 = 35; //r
uint8_t dataPin5 = 33; // g
uint8_t clockPin5 = 31; //b
uint8_t latchPin6 = 41; //r
uint8_t dataPin6 = 39; // g
uint8_t clockPin6 = 37; //b

uint8_t inputPin[] = {
  
  dataPin1,
  dataPin2,
  dataPin3,
  dataPin4,
  dataPin5,
  dataPin6,
};

uint8_t outputPin[] = {

  latchPin1,
  clockPin1,
  latchPin2,
  clockPin2,
  latchPin3,
  clockPin3,
  latchPin4,
  clockPin4,
  latchPin5,
  clockPin5,
  latchPin6,
  clockPin6,
};

//**************************************************************
//Variables Declaration
//**************************************************************

// Define variables to hold the data for each shift register
byte switchVar1 = 72;
byte switchVar2 = 159;
byte switchVar3 = 246;
byte switchVar4 = 333;
byte switchVar5 = 72;
byte switchVar6 = 159;
byte switchVar7 = 72;
byte switchVar8 = 159;
byte switchVar9 = 72;
byte switchVar10 = 159;
byte switchVar11 = 72;
byte switchVar12 = 159;
byte switchVar13 = 72;
byte switchVar14 = 159;
byte switchVar15 = 246;


// Define array variables for debounce
int justPressed1[pinEachRegister] = {};
int justPressed2[pinEachRegister] = {};
int justPressed3[pinEachRegister] = {};
int justPressed4[pinEachRegister] = {};
int justPressed5[pinEachRegister] = {};
int justPressed6[pinEachRegister] = {};
int justPressed7[pinEachRegister] = {};
int justPressed8[pinEachRegister] = {};
int justPressed9[pinEachRegister] = {};
int justPressed10[pinEachRegister] = {};
int justPressed11[pinEachRegister] = {};
int justPressed12[pinEachRegister] = {};
int justPressed13[pinEachRegister] = {};
int justPressed14[pinEachRegister] = {};
int justPressed15[pinEachRegister] = {};
int pressed1[pinEachRegister] = {};
int pressed2[pinEachRegister] = {};
int pressed3[pinEachRegister] = {};
int pressed4[pinEachRegister] = {};
int pressed5[pinEachRegister] = {};
int pressed6[pinEachRegister] = {};
int pressed7[pinEachRegister] = {};
int pressed8[pinEachRegister] = {};
int pressed9[pinEachRegister] = {};
int pressed10[pinEachRegister] = {};
int pressed11[pinEachRegister] = {};
int pressed12[pinEachRegister] = {};
int pressed13[pinEachRegister] = {};
int pressed14[pinEachRegister] = {};
int pressed15[pinEachRegister] = {};

int toSend = 0;

void setup(){

  for(int i = 0; i < pinEachRegister; i++){

    pressed1[i] = 0;
    pressed2[i] = 0;
    pressed3[i] = 0;
    pressed4[i] = 0;
    pressed5[i] = 0;
    pressed6[i] = 0;
    pressed7[i] = 0;
    pressed8[i] = 0;
    pressed9[i] = 0;
    pressed10[i] = 0;
    pressed11[i] = 0;
    pressed12[i] = 0;
    pressed13[i] = 0;
    pressed14[i] = 0;
    pressed15[i] = 0;
  }
  initSerial();
  initInput();
  initOutput();
  
}

void loop(){

  updateInput();
  updateDebounce();
  serialSend();
}

void initSerial(){

  if ( debugMode || serialMode){

    Serial.begin(baudrate);
    while(!Serial){}
    if(serialMode) Serial.print(F("<Arduino ready>\n"));
    if(debugMode) Serial.print(F("<DebugMode begin>\n"));
  }
}

void initInput(){

  for(uint8_t i = 0; i < arraySize(inputPin); i++){

    pinMode(inputPin[i], INPUT);
  }
}

void initOutput(){

  for(uint8_t i = 0; i < arraySize(outputPin); i++){
    
    pinMode(outputPin[i], OUTPUT);
  }
}

void updateInput(){

  getFirstBoardData(latchPin1, dataPin1, clockPin1);
  getSecondBoardData(latchPin2, dataPin2, clockPin2);
  getThirdBoardData(latchPin3, dataPin3, clockPin3);
  getFourthBoardData(latchPin4, dataPin4, clockPin4);
  getFifthBoardData(latchPin5, dataPin5, clockPin5);
  getSixthBoardData(latchPin6, dataPin6, clockPin6);
  
}

void getFirstBoardData(uint8_t myLatchPin, uint8_t myDataPin, uint8_t myClockPin){

  digitalWrite(myLatchPin,1);
  delayMicroseconds(20);
  digitalWrite(myLatchPin,0);

  switchVar1 = shiftIn(myDataPin, myClockPin);
  switchVar2 = shiftIn(myDataPin, myClockPin);
  switchVar3 = shiftIn(myDataPin, myClockPin);
  switchVar4 = shiftIn(myDataPin, myClockPin);
/*
  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);
  Serial.println(switchVar3, BIN);
  Serial.println(switchVar4, BIN);

  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);
*/
}

void getSecondBoardData(uint8_t myLatchPin, uint8_t myDataPin, uint8_t myClockPin){

  digitalWrite(myLatchPin,1);
  delayMicroseconds(20);
  digitalWrite(myLatchPin,0);

  switchVar5 = shiftIn(myDataPin, myClockPin);
  switchVar6 = shiftIn(myDataPin, myClockPin);
 
/*
  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);
  Serial.println(switchVar3, BIN);
  Serial.println(switchVar4, BIN);

  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);
*/
}

void getThirdBoardData(uint8_t myLatchPin, uint8_t myDataPin, uint8_t myClockPin){

  digitalWrite(myLatchPin,1);
  delayMicroseconds(20);
  digitalWrite(myLatchPin,0);

  switchVar7 = shiftIn(myDataPin, myClockPin);
  switchVar8 = shiftIn(myDataPin, myClockPin);
 
/*
  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);
  Serial.println(switchVar3, BIN);
  Serial.println(switchVar4, BIN);

  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);
*/
}

void getFourthBoardData(uint8_t myLatchPin, uint8_t myDataPin, uint8_t myClockPin){

  digitalWrite(myLatchPin,1);
  delayMicroseconds(20);
  digitalWrite(myLatchPin,0);

  switchVar9 = shiftIn(myDataPin, myClockPin);
  switchVar10 = shiftIn(myDataPin, myClockPin);
 
/*
  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);
  Serial.println(switchVar3, BIN);
  Serial.println(switchVar4, BIN);

  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);
*/
}

void getFifthBoardData(uint8_t myLatchPin, uint8_t myDataPin, uint8_t myClockPin){

  digitalWrite(myLatchPin,1);
  delayMicroseconds(20);
  digitalWrite(myLatchPin,0);

  switchVar11 = shiftIn(myDataPin, myClockPin);
  switchVar12 = shiftIn(myDataPin, myClockPin);
 /*

  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);
  Serial.println(switchVar3, BIN);
  Serial.println(switchVar4, BIN);

  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);
*/
}

void getSixthBoardData(uint8_t myLatchPin, uint8_t myDataPin, uint8_t myClockPin){

  digitalWrite(myLatchPin,1);
  delayMicroseconds(20);
  digitalWrite(myLatchPin,0);

  switchVar13 = shiftIn(myDataPin, myClockPin);
  switchVar14 = shiftIn(myDataPin, myClockPin);
  switchVar15 = shiftIn(myDataPin, myClockPin);
 
/*
  Serial.println(switchVar1, BIN);
  Serial.println(switchVar2, BIN);
  Serial.println(switchVar3, BIN);
  Serial.println(switchVar4, BIN);

  //white space
  Serial.println("-------------------");
  //delay so all these print satements can keep up. 
  delay(500);
*/
}

byte shiftIn(int myDataPin, int myClockPin){

  int i;
  int temp = 0;
  int pinState;
  byte myDataIn = 0;

  pinMode(myClockPin, OUTPUT);
  pinMode(myDataPin, INPUT);

  for(i = 7; i >= 0; i--){

    digitalWrite(myClockPin, 0);
    delayMicroseconds(2);
    temp = digitalRead(myDataPin);
    if(temp){
      pinState = 1;

      myDataIn = myDataIn | (1 << i);
    }
    else {
      pinState = 0;
    }

    digitalWrite(myClockPin, 1);
  }

  return myDataIn;
}

void updateDebounce(){

  for(int i = 0; i < pinEachRegister; i++){
    justPressed1[i] = 0;
    justPressed2[i] = 0;
    justPressed3[i] = 0;
    justPressed4[i] = 0;
    justPressed5[i] = 0;
    justPressed6[i] = 0;
    justPressed7[i] = 0;
    justPressed8[i] = 0;
    justPressed9[i] = 0;
    justPressed10[i] = 0;
    justPressed11[i] = 0;
    justPressed12[i] = 0;
    justPressed13[i] = 0;
    justPressed14[i] = 0;
    justPressed15[i] = 0;
  }

  for(int i = 0; i < pinEachRegister; i++){

    if(switchVar1 & (1 << i)){
      justPressed1[i] = 1;
    }
    if(switchVar2 & (1 << i)){
      justPressed2[i] = 1;
    }
    if(switchVar3 & (1 << i)){
      justPressed3[i] = 1;
    }
    if(switchVar4 & (1 << i)){
      justPressed4[i] = 1;
    }
    if(switchVar5 & (1 << i)){
      justPressed5[i] = 1;
    }
    if(switchVar6 & (1 << i)){
      justPressed6[i] = 1;
    }
    if(switchVar7 & (1 << i)){
      justPressed7[i] = 1;
    }
    if(switchVar8 & (1 << i)){
      justPressed8[i] = 1;
    }
    if(switchVar9 & (1 << i)){
      justPressed9[i] = 1;
    }
    if(switchVar10 & (1 << i)){
      justPressed10[i] = 1;
    }
    if(switchVar11 & (1 << i)){
      justPressed11[i] = 1;
    }
    if(switchVar12 & (1 << i)){
      justPressed12[i] = 1;
    }
    if(switchVar13 & (1 << i)){
      justPressed13[i] = 1;
    }
    if(switchVar14 & (1 << i)){
      justPressed14[i] = 1;
    }
    if(switchVar15 & (1 << i)){
      justPressed15[i] = 1;
    }
  }
/*
  for(int i = 0; i < pinEachRegister; i++){
    Serial.print(justPressed1[i]);
  }
  Serial.println();
  for(int i = 0; i < pinEachRegister; i++){
    Serial.print(justPressed2[i]);
  }
  Serial.println();
  */
}

void serialSend(){

  for(int i = 0; i < pinEachRegister; i++){

    if((pressed1[i] == 0) && (justPressed1[i] == 1)){
      
      pressed1[i] = justPressed1[i];

      toSend = i * 2;
      Serial.write(toSend);
      //Serial.println(toSend);
    }
    
    if((pressed2[i] == 0) && (justPressed2[i] == 1)){
      pressed2[i] = justPressed2[i];

      toSend = i * 2;
      toSend = toSend + 16;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed3[i] == 0) && (justPressed3[i] == 1)){
      pressed3[i] = justPressed3[i];

      toSend = i * 2;
      toSend = toSend + 32;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed4[i] == 0) && (justPressed4[i] == 1)){
      pressed4[i] = justPressed4[i];

      toSend = i * 2;
      toSend = toSend + 48;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed5[i] == 0) && (justPressed5[i] == 1)){
      pressed5[i] = justPressed5[i];

      toSend = i * 2;
      toSend = toSend + 64;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed6[i] == 0) && (justPressed6[i] == 1)){
      pressed6[i] = justPressed6[i];

      toSend = i * 2;
      toSend = toSend + 80;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed7[i] == 0) && (justPressed7[i] == 1)){
      pressed7[i] = justPressed7[i];

      toSend = i * 2;
      toSend = toSend + 96;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed8[i] == 0) && (justPressed8[i] == 1)){
      pressed8[i] = justPressed8[i];

      toSend = i * 2;
      toSend = toSend + 112;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed9[i] == 0) && (justPressed9[i] == 1)){
      pressed9[i] = justPressed9[i];

      toSend = i * 2;
      toSend = toSend + 128;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed10[i] == 0) && (justPressed10[i] == 1)){
      pressed10[i] = justPressed10[i];

      toSend = i * 2;
      toSend = toSend + 144;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed11[i] == 0) && (justPressed11[i] == 1)){
      pressed11[i] = justPressed11[i];

      toSend = i * 2;
      toSend = toSend + 160;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed12[i] == 0) && (justPressed12[i] == 1)){
      pressed12[i] = justPressed12[i];

      toSend = i * 2;
      toSend = toSend + 176;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed13[i] == 0) && (justPressed13[i] == 1)){
      pressed13[i] = justPressed13[i];

      toSend = i * 2;
      toSend = toSend + 192;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed14[i] == 0) && (justPressed14[i] == 1)){
      pressed14[i] = justPressed14[i];

      toSend = i * 2;
      toSend = toSend + 208;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed15[i] == 0) && (justPressed15[i] == 1)){
      pressed15[i] = justPressed15[i];

      toSend = i * 2;
      toSend = toSend + 224;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed1[i] == 1) && (justPressed1[i] == 0)){
      pressed1[i] = justPressed1[i];

      toSend = 1 + (i * 2);
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed2[i] == 1) && (justPressed2[i] == 0)){
      pressed2[i] = justPressed2[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 16;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed3[i] == 1) && (justPressed3[i] == 0)){
      pressed3[i] = justPressed3[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 32;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed4[i] == 1) && (justPressed4[i] == 0)){
      pressed4[i] = justPressed4[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 48;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed5[i] == 1) && (justPressed5[i] == 0)){
      pressed5[i] = justPressed5[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 64;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed6[i] == 1) && (justPressed6[i] == 0)){
      pressed6[i] = justPressed6[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 80;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed7[i] == 1) && (justPressed7[i] == 0)){
      pressed7[i] = justPressed7[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 96;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed8[i] == 1) && (justPressed8[i] == 0)){
      pressed8[i] = justPressed8[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 112;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed9[i] == 1) && (justPressed9[i] == 0)){
      pressed9[i] = justPressed9[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 128;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed10[i] == 1) && (justPressed10[i] == 0)){
      pressed10[i] = justPressed10[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 144;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed11[i] == 1) && (justPressed11[i] == 0)){
      pressed11[i] = justPressed11[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 160;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed12[i] == 1) && (justPressed12[i] == 0)){
      pressed12[i] = justPressed12[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 176;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed13[i] == 1) && (justPressed13[i] == 0)){
      pressed13[i] = justPressed13[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 192;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed14[i] == 1) && (justPressed14[i] == 0)){
      pressed14[i] = justPressed14[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 208;
      Serial.write(toSend);
      //Serial.println(toSend);
    }

    if((pressed15[i] == 1) && (justPressed15[i] == 0)){
      pressed15[i] = justPressed15[i];

      toSend = 1 + (i * 2);
      toSend = toSend + 224;
      Serial.write(toSend);
      //Serial.println(toSend);
    }
  }
}

