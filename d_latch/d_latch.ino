int d[] = {2,5,6,7};
int latch = 3;
int andpin = 4;

// the setup routine runs once when you press reset:
void setup() {                
  // initialize the digital pin as an output.
  for(int i=0; i<4; i++){
    pinMode(d[i], OUTPUT);    
  } 
  pinMode(latch, OUTPUT);     
  pinMode(andpin, OUTPUT);
  
  digitalWrite(andpin, HIGH);
}

// the loop routine runs over and over again forever:
void loop() {
  
  for(int i=0; i<4; i++){
    digitalWrite(d[i], HIGH);
    digitalWrite(latch, HIGH);
    digitalWrite(latch,LOW);
    delay(500);
    digitalWrite(d[i], LOW);
    digitalWrite(latch, HIGH);
    digitalWrite(latch,LOW);
    delay(500);
  }
}
