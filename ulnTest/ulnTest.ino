int latchColPin = 53;
int clockColPin = 51;
int dataColPin = 52;
int latchRowPin = 22;
int clockRowPin = 24;
int dataRowPin = 23;
int ledPin = 50;

byte data = 0;
int currentLED = 0;

unsigned long previousMillis = 0;
const long interval = 25;
int ledState = LOW;

uint8_t outputPin[] = {
  
  latchColPin,
  clockColPin,
  dataColPin,
  latchRowPin,
  clockRowPin,
  dataColPin,
  };

void setup() {

  initOutput();

}

void loop() {

  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval){

    previousMillis = currentMillis;

    if(ledState == LOW){
      ledState = HIGH;
    }else{
      ledState = LOW;
    }

    digitalWrite(ledPin, ledState);
  }

  data = 0;

  if(currentLED == 7){
    currentLED = 0;
  }else{
    currentLED++;
  }

  bitSet(data, currentLED);

  digitalWrite(latchColPin, LOW);
  shiftOut(dataColPin, clockColPin, LSBFIRST, 255);
  digitalWrite(latchColPin, HIGH);

  digitalWrite(latchRowPin, LOW);
  shiftOut(dataRowPin, clockRowPin, LSBFIRST, 255);
  digitalWrite(latchRowPin, HIGH);

  delay(25);

}

void initOutput(){

  for( uint8_t i = 0; i <= sizeof(outputPin); i++){

    pinMode(outputPin[i], OUTPUT);
    digitalWrite(outputPin[i], LOW);
  }
}

