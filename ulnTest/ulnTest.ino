int latchColPin = 53;
int clockColPin = 51;
int dataColPin = 52;
int ledPin = 10;
int ledPin2 = 11;

byte data = 0;
int currentLED = 0;

uint8_t outputPin[] = {
  
  latchColPin,
  clockColPin,
  dataColPin,
  ledPin,
  ledPin2,
  };

void setup() {

  initOutput();
  digitalWrite(ledPin, HIGH);
  digitalWrite(ledPin2, LOW);
}

void loop() {


  data = 0;

  currentLED = random(8);

  bitSet(data, currentLED);

  digitalWrite(latchColPin, LOW);
  shiftOut(dataColPin, clockColPin, LSBFIRST, data);
  digitalWrite(latchColPin, HIGH);

  delay(25);

}

void initOutput(){

  for( uint8_t i = 0; i <= sizeof(outputPin); i++){

    pinMode(outputPin[i], OUTPUT);
    digitalWrite(outputPin[i], LOW);
  }
}

