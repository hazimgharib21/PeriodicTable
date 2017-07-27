int latchPin = 22; // sh_cp
int clockPin = 24; // st_cp
int dataPin = 23; // ds

int latchInputPin = 53;
int clockInputPin = 51;
int dataInputPin = 52;
byte leds = 0;
int currentLED = 0;
bool ledState = true;
int led = 26;
int button = 25;
bool buttonState = false;

unsigned long previousMillis = 0;

const long interval = 500;
byte switchVar1 = 72;
void setup(){
  pinMode(latchPin, OUTPUT);
  pinMode(dataPin, OUTPUT);
  pinMode(clockPin, OUTPUT);
  pinMode(led, OUTPUT);
  pinMode(button, INPUT_PULLUP);
  pinMode(latchInputPin, OUTPUT);
  pinMode(clockInputPin, OUTPUT);
  pinMode(dataInputPin, OUTPUT);
  leds = 0;

  
}

void loop(){

  leds = 0;

  if(currentLED == 7){
    currentLED = 0;
  }else{
    currentLED++;
  }

  
  
  bitSet(leds, currentLED);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);

  digitalWrite(latchInputPin, LOW);
  shiftOut(dataInputPin, clockInputPin, LSBFIRST, leds);
  digitalWrite(latchInputPin, HIGH);

  delay(250);
/*
 
  
  buttonState = digitalRead(button);

  if(!buttonState){
    digitalWrite(led, HIGH);
  }else{
    digitalWrite(led, LOW);
  }
  
  unsigned long currentMillis = millis();

  if(currentMillis - previousMillis >= interval){
    previousMillis = currentMillis;

    ledBlink();
  }
  
  leds = 0;

  if(currentLED == 7){
    currentLED = 0;
  }else{
    currentLED++;
  }

  
  
  bitSet(leds, currentLED);

  digitalWrite(latchPin, LOW);
  shiftOut(dataPin, clockPin, LSBFIRST, leds);
  digitalWrite(latchPin, HIGH);

  delay(250);
  */
}

void ledBlink(){

  if(ledState){
    digitalWrite(led, HIGH);
    ledState = false;
  }else{
    digitalWrite(led, LOW);
    ledState = true;
  }

  
}


