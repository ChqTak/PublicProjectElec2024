//回転数
const int revolutions = 5;
//最速
const int slowMicros   = 2900;
//一回転に必要なステップ
const int stepsPerRevolution = 50;
const int totalSteps = stepsPerRevolution*revolutions;

int APHASE = 4;
int AENBL  = 5;
int BPHASE = 6;
int BENBL  = 7;

void setup(){
  pinMode(APHASE,OUTPUT);
  pinMode(AENBL ,OUTPUT);
  pinMode(BPHASE,OUTPUT);
  pinMode(BENBL ,OUTPUT);
  digitalWrite(AENBL,HIGH);
  digitalWrite(BENBL,HIGH);
}

int step = 0;

void loop(){
  int currentDelay = slowMicros;
  for(; step < totalSteps; step++){
    rotateMotor(currentDelay);
    currentDelay = currentDelay + 100;
  }

  close();
}

void DELAY_WAIT(int delay){
  delayMicroseconds(delay);
}

void rotateMotor(int delay){
  digitalWrite(APHASE,HIGH);
  DELAY_WAIT(delay);
  digitalWrite(BPHASE,HIGH);
  DELAY_WAIT(delay);
  digitalWrite(APHASE,LOW);
  DELAY_WAIT(delay);
  digitalWrite(BPHASE,LOW);
  DELAY_WAIT(delay);
}

void close() {
  digitalWrite(AENBL,LOW);
  digitalWrite(BENBL,LOW);
  digitalWrite(APHASE,LOW);
  digitalWrite(BPHASE,LOW);

  pinMode(APHASE,INPUT);
  pinMode(AENBL ,INPUT);
  pinMode(BPHASE,INPUT);
  pinMode(BENBL ,INPUT);

}


//http://sourceforge.net/p/dfu-util/tickets/