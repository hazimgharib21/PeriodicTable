int latchColPin = 22;
int clockColPin = 24;
int dataColPin = 23;

int latchRowPin = 53;
int clockRowPin = 51;
int dataRowPin = 52;

byte colData = 1;
byte rowData = 1;
int currentColLED = 0;
int currentRowLED = 0;

uint8_t outputPin[] = {
  latchColPin,
  clockColPin,
  dataColPin,
  latchRowPin,
  clockRowPin,
  dataRowPin
  };

void setup() {
  
  initOutput();
}

void loop() {
  // put your main code here, to run repeatedly:

  colData = 0;
  rowData = 0;
  
  currentColLED = random(8);
  currentRowLED = random(8);

  bitSet(colData, currentColLED);
  bitSet(rowData, currentRowLED);
  
  updateMatrix(colData, rowData);
  delay(5);
}

void initOutput(){

  for( uint8_t i = 0; i <= 5; i++){
    pinMode(outputPin[i], OUTPUT);
    digitalWrite(outputPin[i], LOW);
  }
}

void updateMatrix(byte columnData, byte rowsData){

  digitalWrite(latchColPin, LOW);
  shiftOut(dataColPin, clockColPin, LSBFIRST, columnData);
  digitalWrite(latchColPin, HIGH);

  digitalWrite(latchRowPin, LOW);
  shiftOut(dataRowPin, clockRowPin, LSBFIRST, rowsData);
  digitalWrite(latchRowPin, HIGH);
}

