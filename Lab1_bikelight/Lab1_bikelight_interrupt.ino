
int button = 2;
volatile int switcher = 0;
boolean flash;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  attachInterrupt(0, switcherf, RISING);
}

void switcherf() {
  switcher++;
  switcher = switcher % 4;
}

void loop() {
  
}

void allon() {
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, HIGH);
  }
}

void alloff(){
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, LOW);
  }
}

void allflashing(){
  for(int p = 9; p<14; p++ ){
    digitalWrite(p, flash);
  }
}

void allbounce(){
}
