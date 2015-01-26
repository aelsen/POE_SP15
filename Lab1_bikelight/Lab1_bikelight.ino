
int button = 2;
volatile int switcher = 0;
boolean flash;
int flashtime = 50;
int bouncetime = 100;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  attachInterrupt(0, switcherf, RISING);
}

void switcherf() {
  switcher++;
  switcher = switcher % 4;
  delay(500);
  Serial.println("case: ");
  Serial.println(switcher);
}

void loop() {
switch (switcher){
  case 0:
    allOn();
    break;
  case 1:
    allOff();
    break;
  case 2:
    delay(flashtime);
    flash = !flash;
    allFlashing();
    break;
  case 3:
    allBounce();
    Serial.println("case 3 ");
    break;
  }
}

void allOn() {
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, HIGH);
  }
}

void allOff(){
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, LOW);
  }
}

void allFlashing(){
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, flash);
  }
}

void allBounce(){
  digitalWrite(9, LOW);
  digitalWrite(10, LOW);
  digitalWrite(11, LOW);
  digitalWrite(12, LOW);
  digitalWrite(13, LOW);
  for(int p = 0; true; p++ ){
    int pmod = p % 8;
    if (pmod>4){
      pmod = 8 - pmod;}
    pmod = 9 + pmod;
    digitalWrite(pmod, HIGH);
    delay(bouncetime);
    digitalWrite(pmod, LOW);
  }
}
