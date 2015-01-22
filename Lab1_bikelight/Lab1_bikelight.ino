
int button = 2;
boolean flash;

void setup() {
  Serial.begin(9600);
  pinMode(13, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(l1, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(button, INPUT);
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
