/**
Principles of Engineering
Spring 2015
Lab 1 - Brake Light
Antonia Elsen, Jessica Oehrlein, William Saulnier

A small arduino script that will control 5 LEDs, making them flash
in four different patterns -- all on, all off, all flashing, or all
bouncing. The speed of the bouncing is controlled by the rotation
of a 10k potentiometer.
**/

boolean flash;
int button = 2;
int bouncet = 0;
int flash_interval = 50;
volatile int mode = 0;
unsigned long last_inter = 0;


void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  attachInterrupt(0, modef, RISING);
}

/**
  Interrupt function that switches between the four modes of
  LED flashing on button press.
**/
void modef() {
  //Debounce the button. Ignore any interrupts after the first
    //for 200ms after the first interrupt
  unsigned long first_inter = millis();
  if (first_inter - last_inter > 200){
    mode++;
    mode = mode % 4;
  }
  last_inter = first_inter;
}

/**

**/
void loop() {
  switch (mode){
    case 0:
      allOn();
      break;
    case 1:
      allOff();
      break;
    case 2:
      delay(flash_interval);
      flash = !flash;
      allFlashing();
      break;
    case 3:
      allBouncing();
      break;
    }
}

/**
  Turns all LEDs on.
**/
void allOn() {
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, HIGH);
  }
}

/**
  Turns all LEDs off.
**/
void allOff(){
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, LOW);
  }
}

/**
  Flashes the LEDs on or off, depending on their previous state.

  Did you really need me to comment these?
**/
void allFlashing(){
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, flash);
  }
}

/**
  Switches one LED on at a time to create a bouncing pattern.
  The rate at which the LEDs bounce (the delay) is determined from the voltage
  read from a voltage divider on analog pin 0.
**/
void allBouncing(){
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);


  int pmod = bouncet % 8;
  if (pmod>4){
    pmod = 8 - pmod;}
  pmod = 9 + pmod;
  bouncet++;

  digitalWrite(pmod, HIGH);
  delay(analogRead(0));
  digitalWrite(pmod, LOW);
}
